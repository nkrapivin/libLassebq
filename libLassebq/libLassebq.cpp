// libLassebq.cpp: определяет экспортированные функции для приложения DLL.
//

#include "libLassebq.h"
#ifdef DITTO_WIN_STEAM
#include "TheSwordsOfDitto.h"
#else
#include "KatanaZero.h"
#endif

#include "GMAddresses.h"
#include "Utils.h"
#include "GMLConstants.h"
#include "GMLua.h"
#include "GameSpecific.h"
#include <WinCon.h>
#include <fstream>
#include <shellapi.h>
#include <unordered_map>
#include <sstream>

HMODULE exeBase = nullptr;
CHash<CObjectGM>** g_ObjectHashTable = nullptr;
int g_GMLScriptsSize;
int g_VariablesSize;

std::unordered_map<std::string, int> fR; // runtime funcs
std::unordered_map<std::string, int> fS; // script
std::unordered_map<std::string, int> fV; // var
std::unordered_map<std::string, int> fB; // builtin

// <object_index, <event_key, function_pointer>>
std::unordered_map<int, std::unordered_map<unsigned long long, void*>> EventPatchMap;

RValue Result(0.0);

YYErrorT YYError = nullptr;
YYObjectBase** g_pGlobal = nullptr;

typedef CEvent*(__thiscall *GetEvRecurs)(CObjectGM* self, int etype, int esubtype);
typedef void(__thiscall *InsertEv)(CHashMap<unsigned long long, CEvent*, 3> *self, unsigned long long _key, CEvent* _value);
GetEvRecurs GetEventRecursive = nullptr;
InsertEv InsertEvent = nullptr;

void lassebq_find_bvars() {
	for (int i = 0; i < 500; i++)
	{
		const RVariableRoutine& rvr = g_BuiltinVars[i];
		if (rvr.f_getroutine == nullptr || rvr.f_name == nullptr) break;
		fB[rvr.f_name] = i;
	}
}

void lassebq_free_result() {
	Result.~RValue();
}

int lassebq_get_bvar(const std::string name) {
	int ind = fB[name];
	if (ind < 0 || ind > 500) abort();
	lassebq_free_result();
	g_BuiltinVars[ind].f_getroutine(g_Self, ARRAY_INDEX_NO_INDEX, &Result);
	return Result.asInt32();
}

void lassebq_callr(std::string id, const RValueList& args = { })
{
	lassebq_free_result();
	if (fR.find(id) == fR.end())
	{
		std::cout << "TRIED TO CALL UNKNOWN RUNTIME FUNCTION " << id << std::endl;
		abort();
	}

	CallRFunction(fR[id], Result, args);
}

void lassebq_calls(std::string id, bool isObjectEvent, const RValueList& args = { })
{
	lassebq_free_result();
	if (fR.find(id) == fR.end())
	{
		std::cout << "TRIED TO CALL UNKNOWN SCRIPT FUNCTION " << id << std::endl;
		abort();
	}

	CallScriptFunction(fS[id], Result, args, isObjectEvent);
}

void lassebq_doLua(CInstance* _pSelf, CInstance* _pOther, const char* _pLFName) // pointerLuaFunctionName
{
	int r = LUA_OK; const char* errmsg = nullptr;
	for (const std::string& script : Lscripts)
	{
		r = luaL_dofile(lS, script.c_str());
		if (r == LUA_OK)
		{
			lua_getglobal(lS, _pLFName);
			if (lua_isfunction(lS, -1)) // if the function exists...
			{
				// push pSelf/pOther as arguments to the function call...
				// TODO: wrappers?
				CInstance** luaSelf = reinterpret_cast<CInstance**>(lua_newuserdata(lS, sizeof(CInstance**)));
				*luaSelf = _pSelf;
				luaL_getmetatable(lS, "__libLassebq_GMLInstance_metatable");
				lua_setmetatable(lS, -2);
				CInstance** luaOther = reinterpret_cast<CInstance**>(lua_newuserdata(lS, sizeof(CInstance**)));
				*luaOther = _pOther;
				luaL_getmetatable(lS, "__libLassebq_GMLInstance_metatable");
				lua_setmetatable(lS, -2);

				int lArgc = 2;
				int rnum = 0;

				// do the luacall
				r = lua_pcall(lS, lArgc, rnum, 0);
				if (r != LUA_OK)
				{
					errmsg = lua_tostring(lS, -1);
					if (g_ThrowErrors)
					{
						YYError("Lua Error: lua_pcall failed with result %d in function %s.\r\nDetails:\r\n%s\r\n", r, _pLFName, errmsg);
					}
					lua_pop(lS, 1);
				}
			}
		}
		else
		{
			errmsg = lua_tostring(lS, -1);
			if (g_ThrowErrors)
			{
				YYError("Lua Error: luaL_dofile failed with result %d in function %s.\r\nDetails:\r\n%s\r\n", r, _pLFName, errmsg);
			}
			lua_pop(lS, 1);
		}
	}
}

