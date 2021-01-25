// libLassebq.cpp: определяет экспортированные функции для приложения DLL.
//

#include "libLassebq.h"
#include "KatanaZero.h"
#include "KatanaZeroIDs.h"
#include <WinCon.h>
#include <fstream>
#include <shellapi.h>
#include <unordered_map>

#define PROMPT "> "
#define PRINT_VAR(cl,n) oS << #n << " = " << cl->i_##n << std::endl


HMODULE exeBase = nullptr;
YYVAR** g_Variables = nullptr;
YYGMLFunc* g_GMLScripts = nullptr;
CRoom** g_RunRoom = nullptr;
RFunction** g_RFunctionTable = nullptr;
CHash<CObjectGM>** g_ObjectHashTable = nullptr;
SYYStackTrace** SYYStackTrace::s_pStart = nullptr;
DynamicArrayOfInteger* g_ObjectHasEvent = nullptr;
int* g_ObjectNumEvent = nullptr;
int* g_RFunctionTableLen = nullptr;
CInstance* g_Self = nullptr;
CInstance* g_Other = nullptr;
const char** g_WorkingDirectory = nullptr;
int g_GMLScriptsSize;
int g_VariablesSize;
int g_LLBQObject = -1;
FREE_RVal_Pre FREE_RValue__Pre;
YYSetStr YYSetString;
YYCreStr YYCreateString;
GMMMSetLength MMSetLength;
HWND g_YYGMWindowHWND;

GetCtxStackTop GetContextStackTop = nullptr;
DetPotRoot DeterminePotentialRoot = nullptr;
VarGetValDirect Variable_GetValue_Direct = nullptr;
FindRValSlot FindRValueSlot = nullptr;

// RegisterCallback stuff
GML_ds_map_create ds_map_create = nullptr;
GML_ds_map_add_real ds_map_add_real = nullptr;
GML_ds_map_add_string ds_map_add_string = nullptr;
GML_create_async_event create_async_event = nullptr;

std::unordered_map<std::string, int> fR;
std::unordered_map<std::string, int> fS;
std::unordered_map<std::string, int> fV;

RValue Result(0.0);

typedef RValue&(__thiscall *GetYYVRef)(YYObjectBase *self, int _index);
GetYYVRef InternalGetYYVarRef = nullptr;
RValue& GetRVRef(CInstance* self, int i)
{
	if (self->yyvars != nullptr)
		return self->yyvars[i];
	return InternalGetYYVarRef(reinterpret_cast<YYObjectBase *>(self), i);
}

void lassebq_free_result() {
	Result.~RValue();
	memset(&Result, 0, sizeof(RValue));
	Result.kind = VALUE_UNSET;
	Result.v64 = 0L;
	Result.flags = 0;
}

void clearConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten = 0;
	DWORD dwConSize = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
		TEXT(' '),      // Character to write to the buffer
		dwConSize,       // Number of cells to write
		coordScreen,     // Coordinates of first cell
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute
		coordScreen,      // Coordinates of first cell
		&cCharsWritten))  // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(hConsole, coordScreen);
}

bool lassebq_getvar_direct(std::string name, RValue& ret, int array_index = ARRAY_INDEX_NO_INDEX)
{
	if (fV.find(name) == fV.end())
	{
		std::cout << "TRIED TO ACCESS A NON-EXISTING VARIABLE " << name << std::endl;
		abort();
	}

	return Variable_GetValue_Direct(reinterpret_cast<YYObjectBase*>(g_Self), fV[name], array_index, &ret);
}

const char* lassebq_get_working_directory()
{
	return *g_WorkingDirectory;
}

void lassebq_dbg()
{
	std::cout << "Waiting for Visual Studio's debugger..." << std::endl;

	while (IsDebuggerPresent() == FALSE)
	{
		Sleep(100);
	}
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

void lassebq_Create_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	// PLEASE DO NOT FORGET THESE FOUR LINES, THEY ARE ESSENTIAL FOR CALLR/CALLS TO WORK!
	YY_STACKTRACE_FUNC_ENTRY("libLassebq_Create", 0);
	YY_STACKTRACE_LINE(1);
	g_Self = _pSelf; // SET GLOBAL LIBLASSEBQ SELF TO ***OUR*** SELF!!!
	g_Other = _pOther; // not really required, but still!

	lassebq_callr("window_set_caption", { "Katana ZERO [MODDED]" });
	std::cout << "Hello from Create Event!" << std::endl;
}

