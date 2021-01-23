// libLassebq.cpp: определяет экспортированные функции для приложения DLL.
//

#include "libLassebq.h"
#include "KatanaZero.h"
#include "KatanaZeroIDs.h"
#include <WinCon.h>
#include <fstream>

#define PROMPT "> "

HMODULE exeBase = nullptr;
YYVAR** g_BuiltinFuncs;
YYVAR** g_Variables;
YYGMLFunc* g_GMLScripts;
CRoom** g_RunRoom;
RFunction** g_RFunctionTable;
CHash<CObjectGM>** g_ObjectHashTable;
int* g_RFunctionTableLen;
CInstance* g_Self;
const char** g_WorkingDirectory;
const char** g_GameName;
const char** g_CommandLine;
int g_BuiltinFuncSize;
int g_GMLScriptsSize;
int g_VariablesSize;
int* g_CurrentRoom;
GML_CallLegacyFunction call;

// RegisterCallback stuff
GML_ds_map_create ds_map_create = nullptr;
GML_ds_map_add_real ds_map_add_real = nullptr;
GML_ds_map_add_string ds_map_add_string = nullptr;
GML_create_async_event create_async_event = nullptr;

RValue Result(0.0);

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

const char* lassebq_get_game_name()
{
	return *g_GameName;
}

const char* lassebq_get_command_line()
{
	return *g_CommandLine;
}

int lassebq_get_current_room()
{
	return *g_CurrentRoom;
}

void lassebq_callb(int id, const std::list<RValue>& args = { })
{
	CallGMLFunction(id, Result, args);
}

void lassebq_callr(int id, const std::list<RValue>& args = { })
{
	CallRFunction(id, Result, args);
}

void lassebq_calls(int id, const std::list<RValue>& args = { }, bool isObjectEvent = false)
{
	CallScriptFunction(id, Result, args, isObjectEvent);
}

void lassebq_Step_GMLRoutine(CInstance* _pSelf, CInstance* _pOther)
{
	int keyboard_check_pressed = lassebq_find_builtin("keyboard_check_pressed");

	// fun fact: vk_* constants in GM match up with Windows's WinAPI VK_* constants 99.99% of the time :)
	lassebq_callb(keyboard_check_pressed, { VK_F2 });

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

								   // don forget
	g_Self = _pSelf;

	// set draw settings.
	lassebq_callr(draw_set_font, { EtoD(GameFonts::font_folderbold) });
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
		SetConsoleTitle(TEXT("a cat in need is a cat indeed."));
	}
}