unsigned long long lassebq_evKey(int etype, int esubtype)
{
	return static_cast<unsigned long long>(static_cast<long long>(esubtype) | (static_cast<long long>(etype) << 0x20ll));
}

void lassebq_lua_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	g_Self = _pSelf;
	g_Other = _pOther;
	
	int event_type = lassebq_get_bvar("event_type");
	int event_numb = lassebq_get_bvar("event_number");
	CEvent* ev = GetEventRecursive(_pSelf->m_pObject, event_type, event_numb);
	YY_STACKTRACE_FUNC_ENTRY(ev->e_code->i_pName, 0);

	char luaFuncName[256]{ '\0' };
	// "objectname_eventname"
	snprintf(luaFuncName, sizeof(luaFuncName), "%s_%s",
		_pSelf->m_pObject->m_pName,
		mapOfEvents[lassebq_evKey(event_type, event_numb)].c_str()
	);

	YY_STACKTRACE_LINE(1);
	lassebq_doLua(_pSelf, _pOther, luaFuncName);
}

#ifndef DITTO_WIN_STEAM
void lassebq_antiSpeedrunCheat_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	g_Self = _pSelf;
	g_Other = _pOther;

	YY_STACKTRACE_FUNC_ENTRY("libLassebq_antiSpeedrunCheat_DrawGUIEnd", 0);
	lassebq_callr("get_timer");
	lassebq_callr("sin", { Result.asReal()/100000.0 });
	double time = Result.asReal();
	double k = time * 2.0;
	double m = 4.0; // margin
	double x = 128.0 + k;
	double y = 128.0 + k;
	const char* str = "libLassebq is active,\nthe speedrun may be fake!";
	lassebq_callr("draw_set_font", { EtoD(GameFonts::font_folderbold) });

	YY_STACKTRACE_LINE(1);
	lassebq_callr("string_width", { str });
	double sw = Result.asReal();
	lassebq_callr("string_height", { str });
	double sh = Result.asReal();
	double x2 = x + sw + m;
	double y2 = y + sh + m;

	YY_STACKTRACE_LINE(2);
	lassebq_callr("draw_get_alpha");
	double oldAlpha = Result.asReal();
	lassebq_callr("draw_get_halign");
	double oldH = Result.asReal();
	lassebq_callr("draw_get_valign");
	double oldV = Result.asReal();
	YY_STACKTRACE_LINE(3);
	lassebq_callr("draw_set_alpha", { 0.5 });
	lassebq_callr("draw_set_halign", { fa_left });
	lassebq_callr("draw_set_valign", { fa_top });
	YY_STACKTRACE_LINE(4);
	lassebq_callr("draw_rectangle_color", { x - m, y - m, x2, y2, c_black, c_black, c_black, c_black, false });
	lassebq_callr("draw_text_color", { x, y, str, c_red, c_red, c_red, c_red, 1.0 });
	YY_STACKTRACE_LINE(5);
	lassebq_callr("draw_set_alpha", { oldAlpha });
	lassebq_callr("draw_set_halign", { oldH });
	lassebq_callr("draw_set_valign", { oldV });
	YY_STACKTRACE_LINE(6);
}
#endif

