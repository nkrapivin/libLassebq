#include "GMLua.h"
#ifdef DITTO_WIN_STEAM
#include "TheSwordsOfDitto.h"
#else
#include "KatanaZero.h"
#endif
#include "Utils.h"
#include "Dangerous.h"

std::vector<std::string> Lscripts{ };
lua_State* lS = nullptr;
bool g_AddCollisionEvents = false;
bool g_ThrowErrors = true;
bool g_NoConsole = false;
bool g_IgnoreArgc = false;
bool g_AddScripts = false;
bool g_EnableBeforeEvents = false;
bool g_CareAboutGMLuaObjects = false;

/*
 *  Why:
 *  Builtin array variables are not actually GML arrays,
 *  The getter function allows you to specify an array index as a parameter.
 *  Even if you do `var a = variable_instance_get(id, "alarm");`
 *  It will just execute the getter with array index ARRAY_INDEX_NO_INDEX (INT_MIN)
 *  So it will simply return alarm[0], which is -1 most of the time.
 *
 *  What:
 *  Here we have a list of all builtins which I believe are arrays (TODO: double-check in GHIDRA)
 *  At launch, we verify the variable's name against this list
 *  If it matches, we save it's varId into a second list.
 *  Then, in GMLua_getvar GMLua_setvar they check if you're trying to access a builtin array
 *  If you do, they will get the length of that array (third hardcoded list)
 *  And create a GML array (if you're getting) or a Lua table (if you're setting)
 *
 *  Keep in mind that in Lua arrays start at one, so the first alarm in Lua will be _pSelf.alarm[1]
 *  Same for view_camera for example, first view's camera is at _pGlobal.view_camera[1]
 *  This is horrible and I can't change this even though I really want to. :(
 *
 *  Meow:
 *  Yes.
 */
const char* const g_BuiltinArrayNames[] = {
	"alarm",
	"view_visible",
	"view_xview",
	"view_yview",
	"view_wview",
	"view_hview",
	"view_xport",
	"view_yport",
	"view_wport",
	"view_hport",
	"view_angle",
	"view_hborder",
	"view_vborder",
	"view_hspeed",
	"view_vspeed",
	"view_object",
	"view_surface_id",
	"view_camera",
	"instance_id", // instance_count is the length.

	// not required in GMS 2:
	"background_visible",
	"background_foreground",
	"background_index",
	"background_x",
	"background_y",
	"background_width",
	"background_height",
	"background_htiled",
	"background_vtiled",
	"background_xscale",
	"background_yscale",
	"background_hspeed",
	"background_vspeed",
	"background_blend",
	"background_alpha"
};

// -1 means the length is NOT fixed.
const int g_BuiltinArrayLengths[] = {
	12, // alarm[12]
	8,  // view_visible[8]
	8,  // view_xview[8]
	8,  // view_yview[8]
	8,  // view_wview[8]
	8,  // view_hview[8]
	8,  // view_xport[8]
	8,  // view_yport[8]
	8,  // view_wport[8]
	8,  // view_hport[8]
	8,  // view_angle[8]
	8,  // view_hborder[8]
	8,  // view_vborder[8]
	8,  // view_hspeed[8]
	8,  // view_vspeed[8]
	8,  // view_object[8]
	8,  // view_surface_id[8]
	8,  // view_camera[8]
	-1, // instance_id[instance_count], variable length.

	//  not required in GMS 2:
	8,  // background_visible[8]
	8,  // background_foreground[8]
	8,  // background_index[8]
	8,  // background_x[8]
	8,  // background_y[8]
	8,  // background_width[8]
	8,  // background_height[8]
	8,  // background_htiled[8]
	8,  // background_vtiled[8]
	8,  // background_xscale[8]
	8,  // background_yscale[8]
	8,  // background_hspeed[8]
	8,  // background_vspeed[8]
	8,  // background_blend[8]
	8   // background_alpha[8]
};

int g_BuiltinArrayIDs[] = {
	-1, // alarm
	-1, // view_visible
	-1, // view_xview
	-1, // view_yview
	-1, // view_wview
	-1, // view_hview
	-1, // view_xport
	-1, // view_yport
	-1, // view_wport
	-1, // view_hport
	-1, // view_angle
	-1, // view_hborder
	-1, // view_vborder
	-1, // view_hspeed
	-1, // view_vspeed
	-1, // view_object
	-1, // view_surface_id
	-1, // view_camera
	-1, // instance_id

	// not required in GMS 2:
	-1, // background_visible
	-1, // background_foreground
	-1, // background_index
	-1, // background_x
	-1, // background_y
	-1, // background_width
	-1, // background_height
	-1, // background_htiled
	-1, // background_vtiled
	-1, // background_xscale
	-1, // background_yscale
	-1, // background_hspeed
	-1, // background_vspeed
	-1, // background_blend
	-1  // background_alpha
};

const int g_BuiltinArrayLen = sizeof(g_BuiltinArrayIDs) / sizeof(g_BuiltinArrayIDs[0]);
int g_InstanceCountVarid = -1;
int g_InstanceIdVarid = -1;

// a very quick function to get the instance count variable.
int getInstanceCount()
{
	RValue count(0.0); // returned value will be a double, let's prepare an RV.

	// this one doesn't need pSelf ^^
	g_BuiltinVars[g_InstanceCountVarid].f_getroutine(nullptr, ARRAY_INDEX_NO_INDEX, &count);
	return count.asInt32();
}

int findBuiltinArrayByName(const char* _name)
{
	for (int i = 0; i < g_BuiltinArrayLen; i++)
	{
		if (strcmp(g_BuiltinArrayNames[i], _name) == 0)
		{
			return i;
		}
	}

	return -1;
}

int isBuiltinArrayVariable(const RVariableRoutine& rvr)
{
	for (int i = 0; i < g_BuiltinArrayLen; i++)
	{
		if (strcmp(g_BuiltinArrayNames[i], rvr.f_name) == 0)
		{
			return i;
		}
	}

	return -1;
}

int findBuiltinArrayByVarid(const int varId)
{
	for (int i = 0; i < g_BuiltinArrayLen; i++)
	{
		if (g_BuiltinArrayIDs[i] == varId)
		{
			return i;
		}
	}

	return -1;
}

