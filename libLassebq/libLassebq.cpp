// libLassebq.cpp: определяет экспортированные функции для приложения DLL.
//

#include "libLassebq.h"
#include "KatanaZero.h"
#include "KatanaZeroIDs.h"
#include <WinCon.h>
#include <fstream>
#include <shellapi.h>

#define PROMPT "> "
#define PRINT_VAR(cl,n) oS << #n << " = " << cl->i_##n << std::endl
#define R(RV) (std::make_unique<RValue>((RV)))


HMODULE exeBase = nullptr;
YYVAR** g_BuiltinFuncs;
YYVAR** g_Variables;
YYGMLFunc* g_GMLScripts;
CRoom** g_RunRoom;
RFunction** g_RFunctionTable;
CHash<CObjectGM>** g_ObjectHashTable;
DynamicArrayOfInteger* g_ObjectHasEvent;
int* g_ObjectNumEvent;
int* g_RFunctionTableLen;
CInstance* g_Self;
const char** g_WorkingDirectory;
int g_BuiltinFuncSize;
int g_GMLScriptsSize;
int g_VariablesSize;
int* g_CurrentRoom;
FREE_RVal_Pre FREE_RValue__Pre;
YYSetStr YYSetString;
HWND g_YYGMWindowHWND;

// RegisterCallback stuff
GML_ds_map_create ds_map_create = nullptr;
GML_ds_map_add_real ds_map_add_real = nullptr;
GML_ds_map_add_string ds_map_add_string = nullptr;
GML_create_async_event create_async_event = nullptr;

RValue Result(0.0);

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

int lassebq_find_builtin(const char* name)
{
	for (int i = 0; i < g_BuiltinFuncSize; i++)
	{
		if (strcmp(name, g_BuiltinFuncs[i]->pName) == 0)
		{
			return i;
		}
	}

	return -1;
}

int lassebq_find_runtime(const char* name)
{
	for (int i = 0; i < *g_RFunctionTableLen; i++)
	{
		if (strcmp(name, (*g_RFunctionTable)[i].f_name) == 0)
		{
			return i;
		}
	}

	return -1;
}

int lassebq_find_variable(const char* name)
{
	for (int i = 0; i < g_VariablesSize; i++)
	{
		if (strcmp(name, g_Variables[i]->pName) == 0)
		{
			return i;
		}
	}

	return -1;
}

int lassebq_find_script(const char* name)
{
	for (int i = 0; i < g_GMLScriptsSize; i++)
	{
		if (strcmp(name, g_GMLScripts[i].pName) == 0)
		{
			return i;
		}
	}

	return -1;
}

const char* lassebq_get_working_directory()
{
	return *g_WorkingDirectory;
}

int lassebq_get_current_room()
{
	return *g_CurrentRoom;
}

void lassebq_dbg()
{
	std::cout << "Waiting for Visual Studio's debugger..." << std::endl;
	while (IsDebuggerPresent() == FALSE) Sleep(100);
}

void lassebq_callb(int id, const RValueList& args = { })
{
	lassebq_free_result();
	CallGMLFunction(id, Result, args);
}

void lassebq_callr(int id, const RValueList& args = { })
{
	lassebq_free_result();
	CallRFunction(id, Result, args);
}

void lassebq_calls(int id, bool isObjectEvent, const RValueList& args = { })
{
	lassebq_free_result();
	CallScriptFunction(id, Result, args, isObjectEvent);
}

