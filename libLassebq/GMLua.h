#pragma once
#include "lua\lua.hpp"
#include "GMLFuncs.h"
#include "libLassebq.h"
#include "GMLConstants.h"
#include "ScriptHooker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

extern std::vector<std::string> Lscripts;
extern lua_State* lS;
void InitLua(void);
void InitGMLuaScripts(void);
void InitGMLuaConfig(void);

struct LasseVar {
	int index;
	bool isbuiltin;
};

struct LasseVarB {
	CInstanceBase* self;
	int varid;
};

// Lua->RV->Lua stuff
RValue LtoR(lua_State* _pL, int a);
void LuaToRValue(lua_State* _pL, int a, RValueList& args);
int RValueToLua(lua_State* _pL, const RValue& result);

// Lua->GML call stuff
bool LuaChkArgs(const int gmargc, int luaargc, lua_State* _pL);
int DoLuaGMLCall(lua_State* _pL, const int functionId, const int gmArgc);
int DoLuaScriptCall(lua_State* _pL, const int entryId);

// registrars
void RegisterRConstants(lua_State* _pL);
void RegisterAssets(lua_State* _pL);
void RegisterVarids(lua_State* _pL);

int lua_GMLua_getvar(lua_State* _pL);
int lua_GMLua_setvar(lua_State* _pL);
int lua_GMLua_inst(lua_State* _pL);

void RenewGlobal(lua_State* _pL);

// config variables.
extern bool g_ThrowErrors;
extern bool g_NoConsole;
extern bool g_AddCollisionEvents;
extern bool g_AddScripts;