void lassebq_Step_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	// PLEASE DO NOT FORGET THESE FOUR LINES, THEY ARE ESSENTIAL FOR CALLR/CALLS TO WORK!
	YY_STACKTRACE_FUNC_ENTRY("libLassebq_Step", 0);
	YY_STACKTRACE_LINE(1);
	g_Self = _pSelf; // SET GLOBAL LIBLASSEBQ SELF TO ***OUR*** SELF!!!
	g_Other = _pOther; // not really required, but still!
}

void lassebq_DrawGUI_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	// PLEASE DO NOT FORGET THESE FOUR LINES, THEY ARE ESSENTIAL FOR CALLR/CALLS TO WORK!
	YY_STACKTRACE_FUNC_ENTRY("libLassebq_DrawGUI", 0);
	YY_STACKTRACE_LINE(1);
	g_Self = _pSelf; // SET GLOBAL LIBLASSEBQ SELF TO ***OUR*** SELF!!!
	g_Other = _pOther; // not really required, but still!
}

#define quickvarR(_RVV) RValue& _RVV(GetRVRef(g_Self, fV[#_RVV]))
#define quickvarB(_RVV) RValue _RVV; lassebq_getvar_direct(#_RVV, _RVV)
#define varS(_RVV) << #_RVV << " = " << _RVV.asString() << std::endl

void lassebq_playerGUI_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	// PLEASE DO NOT FORGET THESE FOUR LINES, THEY ARE ESSENTIAL FOR CALLR/CALLS TO WORK!
	YY_STACKTRACE_FUNC_ENTRY("libLassebq_Player_DrawGUI", 0);
	YY_STACKTRACE_LINE(1);
	g_Self = _pSelf; // SET GLOBAL LIBLASSEBQ SELF TO ***OUR*** SELF!!!
	g_Other = _pOther; // not really required, but still!

	// get refs to player vars
	quickvarR(vsp);
	quickvarR(hsp);
	quickvarR(can_move);
	quickvarB(x);
	quickvarB(y);
	quickvarB(fps);
	quickvarB(fps_real);

	std::stringstream ss;
	ss  << "liblassebq player debugger:" << std::endl
		<< "custom vars (unset for now, because I'm a stupid idiot):" << std::endl
		// add your stuff here.
		varS(vsp)
		varS(hsp)
		varS(can_move)
		<< "builtin vars (should work):" << std::endl
		varS(x)
		varS(y)
		varS(fps)
		varS(fps_real)
		<< std::endl;

	lassebq_callr("draw_set_halign", { 0.0 });
	lassebq_callr("draw_set_valign", { 0.0 });
	lassebq_callr("draw_set_font", { EtoD(GameFonts::font_songtitle) });
	lassebq_callr("string_width", { ss.str() });
	double w = Result.asReal();
	lassebq_callr("string_height", { ss.str() });
	double h = Result.asReal();
	lassebq_callr("draw_set_color", { 8421376.0 });
	lassebq_callr("draw_set_alpha", { 0.9 });
	lassebq_callr("draw_rectangle_color", { 64.0 - 2.0, 64.0 - 2.0, 64.0 + w + 2.0, 64.0 + h + 2.0, 0.0, 0.0, 0.0, 0.0, 0.0 });
	lassebq_callr("draw_set_alpha", { 1.0 });
	lassebq_callr("draw_text", { 64.0, 64.0, ss.str() });
}

void allocConsoleQuick()
{
	FILE *__fDummy;
	BOOL bResult;

	bResult = AllocConsole();

	if (bResult == TRUE)
	{
		_wfreopen_s(&__fDummy, L"CONIN$", L"r", stdin);
		_wfreopen_s(&__fDummy, L"CONOUT$", L"w", stderr);
		_wfreopen_s(&__fDummy, L"CONOUT$", L"w", stdout);
		//SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleTitle(TEXT("a cat in need is a cat indeed."));
	}
}

typedef CEvent*(__thiscall *GetEvRecurs)(CObjectGM* self, int etype, int esubtype);
typedef void(__thiscall *InsertEv)(CHashMap<unsigned long long, CEvent*, 3> *self, unsigned long long _key, CEvent* _value);
GetEvRecurs GetEventRecursive = nullptr;
InsertEv InsertEvent = nullptr;