int lua_GMLua_ignoreArgc(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc < 1)
	{
		return luaL_error(_pL, __FUNCTION__ " error: Invalid argument count, expected at least 1, got %d.", Largc);
	}

	if (lua_isboolean(_pL, 1))
	{
		g_IgnoreArgc = lua_toboolean(_pL, 1) == 1 ? true : false;
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: Invalid argument type, expected boolean.");
	}

	return 0;
}

#if USE_DETOURS
static bool g_dbgmodedone = false;
static PVOID g_debug_mode_base = nullptr; // don't even need the proper type, we'll never need the base bruh.
static bool LLBQ_debug_mode_fake_true(CInstanceBase* lol, int who_cares, RValue* result)
{
	result->~RValue(); // free whatever was in there.
	result->kind = VALUE_BOOL;
	result->val = 1.0; // VALUE_BOOL is actually a double.
	return true;
}
#endif

int lua_GMLua_detour_debug_mode_var(lua_State* _pL)
{
#if USE_DETOURS
#define DTR_PRINT(_F) std::cout << (_F) << " = " << err << std::endl
	if (!g_dbgmodedone)
	{
		g_dbgmodedone = true;

		for (int i = 0; i < g_BuiltinVariablesSize; i++)
		{
			if (strcmp("debug_mode", g_BuiltinVars[i].f_name) == 0)
			{
				std::cout << "Detouring debug_mode, sit tight..." << std::endl;
				g_debug_mode_base = g_BuiltinVars[i].f_getroutine;
				LONG err = 0; // detours error code.
				err = DetourTransactionBegin();
				DTR_PRINT("DetourTransactionBegin()");
				err = DetourUpdateThread(GetCurrentThread());
				DTR_PRINT("DetourUpdateThread(GetCurrentThread())");
				err = DetourAttach(&g_debug_mode_base, LLBQ_debug_mode_fake_true);
				DTR_PRINT("DetourAttach(&g_debug_mode_base, LLBQ_debug_mode_fake_true)");
				err = DetourTransactionCommit();
				DTR_PRINT("DetourTransactionCommit()");
			}
		}
	}
#endif

	return 0;
}

bool isInvalidConstant(const char* n)
{
	return
	(
		strcmp(n, "self") == 0
		||
		strcmp(n, "local") == 0
	);
}

void RegisterRConstants(lua_State* _pL)
{
	std::cout << "Adding constants to Lua... ";

	for (int i = 0; i < *g_ConstNumb; i++)
	{
		const char* const constName = (*g_ConstNames)[i];
		if (isInvalidConstant(constName)) continue;

		const RValue& val = (*g_ConstValues)[i];
		if ((val.kind & MASK_KIND_RVALUE) != VALUE_REAL) abort();
		lua_pushnumber(_pL, val.val);
		lua_setglobal(_pL, constName);
	}

	lua_pushinteger(_pL, ARRAY_INDEX_NO_INDEX);
	lua_setglobal(_pL, "ARRAY_INDEX_NO_INDEX");

	std::cout << "Done!" << std::endl;
}

#define ASSET_PUSH() const char* const assetName = Result.pRefString->get();          \
	if (strcmp(assetName, "<undefined>") == 0) break;                                 \
	int _type = lua_getglobal(_pL, assetName);                                        \
	lua_pop(_pL, 1);                                                                  \
	if (_type == LUA_TNONE || _type == LUA_TNIL) {                                    \
		lua_pushinteger(_pL, i);                                                      \
		lua_setglobal(_pL, Result.pRefString->get());                                 \
	}

void RegisterAssets(lua_State* _pL)
{
	std::cout << "Adding asset names to Lua... ";

	// Audiogroups.
	for (int i = 0; true; i++)
	{
		lassebq_callr("audio_group_name", { i });
		ASSET_PUSH();
	}

	// Sounds.
	for (int i = 0; true; i++)
	{
		lassebq_callr("audio_get_name", { i });
		ASSET_PUSH();
	}

	// Sprites.
	for (int i = 0; true; i++)
	{
		lassebq_callr("sprite_get_name", { i });
		ASSET_PUSH();
	}

	// Backgrounds.
	for (int i = 0; true; i++)
	{
		lassebq_callr("background_get_name", { i });
		ASSET_PUSH();
	}

	// Paths.
	for (int i = 0; true; i++)
	{
		lassebq_callr("path_get_name", { i });
		ASSET_PUSH();
	}

	// Scripts.
	for (int i = 0; true; i++)
	{
		lassebq_callr("script_get_name", { i });
		ASSET_PUSH();
	}

	// Shaders.
	for (int i = 0; i < EtoI(GameShaders::__sizeof); i++)
	{
		lassebq_callr("shader_get_name", { i });
		ASSET_PUSH();
	}

	// Fonts.
	for (int i = 0; true; i++)
	{
		lassebq_callr("font_get_name", { i });
		ASSET_PUSH();
	}

	// Timelines.
	for (int i = 0; true; i++)
	{
		lassebq_callr("timeline_get_name", { i });
		ASSET_PUSH();
	}

	// Objects.
	for (int i = 0; true; i++)
	{
		lassebq_callr("object_get_name", { i });
		ASSET_PUSH();

		// Add collision events to the map.
		if (g_AddCollisionEvents)
		{
			mapOfEvents[makeevkey(static_cast<unsigned long long>(ev_collision), i)] = "Collision_" + Result.asString();
		}
	}

	// Rooms.
	for (int i = 0; true; i++)
	{
		lassebq_callr("room_get_name", { i });
		ASSET_PUSH();
	}

	std::cout << "Done!" << std::endl;
}

void InitGMLuaScripts(void)
{
	std::ifstream list("loadlist.txt");

	std::string line;
	while (std::getline(list, line))
	{
		std::cout << "Adding script " << line << std::endl;
		Lscripts.push_back(line);
	}
	list.close();
}