void lassebq_Step_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	// a box that contains one "OK" button and an "Info" icon.
	MessageBox(g_YYGMWindowHWND, TEXT("This is the text."), TEXT("Caption."), MB_OK | MB_ICONINFORMATION);

	int keyboard_check_pressed = lassebq_find_builtin("keyboard_check_pressed");
	RValue key(VK_F2);

	// fun fact: vk_* constants in GM match up with Windows's WinAPI VK_* constants 99.99% of the time :)
	lassebq_callb(keyboard_check_pressed, { key });

	std::cout << "yes!!!" << std::endl;

	// GameMaker's boolean rule: val > 0.5 -> true, else false
	if (Result.asReal() > 0.5)
	{
		int prikol = rand() % keyboard_check_pressed;

		// didn't implement YYStrBuilder cuz too lazy to do SHIT.
		char buf[64] = { '\0' };
		memset(buf, 0, sizeof(buf));
		std::snprintf(buf, sizeof(buf), "giving %d hugs to lassebq", prikol);

		// reminder: don't do this.
		RValue my_caption(reinterpret_cast<const char*>(&buf));

		// it's probably not in the builtin table, use the RFunction table instead :/
		int window_set_caption = lassebq_find_runtime("window_set_caption");
		lassebq_callr(window_set_caption, { my_caption });
	}
}

void lassebq_DrawGUI_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	// TODO: somehow cache function handles?
	int draw_text = lassebq_find_runtime("draw_text");
	int draw_set_font = lassebq_find_runtime("draw_set_font");
	int draw_set_color = lassebq_find_runtime("draw_set_color");

	RValue text_x(128.0);
	RValue text_y(128.0);
	RValue text_string("If Grossley's so good, why there's no Grossley 2????");
	RValue text_color(16777215.0); // c_white
	RValue text_font(EtoD(GameFonts::font_folderbold));

								   // don forget
	g_Self = _pSelf;

	// set draw settings.
	lassebq_callr(draw_set_font, { text_font });
	lassebq_callr(draw_set_color, { text_color });

	// lel.
	lassebq_callr(draw_text, { text_x, text_y, text_string });
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

