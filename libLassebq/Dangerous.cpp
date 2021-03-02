#include "Dangerous.h"

#include "stdafx.h"

uintptr_t GetProcessBase()
{
	return reinterpret_cast<uintptr_t>(GetModuleHandleW(nullptr));
}

// address,data
int lua_Dangerous_WriteProcessMemory(lua_State * _pL)
{
	int Largc = lua_gettop(_pL); // get argument count.

	if (Largc < 2)
	{
		return luaL_error(_pL, __FUNCTION__ " error: expected at least 2 arguments, got %d.", Largc);
	}

	lua_Unsigned address = 0;
	if (lua_isinteger(_pL, 1))
	{
		address = static_cast<lua_Unsigned>(lua_tointeger(_pL, 1));
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `address`, expected integer.");
	}

	if (!lua_istable(_pL, 2))
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `data`, expected table.");
	}

	lua_len(_pL, 2);
	unsigned int len = static_cast<unsigned int>(lua_tointeger(_pL, -1));
	lua_pop(_pL, 1);
	if (len == 0)
	{
		lua_pushboolean(_pL, false);
		return 1;
	}

	LPBYTE data = new BYTE[len];
	for (unsigned int i = 0; i < len; i++)
	{
		lua_pushinteger(_pL, i + 1);
		lua_gettable(_pL, 2);
		data[i] = static_cast<BYTE>(lua_tointeger(_pL, -1));
		lua_pop(_pL, 1);
	}

	SIZE_T written = 0;
	BOOL r = WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(GetProcessBase() + address), data, len, &written);
	delete[] data;

	lua_pushboolean(_pL, r);
	return 1;
}

// address,amount
int lua_Dangerous_ReadProcessMemory(lua_State* _pL)
{
	int Largc = lua_gettop(_pL); // get argument count
	if (Largc < 2)
	{
		return luaL_error(_pL, __FUNCTION__ " error: expected at least 2 arguments, got %d.", Largc);
	}

	lua_Unsigned address = 0;
	if (lua_isinteger(_pL, 1))
	{
		address = static_cast<lua_Unsigned>(lua_tointeger(_pL, 1));
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `address`, expected integer.");
	}

	unsigned int amount = 0;
	if (lua_isinteger(_pL, 2))
	{
		amount = static_cast<unsigned int>(lua_tointeger(_pL, 2));
	}
	else
	{
		return luaL_error(_pL, __FUNCTION__ " error: invalid type for argument `amount`, expected integer.");
	}

	LPBYTE data = new BYTE[amount]{ 0 };
	SIZE_T read = 0;
	BOOL r = ReadProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(GetProcessBase() + address), data, amount, &read);

	lua_createtable(_pL, read, 0);
	for (SIZE_T i = read; i > 0; i--)
	{
		lua_pushinteger(_pL, data[i - 1]);
		lua_rawseti(_pL, -2, i);
	}
	delete[] data;
	return 1;
}

void Dangerous_Register(lua_State* _pL)
{
	// address[integer], data[table], ret=boolean
	lua_register(_pL, "D_WriteProcessMemory", lua_Dangerous_WriteProcessMemory);
	// address[integer], amount[integer], ret=table/nil
	lua_register(_pL, "D_ReadProcessMemory", lua_Dangerous_ReadProcessMemory);
}