void InitGMLuaConfig(void)
{
	bool wait = false;
	std::ifstream cfg("GMLuaConfig.txt"); // the config file is just a bunch of lines for now, too lazy to parse INI.
	std::string line;
	while (std::getline(cfg, line))
	{
		if (line == "noConsole")
		{
			g_NoConsole = true;
		}
		else if (line == "addCollisionEvents")
		{
			g_AddCollisionEvents = true;
		}
		else if (line == "addScripts")
		{
			g_AddScripts = true;
		}
		else if (line == "ignoreLuaErrors")
		{
			g_ThrowErrors = false;
		}
		else if (line == "waitForDebugger")
		{
			wait = true;
		}
		else if (line == "enableBeforeEvents")
		{
			g_EnableBeforeEvents = true;
		}
		else if (line == "iWannaMakeMyOwnObjectsKthx")
		{
			g_CareAboutGMLuaObjects = true;
		}
	}
	cfg.close();

	// wait after we load the config.
	if (wait) WaitForDebugger();
}

int lua_GMLua_getcallbacks(lua_State* _pL)
{
	const std::string p1(std::to_string(reinterpret_cast<uintptr_t>(llbq_p1)));
	const std::string p2(std::to_string(reinterpret_cast<uintptr_t>(llbq_p2)));
	const std::string p3(std::to_string(reinterpret_cast<uintptr_t>(llbq_p3)));
	const std::string p4(std::to_string(reinterpret_cast<uintptr_t>(llbq_p4)));

	lua_createtable(_pL, 4, 0);

	lua_pushstring(_pL, p1.c_str());
	lua_rawseti(_pL, -2, 1);
	lua_pushstring(_pL, p2.c_str());
	lua_rawseti(_pL, -2, 2);
	lua_pushstring(_pL, p3.c_str());
	lua_rawseti(_pL, -2, 3);
	lua_pushstring(_pL, p4.c_str());
	lua_rawseti(_pL, -2, 4);

	return 1;
}

RValue LtoR(lua_State* _pL, int a)
{
	switch (int _t = lua_type(_pL, a))
	{
	case LUA_TUSERDATA:
		{
			RValue** rV = reinterpret_cast<RValue**>(luaL_checkudata(_pL, a, "__libLassebq_GMLRVar_metatable"));
			if (rV != nullptr)
			{
				return **rV;
			}
			else
			{
				return luaL_error(_pL, __FUNCTION__ " error: wrong lua variable, expected userdata/GMLRVar. (stackInd=%d)", a);
			}
		}
	case LUA_TLIGHTUSERDATA:
		{
			const void* v = lua_topointer(_pL, a);
			return RValue(const_cast<void*>(v));
		}
	case LUA_TTABLE:
		{
			lua_len(_pL, a);
			lua_Unsigned arrLen = lua_tointeger(_pL, -1);
			lua_pop(_pL, 1);

			RValue arr(0.0); // will be filled.
			if (arrLen > 0)
			{
				for (lua_Unsigned i = arrLen - 1; i > -1; i--)
				{
					lua_pushinteger(_pL, i + 1);
					lua_gettable(_pL, a);
					(arr)(static_cast<int>(i)) = LtoR(_pL, -1);
					lua_pop(_pL, 1);
				}
				arr.pRefArray->refcount++; // dynamic arrays are evil.
			}
			return arr;
		}
	case LUA_TSTRING:
		{
			const char* v = lua_tostring(_pL, a);
			return RValue(v);
		}
	case LUA_TNUMBER:
		{
			double v = lua_tonumber(_pL, a);
			return RValue(v);
		}
	case LUA_TBOOLEAN:
		{
			bool v = (lua_toboolean(_pL, a) == 1) ? true : false;
			return RValue(v);
		}
	case LUA_TNIL:
		{
			return RValue(nullptr, true);
		}
	case LUA_TNONE:
		{
			return luaL_error(_pL, __FUNCTION__ " error: Cannot convert NONE to RValue.");
		}
	case LUA_TFUNCTION:
		{
			return luaL_error(_pL, __FUNCTION__ " error: Cannot convert FUNCTION to RValue, wake up, this isn't GMS 2.3!");
		}
	default:
		{
			return luaL_error(_pL, __FUNCTION__ " error: Cannot convert Lua variable to RValue, unknown type '%s'.", lua_typename(_pL, _t));
		}
	}
}

bool internal_getvarb(CInstanceBase* obj, int varind, int arrind, RValue& ret, lua_State* _pL)
{
	if (varind < 10000)
	{
		if (g_BuiltinVars[varind].f_getroutine == nullptr)
		{
			return luaL_error(_pL, __FUNCTION__ " error: Tried to set a write-only builtin variable! (varind=%d,arrind=%d,varname='%s')", varind, arrind, g_BuiltinVars[varind].f_name) ? false : false;
		}

		if (!g_BuiltinVars[varind].f_getroutine(obj, arrind, &ret))
		{
			return luaL_error(_pL, __FUNCTION__ " error: Failed to get a builtin variable! (varind=%d,arrind=%d,varname='%s')", varind, arrind, g_BuiltinVars[varind].f_name) ? false : false;
		}

		return true;
	}
	else
	{
		ret = obj->GetYYVarRef(varind - 100000);
		return true;
	}
}

bool internal_setvarb(CInstanceBase* obj, int varind, int arrind, RValue& val, lua_State* _pL)
{
	if (varind < 10000)
	{
		if (!g_BuiltinVars[varind].f_canset || g_BuiltinVars[varind].f_setroutine == nullptr)
		{
			return luaL_error(_pL, __FUNCTION__ " error: Tried to set a read-only builtin variable! (varind=%d,arrind=%d,varname='%s')", varind, arrind, g_BuiltinVars[varind].f_name) ? false : false;
		}
		
		if (!g_BuiltinVars[varind].f_setroutine(obj, arrind, &val))
		{
			return luaL_error(_pL, __FUNCTION__ " error: Failed to set a builtin variable! (varind=%d,arrind=%d,varname='%s')", varind, arrind, g_BuiltinVars[varind].f_name) ? false : false;
		}

		return true;
	}
	else
	{
		RValue& ref(obj->GetYYVarRef(varind - 100000));
		ref = val;
		return true;
	}
}

