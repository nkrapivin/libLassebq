// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"
#include "GMAddresses.h"
#include "DittoRAMProxy.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
#ifdef DITTO_WIN_STEAM
		return DProxy_init();
#endif
	case DLL_PROCESS_DETACH:
#ifdef DITTO_WIN_STEAM
		return DProxy_quit();
#endif
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