void lassebq_patchObject()
{
	std::cout << "Trying to patch obj_texture_page_master..." << std::endl;

	const int obj_index = EtoI(GameObjects::obj_texture_page_master);

	// find our object.
	HashNode<CObjectGM> *oNode = (*g_ObjectHashTable)->m_pHashingTable[(*g_ObjectHashTable)->m_HashingMask & obj_index].m_pFirst;
	for (;;) {
		if (oNode == nullptr) // eh? doesn't exist?
			abort();
		if (oNode->m_ID == obj_index) break; // found it in O(1) yay
		oNode = oNode->m_pNext; // eh? can't find it in O(1)???
	}
	if (oNode == nullptr) abort(); // eh? wtf? shouldn't happen?

								   // got it.
	auto *evMap = oNode->m_pObj->m_eventsMap;
	auto *evEle = evMap->m_elements;
	GML_ObjectEvent nikStep = lassebq_Step_GMLRoutine;
	GML_ObjectEvent nikDrawGUI = lassebq_DrawGUI_GMLRoutine;

	CCode* nikStepCode = new CCode();
	nikStepCode->i_kind = 1;
	nikStepCode->i_str = nullptr;
	nikStepCode->i_value = 0.0;
	nikStepCode->i_pVM = nullptr;
	nikStepCode->i_pVMDebugInfo = nullptr;
	nikStepCode->i_compiled = true;
	nikStepCode->i_pCode = nullptr;
	nikStepCode->i_pName = "gml_Object_obj_texture_page_master_Step_0";
	nikStepCode->i_CodeIndex = 1337;
	nikStepCode->i_pFunc = new YYGMLFunc();
	nikStepCode->i_pFunc->pName = nikStepCode->i_pName;
	nikStepCode->i_pFunc->ptr = nikStep;
	nikStepCode->i_watch = false;
	nikStepCode->i_offset = 0;
	nikStepCode->i_locals = 0;
	nikStepCode->i_args = 0;
	nikStepCode->i_flags = 0;

	CCode* nikDrawGUICode = new CCode();
	nikStepCode->i_kind = 1;
	nikDrawGUICode->i_str = nullptr;
	nikDrawGUICode->i_value = 0.0;
	nikDrawGUICode->i_pVM = nullptr;
	nikDrawGUICode->i_pVMDebugInfo = nullptr;
	nikDrawGUICode->i_compiled = true;
	nikDrawGUICode->i_pCode = nullptr;
	nikDrawGUICode->i_pName = "gml_Object_obj_texture_page_master_Draw_64";
	nikDrawGUICode->i_CodeIndex = 1337;
	nikDrawGUICode->i_pFunc = new YYGMLFunc();
	nikDrawGUICode->i_pFunc->pName = nikDrawGUICode->i_pName;
	nikDrawGUICode->i_pFunc->ptr = nikDrawGUI;
	nikDrawGUICode->i_watch = false;
	nikDrawGUICode->i_offset = 0;
	nikDrawGUICode->i_locals = 0;
	nikDrawGUICode->i_args = 0;
	nikDrawGUICode->i_flags = 0;

	nikStepCode->m_pNext = nikDrawGUICode;
	nikDrawGUICode->m_pNext = nullptr;

	CEvent* nikStepEvent = new CEvent();
	nikStepEvent->m_OwnerObjectID = EtoI(GameObjects::obj_texture_page_master);
	nikStepEvent->e_code = nikStepCode;

	CEvent* nikDrawGUIEvent = new CEvent();
	nikDrawGUIEvent->m_OwnerObjectID = EtoI(GameObjects::obj_texture_page_master);
	nikDrawGUIEvent->e_code = nikDrawGUICode;


	std::cout << "Fake CEvent/CCode constructed, traversing thru eventmap..." << std::endl;
	// (subtype) | (type) << 32ull
	// looked at an actual step event object, k=0,h=3 wtf?!
	const unsigned long long stepKey = 0;
	// ((key) * hashMagic >> 32ull) + 1u & int32_max
	const Hash stepHash = 3;

	const unsigned long long drawGUIKey = 64ll | 8ull << 0x20;
	const Hash drawGUIHash = static_cast<Hash>(drawGUIKey * 0x9E3779B97F4A7C55ull >> 0x20) + 1u & 0x7fffffffu;

	Hash stepMaskedHash = evMap->m_curMask & stepHash;
	Hash drawGUIMaskedHash = evMap->m_curMask & drawGUIHash;

	evEle[drawGUIMaskedHash].hash = drawGUIHash;
	evEle[drawGUIMaskedHash].k = drawGUIKey;
	evEle[drawGUIMaskedHash].v = nikDrawGUIEvent;

	evEle[stepMaskedHash].hash = stepHash;
	evEle[stepMaskedHash].k = stepKey;
	evEle[stepMaskedHash].v = nikStepEvent;

	evMap->m_numUsed += 1; // we added elements, should mark that.
	
	std::cout << "Patching hasevent table..." << std::endl;
	int hLen;
	int* hPtr;

	// step
	DynamicArrayOfInteger table[15][256];
	int numtable[15][256];
	memcpy(table, g_ObjectHasEvent, sizeof(table));
	memcpy(numtable, g_ObjectNumEvent, sizeof(numtable));

	hLen = table[3][0].length;
	hPtr = table[3][0].arr;
	for (int i = 0; i < hLen; i++)
	{
		if (hPtr[i] == 0)
		{
			std::cout << "found where to patch!" << std::endl;
			hPtr[i] = obj_index;
			break;
		}
	}
	numtable[3][0]++;
	//lassebq_dbg();

	//drawgui
	hLen = table[8][64].length;
	hPtr = table[8][64].arr;
	for (int i = 0; i < hLen; i++)
	{
		std::cout << "drawguiobj " << i << " " << hPtr[i] << std::endl;
		if (hPtr[i] == 0)
		{
			hPtr[i] = obj_index;
			break;
		}
	}
	numtable[8][64]++;
	

	memcpy(g_ObjectHasEvent, table, sizeof(table));
	memcpy(g_ObjectNumEvent, numtable, sizeof(numtable));

	std::cout << "Done!" << std::endl;
}