CObjectGM *lassebq_find_obj(int obj_index)
{
	HashNode<CObjectGM> *oNode = (*g_ObjectHashTable)->m_pHashingTable[(*g_ObjectHashTable)->m_HashingMask & obj_index].m_pFirst;
	for (;;) {
		if (oNode == nullptr) // eh? doesn't exist?
			abort();
		if (oNode->m_ID == obj_index) break; // found it in O(1) yay
		oNode = oNode->m_pNext; // eh? can't find it in O(1)???
	}
	if (oNode == nullptr) abort(); // eh? wtf? shouldn't happen?

	return oNode->m_pObj;
}

CCode* lassebq_fake_CCode(GML_ObjectEvent evFunc, const char* evName)
{
	CCode* code = new CCode();
	code->i_kind = 1;
	code->i_str = "";
	code->i_value = 0.0;
	code->i_pVM = nullptr;
	code->i_pVMDebugInfo = nullptr;
	code->i_compiled = true;
	code->i_pCode = "";
	code->i_pName = const_cast<char*>(evName);
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

unsigned long long lassebq_evKey(int etype, int esubtype)
{
	return static_cast<unsigned long long>(static_cast<long long>(esubtype) | (static_cast<long long>(etype) << 0x20ll));
}

void lassebq_addEvent(CObjectGM* gmObj, int etype, int esubtype, const char* name, GML_ObjectEvent evt)
{
	unsigned long long key = lassebq_evKey(etype, esubtype);
	CCode* code = lassebq_fake_CCode(evt, name);
	CEvent* ev = lassebq_fake_CEvent(gmObj->m_ID, code);
	InsertEvent(gmObj->m_eventsMap, key, ev);
}

void lassebq_patchObject(CObjectGM* gmObj)
{
	std::cout << "Trying to patch lassebq obj..." << std::endl;

	lassebq_addEvent(gmObj, 0, 0, "libLassebq_Create", lassebq_Create_GMLRoutine);
	lassebq_addEvent(gmObj, 3, 0, "libLassebq_Step", lassebq_Step_GMLRoutine);
	lassebq_addEvent(gmObj, 8, 64, "libLassebq_DrawGUI", lassebq_DrawGUI_GMLRoutine);

	std::cout << "Trying to patch obj_player..." << std::endl;
	CObjectGM* obj_player = lassebq_find_obj(EtoI(GameObjects::obj_player));
	lassebq_addEvent(obj_player, 8, 64, "libLassebq_Player_DrawGUI", lassebq_playerGUI_GMLRoutine);

	std::cout << "Done! Did it work? :)" << std::endl;
}

CObjectGM* lassebq_make_obj_liblassebq()
{
	//lassebq_dbg();
	lassebq_callr("object_add");
	int obj_index = Result.asInt32();
	std::cout << "LibLassebq object index " << obj_index << std::endl;

	// find our object.
	CObjectGM *oNode = lassebq_find_obj(obj_index);
	
	// mark as persistent.
	lassebq_callr("object_set_persistent", { obj_index, 1.0 });

	// Since Run_Room is NULL, we're not actually in any room just yet
	// WHICH MEANS, WE CAN DO THIS:
	lassebq_callr("room_instance_add", { EtoD(GameRooms::room_init), 0.0, 0.0, obj_index });
	g_LLBQObject = obj_index;
	// room_instance_add our object at position 0;0

	return oNode; // return our object so we can patch events :D
}

void lassebq_initYYC()
{
	allocConsoleQuick();

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
	g_ObjectHasEvent = reinterpret_cast<DynamicArrayOfInteger*>(exeAsUint + Object_Has_Event_Addr);
	g_ObjectNumEvent = reinterpret_cast<int*>(exeAsUint + Object_Num_Event_Addr);
	FREE_RValue__Pre = reinterpret_cast<FREE_RVal_Pre>(exeAsUint + FREE_RValue__Pre_Addr);
	YYSetString = reinterpret_cast<YYSetStr>(exeAsUint + YYSetString_Addr);
	YYCreateString = reinterpret_cast<YYCreStr>(exeAsUint + YYCreateString_Addr);
	InternalGetYYVarRef = reinterpret_cast<GetYYVRef>(exeAsUint + GetYYVarRef_Addr);
	g_Self = nullptr;
	SYYStackTrace::s_pStart = reinterpret_cast<SYYStackTrace**>(exeAsUint + YYSTraceStart_Addr);

	GetContextStackTop = reinterpret_cast<GetCtxStackTop>(exeAsUint + GetCtxStackTop_Addr);
	DeterminePotentialRoot = reinterpret_cast<DetPotRoot>(exeAsUint + DeterminePotRoot_Addr);
	GetEventRecursive = reinterpret_cast<GetEvRecurs>(exeAsUint + GetEvRecursive_Addr);
	InsertEvent = reinterpret_cast<InsertEv>(exeAsUint + InsertEvent_Addr);
	MMSetLength = reinterpret_cast<GMMMSetLength>(exeAsUint + GMMMSetLength_Addr);
	Variable_GetValue_Direct = reinterpret_cast<VarGetValDirect>(exeAsUint + VarGetValueDirect_Addr);
	FindRValueSlot = reinterpret_cast<FindRValSlot>(exeAsUint + FindRValueSlot_Addr);

	for (int i = 0; i < *g_RFunctionTableLen; i++)
	{
		RFunction* RFunc = &(*g_RFunctionTable)[i];
		fR[RFunc->f_name] = i;
	}

	lassebq_callr("window_handle");
	g_YYGMWindowHWND = reinterpret_cast<HWND>(Result.ptr);

	lassebq_patchObject(lassebq_make_obj_liblassebq());
}

void lassebq_print_global_rvars(std::ostream& oS)
{
	lassebq_callr("variable_instance_get_names", { -5.0 });
	RValue arr(Result);

	oS << "-------------------------------" << std::endl;
	if (arr.pRefArray->pArray == nullptr)
	{
		oS << "No RValues!" << std::endl;
	}
	else
	{
		int arrlen = arr.pRefArray->pArray->length;

		for (int i = 0; i < arrlen; i++)
		{
			const std::string varName = arr[i].asString();
			oS << varName << " = ";
			lassebq_callr("variable_global_get", { varName });
			oS << Result.asString() << std::endl;
		}
	}
	oS << "-------------------------------" << std::endl;
}

void lassebq_print_instance_rvars(int instid, std::ostream& oS)
{
	CRoom* curRoom = *g_RunRoom;
	CInstance* inst = curRoom->m_Active.m_pFirst;
	while (inst != nullptr)
	{
		if (inst->i_id == instid) break;
		inst = inst->m_pNext;
	}

	if (inst == nullptr)
	{
		std::cout << "INSTANCE DOES NOT EXIST!" << std::endl;
		return;
	}

	oS << "-------------------------------" << std::endl;
	// very slow :/
	RValue arr(0.0);
	int variable_instance_get_names = fR["variable_instance_get_names"];
	int variable_instance_get = fR["variable_instance_get"];
	CallRFunction(variable_instance_get_names, arr, { instid });

	if (arr.pRefArray->pArray == nullptr)
	{
		std::cout << "No RValues!" << std::endl;
	}
	else
	{
		int arrlen = arr.pRefArray->pArray->length;

		for (int i = 0; i < arrlen; i++)
		{
			const std::string varName = arr[i].asString();
			oS << varName << " = ";
			lassebq_callr("variable_instance_get", { instid, varName });
			oS << Result.asString() << std::endl;
		}
	}

	oS << "-------------------------------" << std::endl;
}

void lassebq_print_instance_vars(int instid, std::ostream& oS)
{
	CRoom* curRoom = *g_RunRoom;
	CInstance* inst = curRoom->m_Active.m_pFirst;
	while (inst != nullptr)
	{
		if (inst->i_id == instid) break;
		inst = inst->m_pNext;
	}

	if (inst == nullptr)
	{
		std::cout << "INSTANCE DOES NOT EXIST!" << std::endl;
		return;
	}

	oS << "-------------------------------" << std::endl;
	PRINT_VAR(inst, id);
	PRINT_VAR(inst, object_index);
	PRINT_VAR(inst, sprite_index);
	PRINT_VAR(inst, image_index);
	PRINT_VAR(inst, image_speed);
	PRINT_VAR(inst, image_scalex);
	PRINT_VAR(inst, image_scaley);
	PRINT_VAR(inst, image_angle);
	PRINT_VAR(inst, image_alpha);
	PRINT_VAR(inst, image_blend);
	PRINT_VAR(inst, x);
	PRINT_VAR(inst, y);
	PRINT_VAR(inst, xstart);
	PRINT_VAR(inst, ystart);
	PRINT_VAR(inst, xprevious);
	PRINT_VAR(inst, yprevious);
	PRINT_VAR(inst, direction);
	PRINT_VAR(inst, speed);
	PRINT_VAR(inst, friction);
	PRINT_VAR(inst, gravity_direction);
	PRINT_VAR(inst, gravity);
	PRINT_VAR(inst, hspeed);
	PRINT_VAR(inst, vspeed);
	oS << "bbox_left = " << inst->i_bbox.bbox_left << std::endl;
	oS << "bbox_top = " << inst->i_bbox.bbox_top << std::endl;
	oS << "bbox_right = " << inst->i_bbox.bbox_right << std::endl;
	oS << "bbox_bottom = " << inst->i_bbox.bbox_bottom << std::endl;

	for (int i = 0; i < sizeof(inst->i_timer) / sizeof(*inst->i_timer); i++)
	{
		oS << "alarm[" << i << "] = " << inst->i_timer[i] << std::endl;
	}

	if (inst->m_pPathAndTimeline != nullptr)
	{
		PRINT_VAR(inst->m_pPathAndTimeline, path_index);
		PRINT_VAR(inst->m_pPathAndTimeline, path_position);
		PRINT_VAR(inst->m_pPathAndTimeline, path_positionprevious);
		PRINT_VAR(inst->m_pPathAndTimeline, path_speed);
		PRINT_VAR(inst->m_pPathAndTimeline, path_scale);
		PRINT_VAR(inst->m_pPathAndTimeline, path_orientation);
		PRINT_VAR(inst->m_pPathAndTimeline, path_end);
		PRINT_VAR(inst->m_pPathAndTimeline, path_xstart);
		PRINT_VAR(inst->m_pPathAndTimeline, path_ystart);
		PRINT_VAR(inst->m_pPathAndTimeline, timeline_index);
		PRINT_VAR(inst->m_pPathAndTimeline, timeline_prevposition);
		PRINT_VAR(inst->m_pPathAndTimeline, timeline_position);
		PRINT_VAR(inst->m_pPathAndTimeline, timeline_speed);
	}
	else
	{
		oS << "[ path_* and timeline_* variables are unset!!! ]" << std::endl;
	}

	PRINT_VAR(inst, layer);
	PRINT_VAR(inst, mask_index);
	PRINT_VAR(inst, nMouseOver);
	PRINT_VAR(inst, depth);
	PRINT_VAR(inst, currentdepth);
	PRINT_VAR(inst, lastImageNumber);
	PRINT_VAR(inst, collisionTestNumber);
	oS << "-------------------------------" << std::endl;
}

void lassebq_print_instances(std::ostream& oS)
{
	CRoom* curRoom = *g_RunRoom;
	CInstance* inst = curRoom->m_Active.m_pFirst;
	oS << "-------------------------------" << std::endl;
	while (inst != nullptr)
	{
		oS << inst->i_id << " " << inst->m_pObject->m_pName << std::endl;
		inst = inst->m_pNext;
	}
	oS << "-------------------------------" << std::endl;
}

void lassebq_wrong_args()
{
	std::cout << "Invalid arguments." << std::endl;
}

LPSTR lassebq_WtoM(const std::wstring& wstr) {
	int size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	LPSTR str = new CHAR[size];
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, str, size, nullptr, nullptr);
	return str;
}

