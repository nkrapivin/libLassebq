#include "GMLua.h"
#ifdef DITTO_WIN_STEAM
#include "TheSwordsOfDitto.h"
#else
#include "KatanaZero.h"
#endif
#include "Utils.h"

#define THROW(x) throw std::runtime_error((x))
std::vector<std::string> Lscripts{ };
lua_State* lS = nullptr;
bool g_AddCollisionEvents = false;
bool g_ThrowErrors = true;
bool g_NoConsole = false;
bool g_IgnoreArgc = false;
bool g_AddScripts = false;
int alarm_varid = -1;

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
	std::cout << "Adding constants to Lua..." << std::endl;

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

#define ASSET_PUSH() if (strcmp(Result.pRefString->get(), "<undefined>") == 0) break; \
	lua_pushnumber(_pL, i);                                                           \
	lua_setglobal(_pL, Result.pRefString->get())

void RegisterAssets(lua_State* _pL)
{
	std::cout << "Adding asset names to Lua..." << std::endl;

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
	}
	cfg.close();

	// wait after we load the config.
	if (wait) WaitForDebugger();
}

RValue LtoR(lua_State* _pL, int a)
{
	if (lua_isboolean(_pL, a))
	{
		bool v = (lua_toboolean(_pL, a) == 1) ? true : false;
		return RValue(v);
	}
	else if (lua_islightuserdata(_pL, a))
	{
		const void* v = lua_topointer(_pL, a);
		return RValue(const_cast<void*>(v));
	}
	else if (lua_istable(_pL, a))
	{
		lua_Unsigned arrLen = lua_rawlen(_pL, a);
		RValue arr(0.0); // will be filled.
		for (int i = 0; i < arrLen; i++)
		{
			lua_pushinteger(_pL, i + 1);
			lua_gettable(_pL, a);
			(arr)(i) = LtoR(_pL, -1);
			lua_pop(_pL, 1);
		}
		arr.pRefArray->refcount++; // dynamic arrays are evil.
		return arr;
	}
	else if (lua_isinteger(_pL, a))
	{
		long long v = lua_tointeger(_pL, a);
		return RValue(v);
	}
	else if (lua_isnumber(_pL, a))
	{
		double v = lua_tonumber(_pL, a);
		return RValue(v);
	}
	else if (lua_isstring(_pL, a))
	{
		const char* v = lua_tostring(_pL, a);
		return RValue(v);
	}
	else if (lua_isnil(_pL, a))
	{
		return RValue(nullptr, true);
	}
	else
	{
		return RValue();
	}
}

bool internal_getvarb(CInstanceBase* obj, int varind, int arrind, RValue& ret)
{
	if (varind < 10000)
	{
		return g_BuiltinVars[varind].f_getroutine(obj, arrind, &ret);
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
			luaL_error(_pL, __FUNCTION__ " error: Tried to set a read-only builtin variable! (varind=%d,arrind=%d)", varind, arrind);
			return false;
		}
		return g_BuiltinVars[varind].f_setroutine(obj, arrind, &val);
	}
	else
	{
		val = obj->GetYYVarRef(varind - 100000);
		return true;
	}
}

// inst,varTable,[arrayIndex]
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
	int arrIndex = ARRAY_INDEX_NO_INDEX;

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
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `inst`, expected lightuserdata.");
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

	if (isBuiltin)
	{
		if (Largc > 2)
		{
			if (lua_isinteger(_pL, 3))
			{
				arrIndex = static_cast<int>(lua_tointeger(_pL, 3));
			}
			else
			{
				return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `arrIndex`, expected integer.");
			}
		}

		RValue ret;
		internal_getvarb(inst, varId, arrIndex, ret);
		return RValueToLua(_pL, ret);
	}
	else
	{
		const RValue& ref(inst->GetYYVarRef(varId));
		return RValueToLua(_pL, ref);
	}
}

// inst,varTable,value,[arrayindex]
int lua_GMLua_setvar(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc < 3)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected at least 3, got %d.", Largc);
	}

	CInstanceBase* inst = nullptr;
	int varId = -1;
	int arrIndex = ARRAY_INDEX_NO_INDEX;
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
		if (Largc > 3)
		{
			if (lua_isinteger(_pL, 4))
			{
				arrIndex = static_cast<int>(lua_tointeger(_pL, 4));
			}
			else
			{
				return luaL_error(_pL, __FUNCTION__ " error: invalid argument type for argument `arrIndex`, expected integer.");
			}
		}

		internal_setvarb(inst, varId, arrIndex, varval, _pL);
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
	if (Largc != 1)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected 1, got %d.", Largc);
	}

	if (lua_isinteger(_pL, 1) || lua_isnumber(_pL, 1))
	{
		lua_Integer id = lua_tointeger(_pL, 1);
		switch (id)
		{
			case GM_noone: return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be `noone`.");
			case GM_all: return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be `all`.");
			case GM_self: return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be `self`, use _pSelf.");
			case GM_other: return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be `other`, use _pOther.");
			case GM_global: return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be `global`, use _pGlobal.");
			default: break;
		}

		if (id < 100000)
		{
			return luaL_error(_pL, __FUNCTION__ " error: instance id cannot be less than 100000, got %lld.", id);
		}

		CInstance* inst = (*g_RunRoom)->m_Active.m_pFirst;
		for (int i = 0; i < (*g_RunRoom)->m_Active.m_Count; i++)
		{
			if (inst == nullptr) break;

			if (inst->i_id == id)
			{
				CInstance** luaSelf = reinterpret_cast<CInstance**>(lua_newuserdata(lS, sizeof(CInstance**)));
				*luaSelf = inst;
				luaL_getmetatable(lS, "__libLassebq_GMLInstance_metatable");
				lua_setmetatable(lS, -2);
				return 1;
			}

			inst = inst->m_pNext;
		}

		lua_pushnil(_pL);
		return 1;
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `id`, expected integer or number.");
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

void RegisterFunctions(lua_State* _pL)
{
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
	lua_register(_pL, "GMLua_getvar", lua_GMLua_getvar);
	lua_register(_pL, "GMLua_setvar", lua_GMLua_setvar);
	lua_register(_pL, "GMLua_inst", lua_GMLua_inst);
	lua_register(_pL, "GMLua_ignoreArgc", lua_GMLua_ignoreArgc);
}

void RegisterScripts(lua_State* _pL)
{
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
			int arrLen = 0;
			const RValue* arr = nullptr;
			if (result.pRefArray->pArray != nullptr)
			{
				arrLen = result.pRefArray->pArray->length;
				arr = result.pRefArray->pArray->arr;
			}
			lua_createtable(_pL, arrLen, 0);
			int luaTable = lua_gettop(_pL);
			for (int elem = 0; elem < arrLen; elem++)
			{
				const RValue& rv = arr[elem];
				RValueToLua(_pL, rv);
				lua_rawseti(_pL, luaTable, 1 + elem);
			}
			return 1;
		}
		case VALUE_UNDEFINED:
		case VALUE_JSNULL:
			lua_pushnil(_pL);
			return 1;
		default:
			return luaL_error(_pL, __FUNCTION__ " error: cannot convert RValue to Lua, unknown RValue type %d.", mKind);
	}
}

