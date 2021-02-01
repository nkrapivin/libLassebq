#pragma once
#include "lua\include\lua.hpp"
#include "GMLFuncs.h"
#include "libLassebq.h"
#include "GMLConstants.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

extern std::vector<std::string> Lscripts;
extern lua_State* lS;
void InitGMLuaScripts(void);
void InitGMLuaConfig(void);
void DumpRFunctions(void);
void DumpGMLScripts(void);

void LuaToRValue(lua_State* _pL, int a, RValueList& args);
int RValueToLua(lua_State* _pL, const RValue& result);
bool LuaChkArgs(const int gmargc, int luaargc, lua_State* _pL);
int DoLuaGMLCall(lua_State* _pL, const int functionId, const int gmArgc);
int DoLuaScriptCall(lua_State* _pL, const int entryId);
void RegisterRConstants(lua_State* _pL);
void RegisterAssets(lua_State* _pL);
void RegisterVarids(lua_State* _pL);
void RegisterBuiltinVarids(lua_State* _pL);
void InitLua(void);
int lua_GMLua_getvar(lua_State* _pL);
int lua_GMLua_setvar(lua_State* _pL);
int lua_GMLua_getvarb(lua_State* _pL);
int lua_GMLua_setvarb(lua_State* _pL);
int lua_GMLua_instToPtr(lua_State* _pL);
extern bool g_ThrowErrors;
extern bool g_NoConsole;
extern bool g_AddCollisionEvents;