// inst,varTable
int lua_GMLua_getvar(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc < 2)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected at least 2, got %d.", Largc);
	}

	CInstanceBase* inst = nullptr;
	int varId = -1;
	bool isBuiltin = false;

	if (lua_isuserdata(_pL, 1))
	{
		CInstance** luaInst = reinterpret_cast<CInstance**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLInstance_metatable"));
		if (luaInst == nullptr)
		{
			return luaL_error(_pL, __FUNCTION__ " error: argument `inst` is not a valid GMLInstance.");
		}

		inst = *luaInst;
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `inst`, expected GMLInstance.");
	}

	if (lua_isuserdata(_pL, 2))
	{
		LasseVar* v = reinterpret_cast<LasseVar*>(luaL_checkudata(_pL, 2, "__libLassebq_GMLVar_metatable"));
		if (v == nullptr)
		{
			return luaL_error(_pL, __FUNCTION__ " error: argument `varid` is not a valid GMLVar.");
		}

		varId = v->index;
		isBuiltin = v->isbuiltin;
	}
	else if (lua_isnil(_pL, 2))
	{
		lua_pushnil(_pL);
		return 1;
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `varid`, expected GMLVar.");
	}

	if (isBuiltin)
	{
		int isArray = findBuiltinArrayByVarid(varId);
		if (isArray == -1)
		{
			RValue ret;
			internal_getvarb(inst, varId, ARRAY_INDEX_NO_INDEX, ret, _pL);
			return RValueToLua(_pL, ret);
		}
		else
		{
			LasseVarB* v = reinterpret_cast<LasseVarB*>(lua_newuserdata(_pL, sizeof(LasseVarB)));
			v->self = inst;
			v->varid = varId;
			luaL_getmetatable(_pL, "__libLassebq_GMLVarArray_metatable");
			lua_setmetatable(_pL, -2);
			return 1;
		}
	}
	else
	{
		const RValue& ref(inst->GetYYVarRef(varId));
		return RValueToLua(_pL, ref);
	}
}

// inst,varTable,value
int lua_GMLua_setvar(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc < 3)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected at least 3, got %d.", Largc);
	}

	CInstanceBase* inst = nullptr;
	int varId = -1;
	bool isBuiltin = false;

	if (lua_isuserdata(_pL, 1))
	{
		CInstance** luaInst = reinterpret_cast<CInstance**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLInstance_metatable"));
		if (luaInst == nullptr)
		{
			return luaL_error(_pL, __FUNCTION__ " error: argument `inst` is not a valid GMLInstance.");
		}

		//inst = reinterpret_cast<CInstanceBase*>(const_cast<void*>(lua_topointer(_pL, 1)));
		inst = *luaInst;
	}

	if (lua_isuserdata(_pL, 2))
	{
		LasseVar* v = reinterpret_cast<LasseVar*>(luaL_checkudata(_pL, 2, "__libLassebq_GMLVar_metatable"));
		if (v == nullptr)
		{
			return luaL_error(_pL, __FUNCTION__ " error: argument `varid` is not a valid GMLVar.");
		}

		varId = v->index;
		isBuiltin = v->isbuiltin;
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `varid`, expected lightuserdata.");
	}

	RValue varval(LtoR(_pL, 3)); // converts a Lua variable on the stack to an RValue.
	if (varval.kind == VALUE_UNSET)
	{
		return luaL_error(_pL, __FUNCTION__ " error: passed value is of type UNSET, expected anything else.");
	}

	if (isBuiltin)
	{
		int isArray = findBuiltinArrayByVarid(varId);
		if (isArray == -1)
		{
			internal_setvarb(inst, varId, ARRAY_INDEX_NO_INDEX, varval, _pL);
		}
		else
		{
			const auto* arr = varval.asArray();
			int aLen = arr->length;
			for (int i = 0; i < aLen; i++)
			{
				RValue vv(varval[i]);
				internal_setvarb(inst, varId, i, vv, _pL);
			}
		}

		return 0;
	}
	else
	{
		RValue& ref(inst->GetYYVarRef(static_cast<int>(varId)));
		ref = varval;
	}

	return 0;
}

const lua_Integer GM_global = -5l;
const lua_Integer GM_noone = -4l;
const lua_Integer GM_all = -3l;
const lua_Integer GM_other = -2l;
const lua_Integer GM_self = -1l;

int lua_GMLua_inst(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc < 1)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected 1, got %d.", Largc);
	}

	int type = lua_type(_pL, 1);
	if (type == LUA_TNUMBER)
	{
		lua_Integer id = lua_tointeger(_pL, 1); // if `v` is a number, it should convert that to an integer?
		switch (id)
		{
			// technically `noone` is a valid ""instance id"", so why not just return `nil` instead?
			case GM_noone: lua_pushnil(_pL); return 1;
			// lol no, make your own loop.
			case GM_all: return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be `all`.");

			// why make a new object when you can reuse what llbq gives you?
			case GM_self: return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be `self`, use _pSelf.");
			case GM_other: return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be `other`, use _pOther.");

			// just return _pGlobal.
			case GM_global: lua_getglobal(_pL, "_pGlobal"); return 1;
			default: break;
		}

		CInstance* inst = lass_find_CInstance_QUICK(static_cast<int>(id));
		if (inst == nullptr)
		{
			lua_pushnil(_pL);
		}
		else
		{
			CInstance** luaSelf = reinterpret_cast<CInstance**>(lua_newuserdata(lS, sizeof(CInstance*)));
			*luaSelf = inst;
			luaL_getmetatable(lS, "__libLassebq_GMLInstance_metatable");
			lua_setmetatable(lS, -2);
		}

		return 1;
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `id`, expected number, got %s.", lua_typename(_pL, type));
	}
}

int lua_GMLua_cclosure(lua_State* _pL) {
	lua_Integer funcIndex = lua_tointeger(_pL, lua_upvalueindex(1));
	lua_Integer funcArgc = lua_tointeger(_pL, lua_upvalueindex(2));
	return DoLuaGMLCall(_pL, static_cast<int>(funcIndex), static_cast<int>(funcArgc));
}

int lua_GMLua_script_cclosure(lua_State* _pL) {
	lua_Integer funcIndex = lua_tointeger(_pL, lua_upvalueindex(1));
	return DoLuaScriptCall(_pL, static_cast<int>(funcIndex));
}