bool LuaChkArgs(const int gmargc, int luaargc, lua_State* _pL)
{
	if (g_IgnoreArgc) return true;

	if (gmargc != luaargc)
	{
		luaL_error(_pL, __FUNCTION__ " error: invalid argument count for a GM call, expected %d, got %d.", gmargc, luaargc);
		return false;
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

void RegisterVarids(lua_State* _pL)
{
	char buf[256]{ '\0' };

	// make us a type of sorts, which will be assigned to every GMLVar object.
	luaL_newmetatable(_pL, "__libLassebq_GMLVar_metatable");
	lua_pop(_pL, 1);

	// cool and good methods.
	luaL_newmetatable(_pL, "__libLassebq_GMLInstance_metatable");
	luaL_dostring(_pL, "return (function(t,k) return GMLua_getvar(t, GMLua_vars[k]) end)");
	lua_setfield(_pL, -2, "__index");
	luaL_dostring(_pL, "return (function(t,k,v) GMLua_setvar(t, GMLua_vars[k], v) end)");
	lua_setfield(_pL, -2, "__newindex");
	lua_pop(_pL, 1);

	// lookup table
	lua_newtable(_pL);
	lua_setglobal(_pL, "GMLua_vars");

	// custom vars
	for (int i = 0; true; i++)
	{
		if (g_Variables[i] == nullptr) break;
		memset(buf, 0, sizeof(buf));
		if (strcat_s(buf, sizeof(buf), "GMLVar_") == EINVAL) abort();
		if (strcat_s(buf, sizeof(buf), g_Variables[i]->pName) == EINVAL) abort();

		LasseVar* v = reinterpret_cast<LasseVar*>(lua_newuserdata(_pL, sizeof(v)));
		v->index = i;
		v->isbuiltin = false;

		luaL_getmetatable(_pL, "__libLassebq_GMLVar_metatable");
		lua_setmetatable(_pL, -2);
		lua_setglobal(_pL, buf);

		lua_getglobal(_pL, "GMLua_vars");
		lua_getglobal(_pL, buf);
		lua_setfield(_pL, -2, g_Variables[i]->pName);
		lua_pop(_pL, 1);
	}

	// builtin vars.
	for (int i = 0; i < 500; i++)
	{
		if (g_BuiltinVars[i].f_name == nullptr || g_BuiltinVars[i].f_getroutine == nullptr) break;
		memset(buf, 0, sizeof(buf));
		if (strcat_s(buf, sizeof(buf), "GMLVar_") == EINVAL) abort();
		if (strcat_s(buf, sizeof(buf), g_BuiltinVars[i].f_name) == EINVAL) abort();

		if (strcmp(g_BuiltinVars[i].f_name, "alarm") == 0)
			alarm_varid = i;

		LasseVar* v = reinterpret_cast<LasseVar*>(lua_newuserdata(_pL, sizeof(v)));
		v->index = i;
		v->isbuiltin = true;

		luaL_getmetatable(_pL, "__libLassebq_GMLVar_metatable");
		lua_setmetatable(_pL, -2);
		lua_setglobal(_pL, buf);

		lua_getglobal(_pL, "GMLua_vars");
		lua_getglobal(_pL, buf);
		lua_setfield(_pL, -2, g_BuiltinVars[i].f_name);
		lua_pop(_pL, 1);
	}

	CInstance** luaGlobal = reinterpret_cast<CInstance**>(lua_newuserdata(lS, sizeof(CInstance**)));

	// this is wrong, will likely break stuff, but who cares.
	*luaGlobal = reinterpret_cast<CInstance*>(*g_pGlobal);

	luaL_getmetatable(lS, "__libLassebq_GMLInstance_metatable");
	lua_setmetatable(lS, -2);
	lua_setglobal(_pL, "_pGlobal");
}

void InitLua(void)
{
	lS = luaL_newstate();
	luaL_openlibs(lS);
	RegisterRConstants(lS);
	RegisterAssets(lS);
	RegisterFunctions(lS);
	RegisterVarids(lS);
	RegisterScripts(lS);
}