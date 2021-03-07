#include "ScriptHooker.h"
#include "SHAutogen.h"
#if USE_DETOURS

int getAutogenTableSize()
{
	for (int i = 0; true; i++)
	{
		if (SH_DummyRoutines[i] == nullptr)
		{
			return i;
		}
	}
}

void SH_pushCInstance(lua_State* _pL, CInstance* _pInst)
{
	CInstance** luaSelf = reinterpret_cast<CInstance**>(lua_newuserdata(lS, sizeof(CInstance*)));
	*luaSelf = _pInst;
	luaL_getmetatable(lS, "__libLassebq_GMLInstance_metatable");
	lua_setmetatable(lS, -2);
}

void SH_pushScriptArgs(lua_State* _pL, const int _count, const RValue** _args)
{
	lua_createtable(_pL, _count, 0);
	for (int _arg = 0; _arg < _count; _arg++)
	{
		RValueToLua(_pL, *_args[_arg]);
		lua_rawseti(_pL, -2, 1 + _arg);
	}
}

int lua_Base(lua_State* _pL)
{
	lua_getglobal(_pL, "GMLua_Detours_Index");
	lua_Integer myind = lua_tointeger(_pL, -1);
	lua_pop(_pL, 1);

	RValue** args = nullptr;
	int Largc = lua_gettop(lS);

	if (Largc > 0)
	{
		args = new RValue*[Largc];
		for (int i = 0; i < Largc; i++)
		{
			args[i] = new RValue(LtoR(_pL, 1 + i));
		}
	}

	RValue result(nullptr, true);
	reinterpret_cast<GML_Script>(SH_DummyPVOIDs[myind])(g_Self, g_Other, result, Largc, const_cast<const RValue**>(args));

	if (args != nullptr)
	{
		for (int i = 0; i < Largc; i++)
		{
			delete args[i];
		}

		delete args;
	}

	return RValueToLua(_pL, result);
}

RValue& SH_hookerRoutine(const int _myIndex, CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args)
{
	g_Self = _pSelf;
	g_Other = _pOther;

	const YYGMLFunc& myself = g_GMLScripts[_myIndex];
	const std::string prefix("gml_Script_");
	const std::string scriptName(std::string(myself.pName).substr(prefix.length()));

	int r = LUA_OK; const char* errmsg = nullptr; int a = -1; int type = LUA_TNONE; int top = 0; int oldtop = 0; bool call = true;
	for (const std::string& files : Lscripts)
	{
		if (CheckFileOk(files)) // weird WinAPI file wait fix, when you're tryna do live coding this does help.
		{
			r = luaL_dofile(lS, files.c_str());
			if (r == LUA_OK)
			{
				a = lua_gettop(lS);
				if (a > 0)
				{
					type = lua_type(lS, -1);
					if (type == LUA_TTABLE)
					{
						type = lua_getfield(lS, -1, scriptName.c_str()); // a++
						if (type == LUA_TTABLE)
						{
							// set detours index.
							lua_pushinteger(lS, _myIndex);
							lua_setglobal(lS, "GMLua_Detours_Index");

							// set base.
							lua_register(lS, "GMLua_Detours_Base", lua_Base);

							// handle 'Before'
							oldtop = lua_gettop(lS);
							type = lua_getfield(lS, -1, "Before"); // a++
							if (type == LUA_TFUNCTION)
							{
								SH_pushCInstance(lS, _pSelf);
								SH_pushCInstance(lS, _pOther);
								SH_pushScriptArgs(lS, _count, _args);
								r = lua_pcall(lS, 3, LUA_MULTRET, 0);
								if (r != LUA_OK)
								{
									errmsg = lua_tostring(lS, -1);
									if (g_ThrowErrors)
									{
										YYError("Lua Error: lua_pcall failed with result %d in script %s/Before.\r\nDetails:\r\n%s\r\n", r, scriptName.c_str(), errmsg);
									}
									lua_pop(lS, 1);
								}

								top = lua_gettop(lS);
								if (top != oldtop)
								{
									//std::cout << "Before returned!!" << std::endl;
									call = false;
									_result.__localCopy(LtoR(lS, -1));
									lua_pop(lS, 1); // pop "Before" result
								}
							}
							else
							{
								lua_pop(lS, 1);
							}

							// handle original
							if (call)
							{
								// call the original base script via trampoline.
								reinterpret_cast<GML_Script>(SH_DummyPVOIDs[_myIndex])(_pSelf, _pOther, _result, _count, _args);

								// handle 'After'
								oldtop = lua_gettop(lS);
								type = lua_getfield(lS, -1, "After");
								if (type == LUA_TFUNCTION)
								{
									SH_pushCInstance(lS, _pSelf);
									SH_pushCInstance(lS, _pOther);
									SH_pushScriptArgs(lS, _count, _args);
									RValueToLua(lS, _result);
									r = lua_pcall(lS, 4, LUA_MULTRET, 0);
									if (r != LUA_OK)
									{
										errmsg = lua_tostring(lS, -1);
										if (g_ThrowErrors)
										{
											YYError("Lua Error: lua_pcall failed with result %d in script %s/After.\r\nDetails:\r\n%s\r\n", r, scriptName.c_str(), errmsg);
										}
										lua_pop(lS, 1);
									}

									top = lua_gettop(lS);
									if (top != oldtop)
									{
										//std::cout << "After returned!!" << std::endl;
										_result.__localCopy(LtoR(lS, -1));
										lua_pop(lS, 1); // pop "After" result
									}
								}
								else
								{
									lua_pop(lS, 1);
								}
							}
							lua_pop(lS, 1); // pop "Before"/"After" table

							// unset detours index.
							lua_pushnil(lS);
							lua_setglobal(lS, "GMLua_Detours_Index");

							// unset base.
							lua_pushnil(lS);
							lua_setglobal(lS, "GMLua_Detours_Base");
						}
						lua_pop(lS, 1); // pop user table
					}
					else
					{
						lua_pop(lS, 1); // pop whatever.
						if (g_ThrowErrors)
						{
							YYError("Lua Error: luaL_dofile (%s), GMLua scripts are supposed to return a TABLE, got %s instead. :/", files.c_str(), lua_typename(lS, type));
						}
					}
				}
				else
				{
					// script returned nothing.
				}
			}
			else
			{
				errmsg = lua_tostring(lS, -1);
				if (g_ThrowErrors)
				{
					YYError("Lua Error: luaL_dofile failed with result %d in script %s.\r\nDetails:\r\n%s\r\n", r, scriptName.c_str(), errmsg);
				}
				lua_pop(lS, 1);
			}
		}
	}

	return _result;
}

