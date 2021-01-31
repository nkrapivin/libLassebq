#include "GMLua.h"
#include "KatanaZero.h"
#include "GMLuaAutogenScript.h"
#include "Utils.h"

#define THROW(x) throw std::runtime_error((x))
std::vector<std::string> Lscripts{ };
lua_State* lS = nullptr;
bool addCollisionEvents = false;
bool g_ThrowErrors = true;

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
		if (addCollisionEvents)
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
		if (line == "addCollisionEvents")
		{
			std::cout << "Collision event name generation enabled, loading times will be WAY slower." << std::endl;
			addCollisionEvents = true;
		}
		else if (line == "ignoreLuaErrors")
		{
			std::cout << "Will ignore Lua errors, this is VERY evil and unstable!" << std::endl;
			g_ThrowErrors = false;
		}
		else if (line == "waitForDebugger")
		{
			std::cout << "Will wait for debugger in " << __FUNCTION__ << std::endl;
			wait = true;
		}
	}
	cfg.close();

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

int lua_GMLua_getvar(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc != 2)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected 2, got %d.", Largc);
	}

	CInstanceBase* inst = nullptr;
	lua_Integer varid = -1;
	if (lua_islightuserdata(_pL, 1))
	{
		inst = reinterpret_cast<CInstanceBase*>(const_cast<void*>(lua_topointer(_pL, 1)));
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `inst`, expected lightuserdata.");
	}

	if (lua_isinteger(_pL, 2))
	{
		varid = lua_tointeger(_pL, 2);
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `varid`, expected integer.");
	}

	const RValue& ref(inst->GetYYVarRef(static_cast<int>(varid)));
	return RValueToLua(_pL, ref);
}

int lua_GMLua_setvar(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc != 3)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected 3, got %d.", Largc);
	}

	CInstanceBase* inst = nullptr;
	lua_Integer varid = -1;
	if (lua_islightuserdata(_pL, 1))
	{
		inst = reinterpret_cast<CInstanceBase*>(const_cast<void*>(lua_topointer(_pL, 1)));
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `inst`, expected lightuserdata.");
	}

	if (lua_isinteger(_pL, 2))
	{
		varid = lua_tointeger(_pL, 2);
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `varid`, expected integer.");
	}

	RValue varval = LtoR(_pL, 3); // converts a Lua variable on the stack to an RValue.
	if (varval.kind == VALUE_UNSET)
	{
		return luaL_error(_pL, __FUNCTION__ " error: passed value is of type UNSET, expected anything else.");
	}

	RValue& ref(inst->GetYYVarRef(static_cast<int>(varid)));
	ref = varval;
	return 0;
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

int lua_GMLua_getvarb(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc < 2)
	{
		return luaL_error(_pL, __FUNCTION__ " error: expected at least 2 arguments, got %d.", Largc);
	}

	CInstanceBase* inst = nullptr;
	lua_Integer varid = -1;
	int iVarind = -1;
	bool direct = false;
	lua_Integer arrIndex = ARRAY_INDEX_NO_INDEX;
	if (lua_islightuserdata(_pL, 1))
	{
		inst = reinterpret_cast<CInstanceBase*>(const_cast<void*>(lua_topointer(_pL, 1)));
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `inst`, expected lightuserdata.");
	}

	if (lua_isinteger(_pL, 2))
	{
		varid = lua_tointeger(_pL, 2);
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `varid`, expected integer.");
	}

	if (Largc > 2)
	{
		if (lua_isboolean(_pL, 3))
		{
			direct = lua_toboolean(_pL, 3) == 1 ? true : false;
		}
		else
		{
			return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `direct`, expected boolean.");
		}

		if (Largc > 3)
		{
			if (lua_isinteger(_pL, 4))
			{
				arrIndex = lua_tointeger(_pL, 4);
			}
			else
			{
				return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `arrayIndex`, expected integer.");
			}
		}
	}

	if (direct)
	{
		iVarind = static_cast<int>(varid);
	}
	else
	{
		iVarind = g_Variables[varid]->val;
	}

	RValue ret;
	
	int iarrInd = static_cast<int>(arrIndex);
	internal_getvarb(inst, iVarind, iarrInd, ret);

	return RValueToLua(_pL, ret);
}

