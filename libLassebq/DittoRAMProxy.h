#pragma once
#include "stdafx.h"

/*
 * Since The Swords of Ditto is using Spine for skeletal animation,
 * and UndertaleModTool can't properly handle Spine sprites,
 * we can't just add an extension to the .win, it will get corrupted,
 * instead, we can replace ram.dll with libLassebq...
 * 
 * However, there is a problem, ram.dll has no init function set up.
 * So we need to initialize the library in DllMain, right when GameMaker tries to load our DLL.
 * Then, we LoadLibraryW the actual DLL, and proxy all function calls straight to RAM.dll :/
 * libLassebq is inside GameMaker, ram.dll calls are proxied, all is fine, everyone is happy.
 * ~~except, probably, the string tables...~~
 */

// function types.
typedef double(*T_ram_application)(void); // takes 0 args, ret double.
typedef double(*T_ram_installed)(void); // takes 0 args, ret double.
typedef double(*T_ram_used)(void); // takes 0 args, ret double.
typedef double(*T_ram_available)(void); // takes 0 args, ret double.

// function pointers.
extern T_ram_application DProxy_ram_application;
extern T_ram_installed DProxy_ram_installed;
extern T_ram_used DProxy_ram_used;
extern T_ram_available DProxy_ram_available;

// function exports
extern "C" __declspec(dllexport) double __cdecl ram_application(void);
extern "C" __declspec(dllexport) double __cdecl ram_installed(void);
extern "C" __declspec(dllexport) double __cdecl ram_used(void);
extern "C" __declspec(dllexport) double __cdecl ram_available(void);

// DLL loader.
BOOL DProxy_init(void);
BOOL DProxy_quit(void);