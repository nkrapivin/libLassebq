#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>

#define ItoD(integer) (static_cast<double>((integer)))
#define EtoI(e) (static_cast<signed int>((e)))
#define EtoD(e) (static_cast<double>((e)))

BOOL ClearConsole();
void WaitForDebugger();
void AllocConsoleQuick();
const char* GetRandomQuote();