// inst,varid,value,[direct],[arrayindex]
int lua_GMLua_setvarb(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.
	if (Largc < 3)
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected at least 3, got %d.", Largc);
	}

	YYObjectBase* inst = nullptr;
	lua_Integer varid = -1;
	int iVarind = -1;
	lua_Integer arrIndex = ARRAY_INDEX_NO_INDEX;
	bool direct = false;
	if (lua_islightuserdata(_pL, 1))
	{
		inst = reinterpret_cast<YYObjectBase*>(const_cast<void*>(lua_topointer(_pL, 1)));
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `inst`, expected lightuserdata.");
	}

	if (lua_isinteger(_pL, 2))
	{
		varid = lua_tointeger(_pL, 2);
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `varid`, expected integer.");
	}

	RValue val = LtoR(_pL, 3);
	if (val.kind == VALUE_UNSET)
	{
		return luaL_error(_pL, __FUNCTION__ " error: passed value is of type UNSET, expected anything else.");
	}

	if (Largc > 3)
	{
		if (lua_isboolean(_pL, 4))
		{
			direct = lua_toboolean(_pL, 4) == 1 ? true : false;
		}
		else
		{
			return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `direct`, expected boolean.");
		}

		if (Largc > 4)
		{
			if (lua_isinteger(_pL, 5))
			{
				arrIndex = lua_tointeger(_pL, 5);
			}
			else
			{
				return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `arrayIndex`, expected integer.");
			}
		}
	}

	if (direct)
	{
		iVarind = static_cast<int>(varid);
	}
	else
	{
		iVarind = g_Variables[varid]->val;
	}

	int iArrind = static_cast<int>(arrIndex);
	internal_setvarb(inst, iVarind, iArrind, val, _pL);

	return 0;
}

const lua_Integer GM_noone = -4l;
const lua_Integer GM_all = -3l;
const lua_Integer GM_other = -2l;
const lua_Integer GM_self = -1l;

int lua_GMLua_instToPtr(lua_State* _pL)
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
			case GM_self: lua_pushlightuserdata(_pL, g_Self); return 1;
			case GM_other: lua_pushlightuserdata(_pL, g_Other); return 1;
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
				lua_pushlightuserdata(_pL, inst);
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
	int funcIndex = lua_tonumber(_pL, lua_upvalueindex(1));
	int funcArgc = lua_tonumber(_pL, lua_upvalueindex(2));
	return DoLuaGMLCall(_pL, funcIndex, funcArgc);
}