int lua_DumpGMLVarids(lua_State* _pL)
{
	std::ofstream out("VARIDS.h", std::ofstream::trunc);

	out << "enum VARIABLE_IDS {" << std::endl;

	for (int i = 0; i < g_VariablesSize; i++)
	{
		const auto* yyvar = g_Variables[i];
		if (!yyvar) break;

		out << "    _varid_" << yyvar->pName << " = " << i;
		if (i < g_VariablesSize - 1) out << "," << std::endl;
		else out << std::endl;
	}

	out << "}";

	out.close();
	return 0;
}

void RegisterFunctions(lua_State* _pL)
{
	std::cout << "Registering functions... ";
	char funcName[128]{ '\0' };
	for (int i = 0; i < *g_RFunctionTableLen; i++)
	{
		const RFunction& rf = (*g_RFunctionTable)[i];
		memset(funcName, 0, sizeof(funcName));
		strcpy_s(funcName, sizeof(funcName), "GML_");
		if (strncat_s(funcName, sizeof(funcName), rf.f_name, sizeof(rf.f_name)) == EINVAL)
			abort();

		// skip invalid or weird functions such as @@NewGMLArray@@ or $PRINT.
		if (strchr(funcName, '@') != nullptr
		|| strchr(funcName, ' ') != nullptr
		|| strchr(funcName, '$') != nullptr) continue;

		lua_pushinteger(_pL, i);
		lua_pushinteger(_pL, rf.f_argnumb);
		lua_pushcclosure(_pL, lua_GMLua_cclosure, 2);
		lua_setglobal(_pL, funcName);
	}

	// Custom variable management functions.
	std::cout << "GMLua functions... ";
	lua_register(_pL, "GMLua_getvar", lua_GMLua_getvar);
	lua_register(_pL, "GMLua_setvar", lua_GMLua_setvar);
	lua_register(_pL, "GMLua_inst", lua_GMLua_inst);
	lua_register(_pL, "GMLua_ignoreArgc", lua_GMLua_ignoreArgc);
	lua_register(_pL, "GMLua_getcallbacks", lua_GMLua_getcallbacks);
	lua_register(_pL, "GMLua_dumpvarids", lua_DumpGMLVarids);
	lua_register(_pL, "GMLua_detour_debug_mode_var", lua_GMLua_detour_debug_mode_var);
	std::cout << "Done!" << std::endl;
}

void RegisterScripts(lua_State* _pL)
{
	std::cout << "Registering scripts...";
	for (int i = 0; i < g_GMLScriptsSize; i++)
	{
		const YYGMLFunc& func = g_GMLScripts[i];
		const std::string fname(func.pName);
		const std::string prefix("gml_Script_");
		if (fname.rfind(prefix) != std::string::npos)
		{
			const std::string luaName("GMLScript_" + fname.substr(prefix.length()));
			lua_pushinteger(_pL, i);
			lua_pushcclosure(_pL, lua_GMLua_script_cclosure, 1);
			lua_setglobal(_pL, luaName.c_str());
		}
	}
	std::cout << "Done!" << std::endl;
}

void LuaToRValue(lua_State* _pL, int a, RValueList& args)
{
	args.emplace_back(LtoR(_pL, a));
}

int RValueToLua(lua_State* _pL, const RValue& result)
{
	int mKind = result.kind & MASK_KIND_RVALUE;
	switch (mKind)
	{
		case VALUE_UNSET:
			//luaL_error(__FUNCTION__ " error: Tried to convert an UNSET")
			return 0;
		case VALUE_REAL:
			lua_pushnumber(_pL, result.val);
			return 1;
		case VALUE_BOOL:
			lua_pushboolean(_pL, result.val > 0.5);
			return 1;
		case VALUE_INT32:
			lua_pushinteger(_pL, result.v32);
			return 1;
		case VALUE_STRING:
			lua_pushstring(_pL, result.pRefString->get());
			return 1;
		case VALUE_PTR:
			lua_pushlightuserdata(_pL, result.ptr);
			return 1;
		case VALUE_INT64:
			lua_pushinteger(_pL, result.v64);
			return 1;
		case VALUE_ARRAY:
		{
			RValue** varArray = reinterpret_cast<RValue**>(lua_newuserdata(_pL, sizeof(RValue*)));

			if (result.pRefArray->refcount == 1)
			{
				// result is the only reference, it will likely be deallocated.
				*varArray = new RValue(result);
				(*varArray)->flags |= ERV_Owned; // this copy is managed by libLassebq.
			}
			else
			{
				// Take an address to the ref and increment refcount.
				//result.pRefArray->refcount++;
				*varArray = const_cast<RValue*>(&result);
			}

			luaL_getmetatable(_pL, "__libLassebq_GMLRVar_metatable");
			lua_setmetatable(_pL, -2);
			return 1;
		}
		case VALUE_UNDEFINED:
		case VALUE_JSNULL:
			lua_pushnil(_pL);
			return 1;
		default:
			return luaL_error(_pL, __FUNCTION__ " error: cannot convert RValue to Lua, unknown RValue type %d. (addr=%p)", mKind, &result);
	}
}

bool LuaChkArgs(const int gmargc, int luaargc, lua_State* _pL)
{
	if (g_IgnoreArgc) return true;

	if (gmargc != luaargc)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count for a GM call, expected %d, got %d.", gmargc, luaargc) ? false : false;
	}
	else
	{
		return true;
	}
}

// Example: return DoLuaGMLCall(L, 1234, 4);
int DoLuaGMLCall(lua_State* _pL, const int functionId, const int gmArgc)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (gmArgc > -1)
	{
		// static argument count, need to sanitize.
		if (LuaChkArgs(gmArgc, Largc, _pL) != true) return 0;
	}

	// Prepare arguments.
	RValueList list;
	for (int a = 0; a < Largc; a++)
	{
		LuaToRValue(_pL, 1 + a, list);
	}

	RValue result;
	CallRFunction(functionId, result, list);
	return RValueToLua(_pL, result);
}

int DoLuaScriptCall(lua_State* _pL, const int entryId)
{
	int Largc = lua_gettop(_pL); // get argument count.
	int i = 0;

	// prepare arguments
	RValueList args;
	for (int a = 0; a < Largc; a++)
	{
		LuaToRValue(_pL, 1 + a, args);
	}

	// call function
	RValue result;
	CallScriptFunction(entryId, result, args);
	return RValueToLua(_pL, result);
}

