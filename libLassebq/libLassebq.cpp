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
RFunction* g_RFunctionTable;
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

RValue Result;

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

void lassebq_callb(int id, std::list<RValue> args)
{
	CallGMLFunction(id, Result, args);
}

void lassebq_calls(int id, std::list<RValue> args, bool isObjectEvent = false)
{
	CallScriptFunction(id, Result, args, isObjectEvent);
}

void allocConsoleQuick()
{
	FILE *__fDummy;
	BOOL bResult;

	bResult = AllocConsole();

	if (bResult == TRUE)
	{
		freopen_s(&__fDummy, "CONIN$", "r", stdin);
		freopen_s(&__fDummy, "CONOUT$", "w", stderr);
		freopen_s(&__fDummy, "CONOUT$", "w", stdout);
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
	g_RFunctionTable = *(reinterpret_cast<RFunction**>(exeAsUint + RFunctionTable_Addr));

	std::vector<RFunction> funcs;

	call = reinterpret_cast<GML_CallLegacyFunction>(CallBuiltin_Addr);

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

	for (;;)
	{
		std::string cmd;
		std::cout << PROMPT;
		std::getline(std::cin, cmd);

		CRoom* room = *g_RunRoom;
		g_Self = room->m_Active.m_pFirst;

		if (cmd == "test")
		{
			for (int i = 0; i < *g_RFunctionTableLen; i++)
			{
				funcs.push_back(g_RFunctionTable[i]);
			}

			const char* fname = "room_get_name";
			int func = lassebq_find_builtin(fname);
			std::cout << fname << ": " << func << std::endl;

			if (func != -1)
			{
				//lassebq_callb(func, { EtoI(GameSounds::song_youwillneverknow), 1, true });
				lassebq_callb(func, { 10 });
				std::cout << "Return value: " << Result.asString() << std::endl;
			}
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
		else if (cmd == "dumpgml")
		{
			std::ofstream dfs("dump.txt", std::ofstream::out | std::ofstream::trunc);
			for (int i = 0; true; i++)
			{
				YYGMLFunc f = g_GMLScripts[i];
				if (f.pName == nullptr || f.ptr == nullptr) break;
				std::string start = std::string(f.pName).substr(0, 4);
				if (start == "gml_" || start == "Timl") // gml OR timeline.
				{
					dfs << reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(f.ptr) - exeAsUint) << "|" << f.pName << std::endl;
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
	}
}

funcR lassebq_init()
{
	return 1.0;
}

funcR lassebq_shutdown()
{
	return 1.0;
}

funcV RegisterCallbacks(void* f1, void* f2, void* f3, void* f4)
{
	CreateThread(nullptr, 0, lassebq_cli, nullptr, 0, nullptr);
}