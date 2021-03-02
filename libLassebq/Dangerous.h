#pragma once
#include "GMLua.h"

void Dangerous_Register(lua_State* _pL);
int lua_Dangerous_WriteProcessMemory(lua_State* _pL);
int lua_Dangerous_ReadProcessMemory(lua_State* _pL);