int lua_GMLVarArray_index(lua_State* _pL)
{
	LasseVarB* varidPtr = reinterpret_cast<LasseVarB*>(luaL_checkudata(_pL, 1, "__libLassebq_GMLVarArray_metatable"));
	lua_Integer key = lua_tointeger(_pL, 2);

	int ind = findBuiltinArrayByVarid(varidPtr->varid);
	int len = g_BuiltinArrayLengths[ind];
	if (len == -1)
	{
		if (varidPtr->varid != g_InstanceIdVarid)
		{
			return luaL_error(_pL, __FUNCTION__ " error: unable to get length for varid=%d", varidPtr->varid);
		}
		else
		{
			len = getInstanceCount();
		}
	}

	if (key > len || key < 1)
	{
		lua_pushnil(_pL);
		return 1;
	}

	key--; // arrays in GML start at 0.
	RValue ret;
	if (!internal_getvarb(varidPtr->self, varidPtr->varid, static_cast<int>(key), ret, _pL))
	{
		lua_pushnil(_pL);
		return 1;
	}
	else
	{
		return RValueToLua(_pL, ret);
	}
}

int lua_GMLVarArray_newindex(lua_State* _pL)
{
	LasseVarB* varidPtr = reinterpret_cast<LasseVarB*>(luaL_checkudata(_pL, 1, "__libLassebq_GMLVarArray_metatable"));
	lua_Integer key = lua_tointeger(_pL, 2);
	key--;

	if (!internal_setvarb(varidPtr->self, varidPtr->varid, static_cast<int>(key), LtoR(_pL, 3), _pL))
	{
		return luaL_error(_pL, __FUNCTION__ " error: failed to set builtin variable. (varid=%d,key=%d)", varidPtr->varid, static_cast<int>(key));
	}

	return 0;
}

int lua_GMLVarArray_len(lua_State* _pL)
{
	LasseVarB* varidPtr = reinterpret_cast<LasseVarB*>(luaL_checkudata(_pL, 1, "__libLassebq_GMLVarArray_metatable"));
	int ind = findBuiltinArrayByVarid(varidPtr->varid);
	int len = g_BuiltinArrayLengths[ind];
	if (len == -1)
	{
		if (varidPtr->varid != g_InstanceIdVarid)
		{
			return luaL_error(_pL, __FUNCTION__ " error: unable to get length for varid=%d", varidPtr->varid);
		}
		else
		{
			len = getInstanceCount();
		}
	}

	lua_pushinteger(_pL, len);
	return 1;
}

int lua_GMLVarArray_tostring(lua_State* _pL)
{
	LasseVarB* varidPtr = reinterpret_cast<LasseVarB*>(luaL_checkudata(_pL, 1, "__libLassebq_GMLVarArray_metatable"));

	int ind = findBuiltinArrayByVarid(varidPtr->varid);
	int len = g_BuiltinArrayLengths[ind];
	if (len == -1)
	{
		if (varidPtr->varid != g_InstanceIdVarid)
		{
			return luaL_error(_pL, __FUNCTION__ " error: unable to get length for varid=%d", varidPtr->varid);
		}
		else
		{
			len = getInstanceCount();
		}
	}

	char buf[128]{ '\0' };
	snprintf(buf, sizeof(buf), "GMLVarArray : name='%s',varid=%d,len=%d", g_BuiltinVars[varidPtr->varid].f_name, varidPtr->varid, len);
	lua_pushstring(_pL, buf);
	return 1;
}

int lua_GMLInstance_index(lua_State* _pL)
{
	// get function to call
	lua_getglobal(_pL, "GMLua_getvar");
	// make a copy of our userdata to be pushed to the stack.
	lua_pushvalue(_pL, 1);
	// GMLua_vars[name]
	lua_getglobal(_pL, "GMLua_vars");
	lua_pushvalue(_pL, 2);
	lua_gettable(_pL, -2);
	// pop GMLua_vars
	lua_remove(_pL, -2);
	// call with t,name,value
	lua_call(_pL, 2, 1);
	return 1;
}

int lua_GMLInstance_newindex(lua_State* _pL)
{
	CInstance** luaInst = reinterpret_cast<CInstance**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLInstance_metatable"));
	const char* name = lua_tostring(_pL, 2);

	// get function to call
	lua_getglobal(_pL, "GMLua_setvar");
	// make a copy of our userdata to be pushed to the stack.
	lua_pushvalue(_pL, 1);
	// GMLua_vars[name]
	lua_getglobal(_pL, "GMLua_vars");
	lua_pushvalue(_pL, 2);
	lua_gettable(_pL, -2);
	// check if need to realloc
	if (lua_isnil(_pL, -1))
	{
		lua_pop(_pL, 1); // don't need the nil.

		YYObjectBase* obj = reinterpret_cast<YYObjectBase*>(*luaInst);
		int ind = Code_Variable_FindAlloc_Slot_From_Name(obj, name);
		std::cout << "[INTERNAL DEBUG]: New variable allocated for: obj=" << obj << ",name=" << name << ",varid=" << ind << std::endl;

		// push new varslot.
		char buf[256]{ '\0' };
		if (strcat_s(buf, sizeof(buf), "GMLVar_") == EINVAL) abort();
		if (strcat_s(buf, sizeof(buf), name) == EINVAL) abort();

		// allocate new varslot
		LasseVar* v = reinterpret_cast<LasseVar*>(lua_newuserdata(_pL, sizeof(LasseVar)));
		v->index = ind;
		v->isbuiltin = false;

		// set it as GMLVar_[varname]
		luaL_getmetatable(_pL, "__libLassebq_GMLVar_metatable");
		lua_setmetatable(_pL, -2);
		lua_setglobal(_pL, buf);

		// set GMLua_vars[varname] = GMLVar_[varname]
		lua_getglobal(_pL, buf);
		int tt = lua_type(_pL, -2);
		//WaitForDebugger();
		lua_setfield(_pL, -2, name);
		lua_pop(_pL, 1);

		// repush our GMLVar to the stack.
		lua_getglobal(_pL, buf);
	}
	else
	{
		// pop GMLua_vars
		lua_remove(_pL, -2);
	}
	// push value
	lua_pushvalue(_pL, 3);
	// call with t,name,value
	lua_call(_pL, 3, 0);
	return 0;
}