void lassebq_initYYC()
{
	allocConsoleQuick();

	exeBase = GetModuleHandleW(nullptr);
	uintptr_t exeAsUint = reinterpret_cast<uintptr_t>(exeBase);

	g_BuiltinFuncs = reinterpret_cast<YYVAR**>(exeAsUint + Builtin_Addr);
	for (int i = 0; true; i++)
	{
		if (g_BuiltinFuncs[i] == nullptr)
		{
			g_BuiltinFuncSize = i;
			break;
		}
	}

	g_Variables = reinterpret_cast<YYVAR**>(exeAsUint + Variable_Addr);
	for (int i = 0; true; i++)
	{
		if (g_Variables[i] == nullptr)
		{
			g_VariablesSize = i;
			break;
		}
	}

	g_GMLScripts = reinterpret_cast<YYGMLFunc*>(exeAsUint + GMLScript_Addr);
	for (int i = 0; true; i++)
	{
		if (g_GMLScripts[i].pName == nullptr || g_GMLScripts[i].ptr == nullptr)
		{
			g_GMLScriptsSize = i;
			break;
		}
	}

	g_RunRoom = reinterpret_cast<CRoom**>(exeAsUint + Run_Room_Addr);
	g_CurrentRoom = reinterpret_cast<int*>(exeAsUint + Current_Room_Addr);
	g_RFunctionTableLen = reinterpret_cast<int*>(exeAsUint + RFunctionTableL_Addr);
	g_RFunctionTable = reinterpret_cast<RFunction**>(exeAsUint + RFunctionTable_Addr);
	g_ObjectHashTable = reinterpret_cast<CHash<CObjectGM>**>(exeAsUint + Object_Hash_Addr);
	g_ObjectHasEvent = reinterpret_cast<DynamicArrayOfInteger*>(exeAsUint + Object_Has_Event_Addr);
	g_ObjectNumEvent = reinterpret_cast<int*>(exeAsUint + Object_Num_Event_Addr);
	FREE_RValue__Pre = reinterpret_cast<FREE_RVal_Pre>(exeAsUint + FREE_RValue__Pre_Addr);
	YYSetString = reinterpret_cast<YYSetStr>(exeAsUint + YYSetString_Addr);
	g_Self = nullptr;

	lassebq_callr(lassebq_find_runtime("window_handle"));
	g_YYGMWindowHWND = reinterpret_cast<HWND>(Result.ptr);
}

void lassebq_print_global_rvars(std::ostream& oS)
{
	RValue arr(0.0);
	int variable_instance_get_names = lassebq_find_runtime("variable_instance_get_names");
	int variable_global_get = lassebq_find_runtime("variable_global_get");
	CallRFunction(variable_instance_get_names, arr, { -5.0 });

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
			lassebq_callr(variable_global_get, { varName });
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
	int variable_instance_get_names = lassebq_find_runtime("variable_instance_get_names");
	int variable_instance_get = lassebq_find_runtime("variable_instance_get");
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
			lassebq_callr(variable_instance_get, { instid, varName });
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
	std::cout << "Builtin functions: " << g_BuiltinFuncSize << std::endl;
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
	bool useStdcout;

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
				int func = lassebq_find_script(fName);

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
				lassebq_calls(func, false, args);

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
				int func = lassebq_find_runtime(fName);

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
				lassebq_callr(func, args);

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
				int func = lassebq_find_script(fName);
				delete[] fName;
				fName = nullptr;

				// do the call
				lassebq_calls(func, true);

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
				std::string varname = lassebq_WtoM(cmd_argv[2]);
				RValueList args;

				if (cmd_argv[3].at(0) == L'@')
				{
					std::wstring noAt = cmd_argv[3].substr(1);
					double vv = std::stod(noAt);
					args.emplace_back(new RValue(vv));
				}
				else
				{
					args.emplace_back(new RValue(cmd_argv[3]));
				}

				int variable_instance_set = lassebq_find_runtime("variable_instance_set");
				lassebq_callr(variable_instance_set, args);

				std::cout << "Set!" << std::endl;
			}
			catch (std::exception&) {
				lassebq_wrong_args();
			}
		}
		else if (cmd_argv[0] == L"cls")
		{
			clearConsole();
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
	CreateThread(nullptr, 0x00400000, lassebq_cli, nullptr, 0, nullptr);
}