DWORD WINAPI lassebq_cli(LPVOID lpThreadParameter)
{
	std::cout << "CLI Thread is working..." << std::endl;
	std::cout << "Base address: " << exeBase << std::endl;
	std::cout << "Variables: " << g_VariablesSize << std::endl;
	std::cout << "Scripts: " << g_GMLScriptsSize << std::endl;
	std::cout << "Window handle: " << g_YYGMWindowHWND << std::endl;
	std::cout << std::endl;
	std::cout << "CreateDsMap: " << ds_map_create << std::endl;
	std::cout << "DsMapAddDouble: " << ds_map_add_real << std::endl;
	std::cout << "DsMapAddString: " << ds_map_add_string << std::endl;
	std::cout << "CreateAsyncEvent: " << create_async_event << std::endl;
	std::cout << std::endl;
	std::cout << "Init done, type funny commands, get funny responses (or Access Violations)..." << std::endl;

	std::string cmd;
	std::wstring fname(L"out.log");
	bool useStdcout = true;

	for (;;)
	{
		std::cout << PROMPT;
		std::getline(std::cin, cmd);
		if (cmd.length() == 0 || cmd.at(0) == ' ') continue;

		// convert UTF_8 string to wide.
		int bufSize = MultiByteToWideChar(GetConsoleCP(), MB_PRECOMPOSED, cmd.c_str(), -1, nullptr, 0);
		LPWSTR buf = new WCHAR[bufSize];
		MultiByteToWideChar(GetConsoleCP(), MB_PRECOMPOSED, cmd.c_str(), -1, buf, bufSize);

		// parse the arguments and convert them into a vector of arguments.
		int cmd_argc = 0;
		LPWSTR* winapi_argv = CommandLineToArgvW(buf, &cmd_argc);
		std::vector<std::wstring> cmd_argv;
		for (int i = 0; i < cmd_argc; i++)
		{
			cmd_argv.push_back(winapi_argv[i]);
		}

		// free the winapi stuff.
		LocalFree(winapi_argv);
		winapi_argv = nullptr;
		delete[] buf;
		buf = nullptr;
		bufSize = 0;

		// finally.
		if (cmd_argv[0] == L"list-instances")
		{
			if (useStdcout)
				lassebq_print_instances(std::cout);
			else
			{
				std::ofstream fS(fname, std::ofstream::out | std::ofstream::app);
				lassebq_print_instances(fS);
				fS.close();
			}
		}
		else if (cmd_argv[0] == L"set-cout-mode")
		{
			if (cmd_argv.size() <= 1)
			{
				useStdcout = true;
				std::cout << "Output mode: console" << std::endl;
			}
			else
			{
				useStdcout = false;
				fname = cmd_argv[1];
				std::cout << "Output mode: file" << std::endl;
			}
		}
		else if (cmd_argv[0] == L"list-global-vars")
		{
			if (useStdcout)
				lassebq_print_global_rvars(std::cout);
			else
			{
				std::ofstream fS(fname, std::ofstream::out | std::ofstream::app);
				lassebq_print_global_rvars(fS);
				fS.close();
			}
		}
		else if (cmd_argv[0] == L"list-instance-vars")
		{
			if (cmd_argv.size() < 2)
			{
				lassebq_wrong_args();
				continue;
			}

			try {
				int instid = std::stoi(cmd_argv[1]);
				if (useStdcout)
					lassebq_print_instance_vars(instid, std::cout);
				else
				{
					std::ofstream fS(fname, std::ofstream::out | std::ofstream::app);
					lassebq_print_instance_vars(instid, fS);
					fS.close();
				}
			}
			catch (std::exception&) {
				lassebq_wrong_args();
			}
		}
		else if (cmd_argv[0] == L"list-instance-rvars")
		{
			if (cmd_argv.size() < 2)
			{
				lassebq_wrong_args();
				continue;
			}

			try {
				int instid = std::stoi(cmd_argv[1]);
				// VERY SLOW!
				if (useStdcout)
					lassebq_print_instance_rvars(instid, std::cout);
				else
				{
					std::ofstream fS(fname, std::ofstream::out | std::ofstream::app);
					lassebq_print_instance_rvars(instid, fS);
					fS.close();
				}
			}
			catch (std::exception&) {
				lassebq_wrong_args();
			}
		}
		else if (cmd_argv[0] == L"calls")
		{
			if (cmd_argv.size() < 2)
			{
				lassebq_wrong_args();
				continue;
			}

			try {
				LPSTR fName = lassebq_WtoM(cmd_argv[1]);

				// prepare arguments.
				RValueList args;

				for (size_t i = 2; i < cmd_argv.size(); i++) {
					if (cmd_argv[i].at(0) == L'@') {
						std::wstring noAt = cmd_argv[i].substr(1);
						double vv = std::stod(noAt);
						args.push_back(vv);
					}
					else {
						args.push_back(cmd_argv[i]);
					}
				}
				
				// do the call
				lassebq_calls(fName, false, args);
				delete[] fName;

				std::cout << "Return value: " << Result.asString() << std::endl;
			}
			catch (std::exception&) {
				lassebq_wrong_args();
			}
		}
		else if (cmd_argv[0] == L"callr")
		{
			if (cmd_argv.size() < 2)
			{
				lassebq_wrong_args();
				continue;
			}

			try {
				LPSTR fName = lassebq_WtoM(cmd_argv[1]);

				// prepare arguments.
				RValueList args;

				for (size_t i = 2; i < cmd_argv.size(); i++) {
					if (cmd_argv[i].at(0) == L'@') {
						std::wstring noAt = cmd_argv[i].substr(1);
						double vv = std::stod(noAt);
						args.push_back(vv);
					}
					else {
						args.push_back(cmd_argv[i]);
					}
				}

				// do the call
				lassebq_callr(fName, args);
				delete[] fName;

				std::cout << "Return value: " << Result.asString() << std::endl;
			}
			catch (std::exception&) {
				lassebq_wrong_args();
			}
		}
		else if (cmd_argv[0] == L"callo")
		{
			if (cmd_argv.size() < 2)
			{
				lassebq_wrong_args();
				continue;
			}

			try {
				LPSTR fName = lassebq_WtoM(cmd_argv[1]);

				// do the call
				lassebq_calls(fName, true);
				delete[] fName;

				std::cout << "Called!" << std::endl;
			}
			catch (std::exception&) {
				lassebq_wrong_args();
			}
		}
		else if (cmd_argv[0] == L"set-var")
		{
			if (cmd_argv.size() < 4)
			{
				lassebq_wrong_args();
				continue;
			}

			try {
				int instid = std::stoi(cmd_argv[1]);
				RValueList args;
				args.emplace_back(instid);
				args.emplace_back(cmd_argv[2]);

				if (cmd_argv[3].at(0) == L'@')
				{
					std::wstring noAt = cmd_argv[3].substr(1);
					double vv = std::stod(noAt);
					args.emplace_back(vv);
				}
				else
				{
					args.emplace_back(cmd_argv[3]);
				}

				lassebq_callr("variable_instance_set", args);

				std::cout << "Set!" << std::endl;
			}
			catch (std::exception& exc) {
				std::cout << exc.what() << std::endl;
				lassebq_wrong_args();
			}
		}
		else if (cmd_argv[0] == L"set-global-var")
		{
			if (cmd_argv.size() < 3)
			{
				lassebq_wrong_args();
				continue;
			}

			try {
				RValueList args;
				args.emplace_back(cmd_argv[1]);

				if (cmd_argv[2].at(0) == L'@')
				{
					std::wstring noAt = cmd_argv[2].substr(1);
					double vv = std::stod(noAt);
					args.emplace_back(vv);
				}
				else
				{
					args.emplace_back(cmd_argv[2]);
				}

				lassebq_callr("variable_global_set", args);

				std::cout << "Set!" << std::endl;
			}
			catch (std::exception& exc) {
				std::cout << exc.what() << std::endl;
				lassebq_wrong_args();
			}
		}
		else if (cmd_argv[0] == L"cls")
		{
			clearConsole();
		}
		else if (cmd_argv[0] == L"test")
		{
			YYVAR* vv = g_Variables[0xb19];
			std::cout << "VARNAME: " << vv->pName << std::endl;
			std::cout << "PTR: " << vv->val << std::endl;
		}
	}

	return 0;
}

funcR lassebq_init()
{
	return 1.0;
}

funcR lassebq_shutdown()
{
	return 1.0;
}

funcV RegisterCallbacks(GML_create_async_event cae, GML_ds_map_create dmc, GML_ds_map_add_real dmar, GML_ds_map_add_string dmas)
{
	// set our callback stuff...
	create_async_event = cae;
	ds_map_create = dmc;
	ds_map_add_real = dmar;
	ds_map_add_string = dmas;

	// do the job.
	lassebq_initYYC();

	// we need a *large* stack (around 2-4 megs) because of GML arg stack stuff...
	DWORD threadId;
	CreateThread(nullptr, 0x00400000, lassebq_cli, nullptr, 0, &threadId);
}