int lua_GMLInstance_tostring(lua_State* _pL)
{
	CInstance** luaInst = reinterpret_cast<CInstance**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLInstance_metatable"));
	char buf[64]{ '\0' };
	int instid = -5; // global

	// get actual instance id if we're not a global CInstance.
	if (*luaInst != *g_pGlobal)
	{
		instid = (*luaInst)->i_id;
	}

	// push and return! ^^
	snprintf(buf, sizeof(buf), "GMLInstance : id=%d,addr=%p", instid, *luaInst);
	lua_pushstring(_pL, buf);
	return 1;
}

int lua_GMLInstance_len(lua_State* _pL)
{
	CInstance** luaInst = reinterpret_cast<CInstance**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLInstance_metatable"));
	lua_Integer value = (*luaInst)->m_yyvarsMap->m_numUsed;
	
	lua_pushinteger(_pL, value);
	return 1;
}

/*
int lua_GMLInstance_next(lua_State* _pL)
{
	CInstance** luaInst = reinterpret_cast<CInstance**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLInstance_metatable"));
	const char* key = lua_tostring(_pL, 2);

	lua_getglobal(_pL, "GMLua_vars");
	lua_pushvalue(_pL, 2);
	lua_gettable(_pL, -2);

	LasseVar* v = reinterpret_cast<LasseVar*>(luaL_checkudata(_pL, -1, "__libLassebq_GMLVar_metatable"));
	const auto* map = (*luaInst)->m_yyvarsMap;
	Hash h = map->CalculateHash(v->index);
	Hash ht = h;
	for (int pos = map->GetIdealPosition(h); pos < map->m_numUsed; pos++)
	{
		if (map->GetHashAt(pos) != ht)
		{

		}
		else
		{
			break;
		}
	}
}
*/

void RenewGlobal(lua_State* _pL)
{
	// global object may be relocated from time to time...
	// gotta renew it sometimes.

	CInstance** luaGlobal = reinterpret_cast<CInstance**>(lua_newuserdata(_pL, sizeof(CInstance*)));

	// this is wrong, will likely break stuff, but who cares.
	*luaGlobal = reinterpret_cast<CInstance*>(*g_pGlobal);

	luaL_getmetatable(_pL, "__libLassebq_GMLInstance_metatable");
	lua_setmetatable(_pL, -2);
	lua_setglobal(_pL, "_pGlobal");
}

int lua_GMLRVar_index(lua_State* _pL)
{
	RValue** rV = reinterpret_cast<RValue**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLRVar_metatable"));
	if ((*rV)->pRefArray == nullptr || !((*rV)->isArray()))
	{
		return luaL_error(_pL, __FUNCTION__ " error: variable at address %p is NOT an array, or it was freed. (type=%d)", *rV, ((*rV)->kind & MASK_KIND_RVALUE));
	}

	lua_Integer key = lua_tointeger(_pL, 2);
	const auto *arr = (*rV)->asArray();

	int len = 0;
	if (arr != nullptr)
	{
		len = arr->length;
	}

	if (key > len || key < 1 || arr == nullptr)
	{
		lua_pushnil(_pL);
		return 1;
	}

	key--;
	return RValueToLua(_pL, (*rV)->DoArrayIndex(static_cast<int>(key)));
}

int lua_GMLRVar_newindex(lua_State* _pL)
{
	RValue** rV = reinterpret_cast<RValue**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLRVar_metatable"));
	if ((*rV)->pRefArray == nullptr || !((*rV)->isArray()))
	{
		return luaL_error(_pL, __FUNCTION__ " error: variable at address %p is NOT an array, or it was freed. (type=%d)", *rV, ((*rV)->kind & MASK_KIND_RVALUE));
	}

	lua_Integer key = lua_tointeger(_pL, 2);
	key--;

	*(ARRAY_LVAL_RValue(*rV, static_cast<int>(key))) = LtoR(_pL, 3);
	return 0;
}

int lua_GMLRVar_len(lua_State* _pL)
{
	RValue** rV = reinterpret_cast<RValue**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLRVar_metatable"));
	if ((*rV)->pRefArray == nullptr || !((*rV)->isArray()))
	{
		return luaL_error(_pL, __FUNCTION__ " error: variable at address %p is NOT an array, or it was freed. (type=%d)", *rV, ((*rV)->kind & MASK_KIND_RVALUE));
	}

	const auto *arr = (*rV)->asArray();
	int len = 0;

	if (arr != nullptr)
	{
		len = arr->length;
	}

	lua_pushinteger(_pL, len);
	return 1;
}

int lua_GMLRVar_tostring(lua_State* _pL)
{
	RValue** rV = reinterpret_cast<RValue**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLRVar_metatable"));
	if ((*rV)->pRefArray == nullptr || !((*rV)->isArray()))
	{
		return luaL_error(_pL, __FUNCTION__ " error: variable at address %p is NOT an array, or it was freed. (type=%d)", *rV, ((*rV)->kind & MASK_KIND_RVALUE));
	}

	const auto *arr = (*rV)->asArray();
	int len = 0;
	if (arr != nullptr)
	{
		len = arr->length;
	}

	char buf[128]{ '\0' };
	snprintf(buf, sizeof(buf), "GMLRVar : addr=%p,len=%d", *rV, len);
	lua_pushstring(_pL, buf);
	return 1;
}

int lua_GMLRVar_gc(lua_State* _pL)
{
	RValue** rV = reinterpret_cast<RValue**>(luaL_checkudata(_pL, 1, "__libLassebq_GMLRVar_metatable"));

	if ((*rV)->isArray())
	{
		// deallocate our rv copy.
		if (((*rV)->flags & ERV_Owned) != 0)
		{
			delete *rV;
		}
		else
		{
			if ((*rV)->pRefArray != nullptr)
			{
				/*
				std::cout << "[INTERNAL DEBUG]: Decrementing reference count..." << std::endl;
				(*rV)->pRefArray->refcount--;
				if ((*rV)->pRefArray->refcount == 0)
				{
					std::cout << "[INTERNAL DEBUG]: Array reference count is 0, freeing..." << std::endl;
					//FREE_RValue__Pre(*rV);
				}
				*/
			}
		}
	}

	return 0;
}