void RegisterFunctions(lua_State* _pL)
{
	for (int i = 0; i < *g_RFunctionTableLen; i++)
	{
		const RFunction& rf = (*g_RFunctionTable)[i];
		std::string rfname(rf.f_name, 64);

		// skip invalid or weird functions such as @@NewGMLArray@@ or $PRINT.
		if (rfname.rfind('@') != std::string::npos
			|| rfname.rfind(' ') != std::string::npos
			|| rfname.rfind('$') != std::string::npos) continue;

		// do the magic.
		std::string lN("GML_"); // append "GML_" prefix to the function name.
		lN += rfname;

		lua_pushnumber(_pL, i);
		lua_pushnumber(_pL, rf.f_argnumb);
		lua_pushcclosure(_pL, lua_GMLua_cclosure, 2);
		lua_setglobal(_pL, lN.c_str());
	}

	// Custom variable management functions.
	lua_register(_pL, "GMLua_getvar", lua_GMLua_getvar);
	lua_register(_pL, "GMLua_setvar", lua_GMLua_setvar);
	lua_register(_pL, "GMLua_getvarb", lua_GMLua_getvarb);
	lua_register(_pL, "GMLua_setvarb", lua_GMLua_setvarb);
	lua_register(_pL, "GMLua_instToPtr", lua_GMLua_instToPtr);
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
	if (gmargc != luaargc)
	{
		luaL_error(_pL, __FUNCTION__ " error: invalid argument count, expected %d, got %d.", gmargc, luaargc);
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
	for (int i = 0; true; i++)
	{
		YYVAR* v = g_Variables[i];
		if (v == nullptr) break;
		memset(buf, 0, sizeof(buf));
		if (strcat_s(buf, sizeof(buf), "GMLVar_") == EINVAL) abort();
		if (strcat_s(buf, sizeof(buf), v->pName) == EINVAL) abort();
		lua_pushinteger(_pL, i);
		lua_setglobal(_pL, buf);
	}

	lua_pushlightuserdata(_pL, *g_pGlobal);
	lua_setglobal(_pL, "_pGlobal");
}

void RegisterBuiltinVarids(lua_State * _pL)
{
	char buf[256]{ '\0' };
	for (int i = 0; i < 500; i++)
	{
		if (g_BuiltinVars[i].f_name == nullptr || g_BuiltinVars[i].f_getroutine == nullptr) break;

		memset(buf, 0, sizeof(buf));
		if (strcat_s(buf, sizeof(buf), "GMLBVar_") == EINVAL) abort();
		if (strcat_s(buf, sizeof(buf), g_BuiltinVars[i].f_name) == EINVAL) abort();
		lua_pushinteger(_pL, i);
		lua_setglobal(_pL, buf);
	}
}

void InitLua(void)
{
	lS = luaL_newstate();
	luaL_openlibs(lS);
	RegisterRConstants(lS);
	RegisterAssets(lS);
	RegisterFunctions(lS);
	RegisterVarids(lS);
	RegisterBuiltinVarids(lS);
	RegisterScripts(lS);
}

void DumpRFunctions(void)
{
	std::ofstream hdr("kek.h", std::ofstream::trunc);
	std::ofstream src("kek.c", std::ofstream::trunc);
	std::ofstream rfc("kek.hpp", std::ofstream::trunc);

	hdr << "#pragma once" << std::endl << std::endl;
	hdr << "#include \"GMLua.h\"" << std::endl << std::endl;
	src << "#include \"GMLuaAutogen.h\"" << std::endl << std::endl;
	for (int i = 0; i < *g_RFunctionTableLen; i++)
	{
		const RFunction& rf = (*g_RFunctionTable)[i];
		if (strchr(rf.f_name, '@') || strchr(rf.f_name, '$') || strlen(rf.f_name) >= sizeof(rf.f_name)) continue;

		hdr << "int lua_" << rf.f_name << "(lua_State *_pL); // takes " << rf.f_argnumb << " arguments" << std::endl;
		rfc << "case " << i << ": return (lua_" << rf.f_name << ");" << std::endl;

		src << "int lua_" << rf.f_name << "(lua_State *_pL) { return DoLuaGMLCall(_pL, " << i << ", " << rf.f_argnumb << "); }";
		src << std::endl;
	}

	hdr.close();
	src.close();
	rfc.close();
}

void DumpGMLScripts(void)
{
	std::ofstream h("GMLuaAutogenScript.h", std::ofstream::trunc);
	std::ofstream c("GMLuaAutogenScript.cpp", std::ofstream::trunc);
	std::ofstream r("GMLuaAutogenRegister.cpp", std::ofstream::trunc);
	std::ofstream e("enum.h", std::ofstream::trunc);

	const std::string pref("gml_Script_");
	h << "#pragma once" << std::endl;
	h << "#include \"GMLua.h\"" << std::endl;
	h << "void RegisterScripts(lua_State *_pL);" << std::endl;
	h << std::endl;
	c << "#include \"GMLuaAutogenScript.h\"" << std::endl;
	c << std::endl;
	r << "void RegisterScripts(lua_State* _pL) {" << std::endl;
	for (int i = 0; i < g_GMLScriptsSize; i++)
	{
		std::string n(g_GMLScripts[i].pName);
		if (n.rfind(pref) != std::string::npos)
		{
			std::string ss = n.substr(pref.length());
			h << "int lua_Script_" << ss << "(lua_State *_pL);" << std::endl;
			c << "int lua_Script_" << ss << "(lua_State *_pL) { return DoLuaScriptCall(_pL, " << i << "); }" << std::endl;
			r << "    lua_register(_pL, \"GMLScript_" << ss << "\", lua_Script_" << ss << ");" << std::endl;
		}
	}
	r << "}" << std::endl;

	e << "enum _VARIABLE_ID {" << std::endl;
	for (int i = 0; true; i++)
	{
		if (g_Variables[i] == nullptr) break;
		e << "    VARIABLE_" << g_Variables[i]->pName << " = " << i << "," << std::endl;
	}
	e << "};" << std::endl << std::endl;
	e << "typedef _VARIABLE_ID VARIABLE_ID;" << std::endl;

	h.close();
	c.close();
	r.close();
	e.close();
}