DWORD WINAPI lassebq_cli(LPVOID lpThreadParameter)
{
	allocConsoleQuick();

	std::cout << "libLassebq is loading for game " << PROJECT_NAME << std::endl;

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
		if (g_GMLScripts[i].pName == nullptr)
		{
			g_GMLScriptsSize = i;
			break;
		}
	}

	g_WorkingDirectory = reinterpret_cast<const char**>(exeAsUint + WorkingDirectory_Addr);
	g_GameName = reinterpret_cast<const char**>(exeAsUint + GameName_Addr);
	g_CommandLine = reinterpret_cast<const char**>(exeAsUint + CommandLine_Addr);
	g_RunRoom = reinterpret_cast<CRoom**>(exeAsUint + Run_Room_Addr);
	g_CurrentRoom = reinterpret_cast<int*>(exeAsUint + Current_Room_Addr);
	g_RFunctionTableLen = reinterpret_cast<int*>(exeAsUint + RFunctionTableL_Addr);
	g_RFunctionTable = reinterpret_cast<RFunction**>(exeAsUint + RFunctionTable_Addr);
	g_ObjectHashTable = reinterpret_cast<CHash<CObjectGM>**>(exeAsUint + Object_Hash_Addr);

	std::cout << "Thread is working..." << std::endl;
	std::cout << "Base address: " << exeBase << std::endl;
	std::cout << "Builtin functions: " << g_BuiltinFuncSize << std::endl;
	std::cout << "Variables: " << g_VariablesSize << std::endl;
	std::cout << "Scripts: " << g_GMLScriptsSize << std::endl;
	std::cout << "Working Directory: " << lassebq_get_working_directory() << std::endl;
	//std::cout << "Game Name: " << lassebq_get_game_name() << std::endl;
	//std::cout << "Command Line: " << lassebq_get_command_line() << std::endl;

	std::cout << std::endl;

	std::cout << "Init done, type funny commands, get funny responses (or Access Violations)..." << std::endl;

	std::string cmd;
	CInstance* inst_tpage_master = nullptr;

	for (;;)
	{
		std::cout << PROMPT;
		std::getline(std::cin, cmd);

		CRoom* room = *g_RunRoom;
		g_Self = room->m_Active.m_pFirst;

		if (cmd == "test")
		{
			int audio_stop_all = lassebq_find_builtin("audio_stop_all");
			int audio_play_sound = lassebq_find_builtin("audio_play_sound");
			lassebq_callb(audio_stop_all);
			lassebq_callb(audio_play_sound, { EtoD(GameSounds::song_youwillneverknow), 1, true });
			std::cout << "return: " << Result.asString() << std::endl;
		}
		else if (cmd == "gmltest")
		{
			const char* fname = "gml_Script_inside_camera";
			int func = lassebq_find_script(fname);
			std::cout << fname << ": " << func << std::endl;

			if (func == -1)
			{
				std::cout << "LOOKUP FAILED!" << std::endl;
			}
			else
			{
				// meh, try a single 1 as the argument :/
				lassebq_calls(func, { 1.0 }, false);
				std::cout << "Return: " << Result.asString() << std::endl;
			}
		}
		else if (cmd == "patchmaster")
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
			const unsigned long long stepKey = 0ull | 3ull << 32ull;
			// ((key) * hashMagic >> 32ull) + 1u & int32_max
			const Hash stepHash = (stepKey * 0x9E3779B97F4A7C55ull >> 32ull) + 1u & 0x7fffffffu;

			const unsigned long long drawGUIKey = 64ull | 8ull << 32ull;
			const Hash drawGUIHash = (drawGUIKey * 0x9E3779B97F4A7C55ull >> 32ull) + 1u & 0x7fffffffu;

			Hash stepMaskedHash = evMap->m_curMask & stepHash;
			Hash drawGUIMaskedHash = evMap->m_curMask & drawGUIHash;

			evEle[stepMaskedHash].hash = stepHash;
			evEle[stepMaskedHash].k = stepKey;
			evEle[stepMaskedHash].v = nikStepEvent;

			evEle[drawGUIMaskedHash].hash = drawGUIHash;
			evEle[drawGUIMaskedHash].k = drawGUIKey;
			evEle[drawGUIMaskedHash].v = nikDrawGUIEvent;

			evMap->m_numUsed += 2; // we added two elements, we should mark that.

			int event_perform = lassebq_find_runtime("event_perform");
			g_Self = inst_tpage_master;
			//lassebq_callr(event_perform, { 3, 0 });

			std::cout << "Done!" << std::endl;
		}
		else if (cmd == "2test")
		{
			// find obj_global_controller
			auto* inst_global_con = room->m_Active.m_pFirst;
			// iterate!
			while (inst_global_con->i_objectindex != EtoI(GameObjects::obj_hud))
				inst_global_con = inst_global_con->m_pNext;

			// we found obj_global_con instance, do funny things
			auto *evMap = inst_global_con->m_pObject->m_eventsMap;

			// TODO: fix CEvent, figure out how to set event kind.
			std::vector<Element<unsigned long long, CEvent*, 3>> elementVec;
			auto* evArray = evMap->m_elements;
			for (int i = 0; i < 30; i++)
			{
				//if (evArray[i].v == nullptr && evArray[i].hash == 0) break;
				elementVec.push_back(evArray[i]);
			}

			std::cout << "ok!" << std::endl;
		}
		else if (cmd == "dumpgml")
		{
			std::ofstream dfs("dump.txt", std::ofstream::out | std::ofstream::trunc);
			dfs << "_____________________________" << std::endl;
			dfs << "ADDRESS | YYC CODE ENTRY NAME" << std::endl;
			dfs << "________|____________________" << std::endl;
			for (int i = 0; true; i++)
			{
				YYGMLFunc f = g_GMLScripts[i];
				if (f.pName == nullptr || f.ptr == nullptr) break;
				std::string start = std::string(f.pName).substr(0, 4);
				if (start == "gml_" || start == "Time") // gml OR timeline.
				{
					dfs << reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(f.ptr) - exeAsUint) << "|" << f.pName << std::endl;
				}
				else break;
			}

			dfs.close();
		}
		else if (cmd == "room")
		{
			std::cout << "Current Room Index: " << lassebq_get_current_room() << std::endl;
		}
		else if (cmd == "cls")
		{
			clearConsole();
		}
		else if (cmd == "end")
		{
			int game_end = lassebq_find_runtime("game_end");
			lassebq_callr(game_end);
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

	// we need a *large* stack (around 2-4 megs) because of GML arg stack stuff...
	CreateThread(nullptr, 0x00400000, lassebq_cli, nullptr, 0, nullptr);
}