int lua_GMLVar_tostring(lua_State* _pL)
{
	LasseVar* v = reinterpret_cast<LasseVar*>(luaL_checkudata(_pL, 1, "__libLassebq_GMLVar_metatable"));
	char buf[64]{ '\0' };
	snprintf(buf, sizeof(buf), "GMLVar : varid=%d,isbuiltin=%s", v->index, (v->isbuiltin ? "true" : "false"));
	lua_pushstring(_pL, buf);
	return 1;
}

int lua_GMLVar_index(lua_State* _pL)
{
	LasseVar* v = reinterpret_cast<LasseVar*>(luaL_checkudata(_pL, 1, "__libLassebq_GMLVar_metatable"));
	const char* k = lua_tostring(_pL, 2);
	if (strcmp("index", k) == 0)
	{
		lua_pushinteger(_pL, v->index);
	}
	else if (strcmp("isbuiltin", k) == 0)
	{
		lua_pushboolean(_pL, v->isbuiltin);
	}
	else
	{
		lua_pushnil(_pL);
	}

	return 1;
}

void RegisterMetatables(lua_State* _pL)
{
	luaL_newmetatable(_pL, "__libLassebq_GMLVar_metatable");
	const luaL_Reg f[] = {
		{ "__tostring", lua_GMLVar_tostring },
		{ "__index", lua_GMLVar_index },
		{ nullptr, nullptr }
	};
	luaL_setfuncs(_pL, f, 0);
	lua_pop(_pL, 1);

	luaL_newmetatable(_pL, "__libLassebq_GMLRVar_metatable");
	const luaL_Reg varfuncs[] = {
		{ "__index", lua_GMLRVar_index },
		{ "__newindex", lua_GMLRVar_newindex },
		{ "__len", lua_GMLRVar_len },
		{ "__tostring", lua_GMLRVar_tostring },
		{ "__gc", lua_GMLRVar_gc },
		{ nullptr, nullptr }
	};
	luaL_setfuncs(_pL, varfuncs, 0);
	lua_pop(_pL, 1);

	// cool and good methods.
	luaL_newmetatable(_pL, "__libLassebq_GMLInstance_metatable");
	const luaL_Reg instfuncs[] = {
		{ "__index", lua_GMLInstance_index },
		{ "__newindex", lua_GMLInstance_newindex },
		{ "__len", lua_GMLInstance_len },
		{ "__tostring", lua_GMLInstance_tostring },
		{ nullptr, nullptr }
	};
	luaL_setfuncs(_pL, instfuncs, 0);
	lua_pop(_pL, 1);

	luaL_newmetatable(_pL, "__libLassebq_GMLVarArray_metatable");
	const luaL_Reg funcs[] = {
		{ "__index", lua_GMLVarArray_index },
		{ "__newindex", lua_GMLVarArray_newindex },
		{ "__len", lua_GMLVarArray_len },
		{ "__tostring", lua_GMLVarArray_tostring },
		{ nullptr, nullptr }
	};
	luaL_setfuncs(_pL, funcs, 0);
	lua_pop(_pL, 1);
}

void RegisterVarids(lua_State* _pL)
{
	char buf[256]{ '\0' };

	// lookup table
	lua_createtable(_pL, g_TotalVarSize, 0); // not *quite* the size, an approximation.
	lua_setglobal(_pL, "GMLua_vars");

	// custom vars
	for (int i = 0; i < g_VariablesSize; i++)
	{
		memset(buf, 0, sizeof(buf));
		if (strcat_s(buf, sizeof(buf), "GMLVar_") == EINVAL) abort();
		if (strcat_s(buf, sizeof(buf), g_Variables[i]->pName) == EINVAL) abort();

		LasseVar* v = reinterpret_cast<LasseVar*>(lua_newuserdata(_pL, sizeof(LasseVar)));
		v->index = i;
		v->isbuiltin = false;

		luaL_getmetatable(_pL, "__libLassebq_GMLVar_metatable");
		lua_setmetatable(_pL, -2);
		lua_setglobal(_pL, buf);

		lua_getglobal(_pL, "GMLua_vars");
		lua_getglobal(_pL, buf);
		lua_setfield(_pL, -2, g_Variables[i]->pName);
		lua_setglobal(_pL, "GMLua_vars");
	}

	// builtin vars.
	for (int i = 0; i < g_BuiltinVariablesSize; i++)
	{
		memset(buf, 0, sizeof(buf));
		if (strcat_s(buf, sizeof(buf), "GMLVar_") == EINVAL) abort();
		if (strcat_s(buf, sizeof(buf), g_BuiltinVars[i].f_name) == EINVAL) abort();

		int ba = isBuiltinArrayVariable(g_BuiltinVars[i]);
		if (ba != -1)
		{
			std::cout << "Registered builtin array variable " << g_BuiltinVars[i].f_name << std::endl;
			g_BuiltinArrayIDs[ba] = i;
		}

		if (strcmp("instance_count", g_BuiltinVars[i].f_name) == 0)
		{
			std::cout << "Found instance_count variable." << std::endl;
			g_InstanceCountVarid = i;
		}

		if (strcmp("instance_id", g_BuiltinVars[i].f_name) == 0)
		{
			std::cout << "Found instance_id variable." << std::endl;
			g_InstanceIdVarid = i;
		}

		LasseVar* v = reinterpret_cast<LasseVar*>(lua_newuserdata(_pL, sizeof(LasseVar)));
		v->index = i;
		v->isbuiltin = true;

		luaL_getmetatable(_pL, "__libLassebq_GMLVar_metatable");
		lua_setmetatable(_pL, -2);
		lua_setglobal(_pL, buf);

		lua_getglobal(_pL, "GMLua_vars");
		lua_getglobal(_pL, buf);
		lua_setfield(_pL, -2, g_BuiltinVars[i].f_name);
		lua_setglobal(_pL, "GMLua_vars");
	}
}

void InitLua(void)
{
	lS = luaL_newstate();
	luaL_openlibs(lS);
	RegisterRConstants(lS);
	RegisterAssets(lS);
	RegisterFunctions(lS);
	RegisterMetatables(lS);
	RegisterVarids(lS);
	RegisterScripts(lS);
	Dangerous_Register(lS);
}