#define DTR_LLBQ_CHK(x,msg) if ((x) != NO_ERROR) { std::cout << "[Hooker]: Detours call failed: " << (msg) << ". result=" << (x) << std::endl; abort(); }

void SH_hookGMLScript(const YYGMLFunc& ref, const int gmlScriptIndex)
{
	LONG e = NO_ERROR;

	e = DetourTransactionBegin();
	DTR_LLBQ_CHK(e, "DetourTransactionBegin");
	e = DetourUpdateThread(GetCurrentThread());
	DTR_LLBQ_CHK(e, "DetourUpdateThread");

	// the magic is here.
	SH_DummyPVOIDs[gmlScriptIndex] = ref.ptr;
	DetourAttach(&SH_DummyPVOIDs[gmlScriptIndex], SH_DummyRoutines[gmlScriptIndex]);
	DTR_LLBQ_CHK(e, "DetourAttach");

	e = DetourTransactionCommit();
	DTR_LLBQ_CHK(e, "DetourTransactionCommit");

	std::cout << "[Hooker]: Hooked (Detoured) GML script " << ref.pName << std::endl;
}

void SH_unhookGMLScript(int _index)
{
	LONG e = NO_ERROR;

	e = DetourTransactionBegin();
	DTR_LLBQ_CHK(e, "DetourTransactionBegin");
	e = DetourUpdateThread(GetCurrentThread());
	DTR_LLBQ_CHK(e, "DetourUpdateThread");

	// the magic is here.
	DetourDetach(&SH_DummyPVOIDs[_index], SH_DummyRoutines[_index]);
	DTR_LLBQ_CHK(e, "DetourDetach");

	e = DetourTransactionCommit();
	DTR_LLBQ_CHK(e, "DetourTransactionCommit");

	std::cout << "[Hooker]: Unhooking GML script index " << _index << std::endl;
}

void SH_quitDetours()
{
	int size = getAutogenTableSize();
	for (int i = 0; i < size; i++)
	{
		if (SH_DummyPVOIDs[i] != nullptr)
		{
			SH_unhookGMLScript(i);
		}
	}

	std::cout << "[Hooker]: Detached!" << std::endl;
}

#endif