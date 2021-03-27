#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>

#define USE_WINAPI_FILE_WAIT_FIX 1 /* a weird fix for livecoding people, utilizes WinAPI error handling ^^' */

#define ItoD(integer) (static_cast<double>((integer)))
#define EtoI(e) (static_cast<signed int>((e)))
#define EtoD(e) (static_cast<double>((e)))

BOOL ClearConsole();
void WaitForDebugger();
void AllocConsoleQuick();
const char* GetRandomQuote();
bool CheckFileOk(const std::string& filePath);