void lassebq_luaPatch_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	g_Self = _pSelf;
	g_Other = _pOther;

	// Execute the original event.
	int event_type = lassebq_get_bvar("event_type");
	int event_numb = lassebq_get_bvar("event_number");
	unsigned long long evKey = lassebq_evKey(event_type, event_numb);
	GML_ObjectEvent origptr = reinterpret_cast<GML_ObjectEvent>
		(EventPatchMap[_pSelf->m_pObject->m_ID][evKey]);
	origptr(_pSelf, _pOther);

	// Execute the lua function.
	CEvent* ev = GetEventRecursive(_pSelf->m_pObject, event_type, event_numb);
	// Why? When the original event returns, it will call Stacktrace's destructor, thus null-ing it
	// So we need to make a new instance of the stacktrace :/
	YY_STACKTRACE_FUNC_ENTRY(ev->e_code->i_pName, 0);
	char luaFuncName[256]{ '\0' };
	// "objectname_eventname"
	snprintf(luaFuncName, sizeof(luaFuncName), "%s_%s",
		_pSelf->m_pObject->m_pName,
		mapOfEvents[evKey].c_str()
	);
	YY_STACKTRACE_LINE(1);
	lassebq_doLua(_pSelf, _pOther, luaFuncName);
}

CObjectGM *lassebq_find_obj(int obj_index)
{
	HashNode<CObjectGM> *oNode = (*g_ObjectHashTable)->m_pHashingTable[(*g_ObjectHashTable)->m_HashingMask & obj_index].m_pFirst;
	for (;;) {
		if (oNode == nullptr) // eh? doesn't exist?
			return nullptr;
		if (oNode->m_ID == obj_index) break; // found it in O(1) yay
		oNode = oNode->m_pNext; // eh? can't find it in O(1)???
	}
	if (oNode == nullptr) return nullptr; // eh? wtf? shouldn't happen?

	return oNode->m_pObj;
}

CCode* lassebq_fake_CCode(GML_ObjectEvent evFunc, const char* evName)
{
	CCode* code = new CCode();
	code->i_kind = 1;
	code->i_str = nullptr;
	code->i_value = 0.0;
	code->i_pVM = nullptr;
	code->i_pVMDebugInfo = nullptr;
	code->i_compiled = true;
	code->i_pCode = nullptr;
	code->i_pName = YYStrDup(evName);
	code->i_CodeIndex = 0;
	code->i_pFunc = new YYGMLFunc();
	code->i_pFunc->pName = code->i_pName;
	code->i_pFunc->ptr = evFunc;
	code->i_watch = false;
	code->i_offset = 0;
	code->i_locals = 0;
	code->i_args = 0;
	code->i_flags = 0;
	return code;
}

CEvent* lassebq_fake_CEvent(int oIndex, CCode* ptr)
{
	CEvent* evt = new CEvent();
	evt->m_OwnerObjectID = oIndex;
	evt->e_code = ptr;
	return evt;
}

void lassebq_addEvent(CObjectGM* gmObj, int etype, int esubtype, const char* name, GML_ObjectEvent evt)
{
	unsigned long long key = lassebq_evKey(etype, esubtype);
	CCode* code = lassebq_fake_CCode(evt, name);
	CEvent* ev = lassebq_fake_CEvent(gmObj->m_ID, code);
	InsertEvent(gmObj->m_eventsMap, key, ev);
}

void lassebq_patchObject()
{
	std::cout << "Trying to patch lassebq obj..." << std::endl;

	int r;
	char buf[256]{ '\0' };
	for (const std::string& fn : Lscripts)
	{
		r = luaL_dofile(lS, fn.c_str());
		if (r == LUA_OK)
		{
			for (int i = 0; true; i++)
			{
#ifndef DITTO_WIN_STEAM
				if (i == EtoI(GameObjects::obj_speedrun_results_screen))
				{
					continue; // ignore any event replaces for obj_speedrun_results_screen.
				}
#endif

				CObjectGM* cogm = lassebq_find_obj(i);
				if (cogm == nullptr) break;
				const char* str = cogm->m_pName;

				for(const std::pair<unsigned long long, std::string>& pair : mapOfEvents)
				{
					memset(buf, 0, sizeof(buf));
					snprintf(buf, sizeof(buf), "%s_%s", str, pair.second.c_str());
					lua_getglobal(lS, buf);
					if (lua_isfunction(lS, -1))
					{
						int type = static_cast<int>(pair.first >> 32ull);
						int subtype = static_cast<int>(pair.first & 0xFFFFFFFFull);
						CEvent* origev = GetEventRecursive(cogm, type, subtype);
						if (origev != nullptr)
						{
							// Don't do anything if we've already added our lua stub.
							if (origev->e_code->i_pFunc->ptr == lassebq_lua_GMLRoutine
							||  origev->e_code->i_pFunc->ptr == lassebq_luaPatch_GMLRoutine)
								continue;

							std::cout << "AN EVENT " << buf << " ALREADY EXISTS! brb replacing..." << std::endl;
							EventPatchMap[i][pair.first] = origev->e_code->i_pFunc->ptr; // save the original function.
							origev->e_code->i_pFunc->ptr = lassebq_luaPatch_GMLRoutine;
							continue;
						}
						else
						{
							memset(buf, 0, sizeof(buf));
							snprintf(buf, sizeof(buf), "libLassebq_%s_%s", str, pair.second.c_str());
							std::cout << "Adding event " << buf << "..." << std::endl;
							lassebq_addEvent(cogm, type, subtype, buf, lassebq_lua_GMLRoutine);
						}
					}
					lua_pop(lS, 1);
				}
			}
		}
	}

	std::cout << "Done! Did it work? :)" << std::endl;
}

