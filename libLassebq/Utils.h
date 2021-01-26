#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>

BOOL ClearConsole();
void WaitForDebugger();
void AllocConsoleQuick();