void lassebq_make_obj_liblassebq()
{
	//lassebq_dbg();
	lassebq_callr("object_add");
	int obj_index = Result.asInt32();
	std::cout << "libLassebq object index " << obj_index << std::endl;

	// find our object.
	CObjectGM *oNode = lassebq_find_obj(obj_index);
	YYFree(oNode->m_pName);
	oNode->m_pName = YYStrDup("obj_libLassebq");
	
	// mark as persistent.
	lassebq_callr("object_set_persistent", { obj_index, true });

	// Since Run_Room is NULL, we're not actually in any room just yet
	// WHICH MEANS, WE CAN DO THIS:
	lassebq_callr("room_instance_add", { 0.0, 0.0, 0.0, obj_index });
	// room_instance_add our object at position 0;0
	// first room only.
	std::cout << "libLassebq object instance id " << Result.asInt32() << std::endl;

	// do not modify or remove these two lines.
#if defined(KZ_105_GOG) || defined(KZ_105_STEAM)
	CObjectGM* speedrun_thing = lassebq_find_obj(EtoI(GameObjects::obj_speedrun_results_screen));
	lassebq_addEvent(speedrun_thing, static_cast<int>(ev_draw), static_cast<int>(ev_gui_end), "libLassebq_antiSpeedrunCheat_DrawGUIEnd", lassebq_antiSpeedrunCheat_GMLRoutine);
#endif
}

void lassebq_initYYC()
{
	InitGMLuaConfig();
	if (!g_NoConsole)
	{
		AllocConsoleQuick();

		std::cout << "libLassebq by nkrapivindev, built for project " << PROJECT_NAME << std::endl;
		std::cout << "This thing is experimental, please report any bugs to nik#5351 on Discord." << std::endl;
		std::cout << "Random quote: " << GetRandomQuote() << std::endl;
#ifdef KZ_105_GOG
		std::cout << "KZ_105_GOG, Katana Zero v1.0.5 Windows GOG" << std::endl;
#endif
#ifdef DITTO_WIN_STEAM
		std::cout << "DITTO_WIN_STEAM, The Swords of Ditto 1.17.05-205 STM" << std::endl;
#endif
		std::cout << std::endl;
		if (g_ThrowErrors) std::cout << "Will ignore Lua errors, this is VERY evil and unstable!" << std::endl;
		if (g_AddCollisionEvents) std::cout << "Collision event name generation enabled, loading times will be WAY slower." << std::endl;
	}

	exeBase = GetModuleHandleW(nullptr);
	uintptr_t exeAsUint = reinterpret_cast<uintptr_t>(exeBase);

	g_Variables = reinterpret_cast<YYVAR**>(exeAsUint + Variable_Addr);
	for (int i = 0; true; i++)
	{
		if (g_Variables[i] == nullptr)
		{
			g_VariablesSize = i;
			break;
		}

		fV[g_Variables[i]->pName] = g_Variables[i]->val;
	}

	g_GMLScripts = reinterpret_cast<YYGMLFunc*>(exeAsUint + GMLScript_Addr);
	for (int i = 0; true; i++)
	{
		if (g_GMLScripts[i].pName == nullptr || g_GMLScripts[i].ptr == nullptr || ((strncmp(g_GMLScripts[i].pName, "gml_", 4) != 0) && (strncmp(g_GMLScripts[i].pName, "Time", 4) != 0)))
		{
			g_GMLScriptsSize = i;
			break;
		}

		fS[g_GMLScripts[i].pName] = i;
	}

	g_RunRoom = reinterpret_cast<CRoom**>(exeAsUint + Run_Room_Addr);
	g_RFunctionTableLen = reinterpret_cast<int*>(exeAsUint + RFunctionTableL_Addr);
	g_RFunctionTable = reinterpret_cast<RFunction**>(exeAsUint + RFunctionTable_Addr);
	g_ObjectHashTable = reinterpret_cast<CHash<CObjectGM>**>(exeAsUint + Object_Hash_Addr);
	FREE_RValue__Pre = reinterpret_cast<FREE_RVal_Pre>(exeAsUint + FREE_RValue__Pre_Addr);
	ARRAY_LVAL_RValue = reinterpret_cast<ARRAYLVal>(exeAsUint + ARRAY_LVAL_RV_Addr);
	YYSetString = reinterpret_cast<YYSetStr>(exeAsUint + YYSetString_Addr);
	YYCreateString = reinterpret_cast<YYCreStr>(exeAsUint + YYCreateString_Addr);
	YYStrDup = reinterpret_cast<YYStrDupT>(exeAsUint + YYStrDup_Addr);
	YYFree = reinterpret_cast<YYFreeT>(exeAsUint + YYFree_Addr);
	g_Self = nullptr;
	SYYStackTrace::s_pStart = reinterpret_cast<SYYStackTrace**>(exeAsUint + YYSTraceStart_Addr);

	// remove this later
	g_ConstNames = reinterpret_cast<const char***>(exeAsUint + ConstNames_Addr);
	g_ConstNumb = reinterpret_cast<const int*>(exeAsUint + ConstNumb_Addr);
	g_ConstValues = reinterpret_cast<const RValue**>(exeAsUint + ConstValues_Addr);
	// remove this later

	YYError = reinterpret_cast<YYErrorT>(exeAsUint + YYError_Addr);

	GetContextStackTop = reinterpret_cast<GetCtxStackTop>(exeAsUint + GetCtxStackTop_Addr);
	DeterminePotentialRoot = reinterpret_cast<DetPotRoot>(exeAsUint + DeterminePotRoot_Addr);
	GetEventRecursive = reinterpret_cast<GetEvRecurs>(exeAsUint + GetEvRecursive_Addr);
	InsertEvent = reinterpret_cast<InsertEv>(exeAsUint + InsertEvent_Addr);
	g_BuiltinVars = reinterpret_cast<RVariableRoutine*>(exeAsUint + BuiltinVars_Addr);
	lassebq_find_bvars();

	for (int i = 0; i < *g_RFunctionTableLen; i++)
	{
		const RFunction& RFunc = (*g_RFunctionTable)[i];
		fR[RFunc.f_name] = i;
	}

	g_pGlobal = reinterpret_cast<YYObjectBase**>(exeAsUint + Global_YYObject_Addr);

#ifndef DITTO_WIN_STEAM /* the heck ditto does? o_O */
	lassebq_make_obj_liblassebq();
#endif

	//WaitForDebugger();
	// I'd print authors and copyright before doing any lua stuff
	std::cout << std::endl;
	std::cout << LUA_COPYRIGHT << std::endl;
	std::cout << LUA_AUTHORS << std::endl;
	std::cout << std::endl;

	// and now, the fun stuff.
	std::cout << "Initializing GMLua..." << std::endl;
	InitGMLuaScripts();
	InitLua();
	lassebq_patchObject();

	// very cursed.
	std::cout << "Applying " << PROJECT_NAME << " specific patches..." << std::endl;
	ApplyGameSpecificPatches(exeAsUint);

	std::cout << "All Done, proceeding to the game..." << std::endl;
	std::cout << std::endl;

	// oh, at long last, switch to our game window instead of the console window :/
	if (!g_NoConsole)
	{
		lassebq_callr("window_handle");
		HWND hGMWindow = reinterpret_cast<HWND>(Result.asPointer());
		SetActiveWindow(hGMWindow);
		SetForegroundWindow(hGMWindow);
	}
}

funcR lassebq_init()
{
	return 1.0;
}

funcR lassebq_shutdown()
{
	// TODO: do something more complicated than this?
	lua_close(lS);
	return 1.0;
}

funcV RegisterCallbacks(char* p1, char* p2, char* p3, char* p4)
{
	// do the job.
	lassebq_initYYC();
}