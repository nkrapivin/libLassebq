#include "GMAddresses.h"
#ifdef DITTO_WIN_STEAM
#include "DittoRAMProxy.h"
#include "libLassebq.h"
#include "Utils.h"

HMODULE hRamDll = nullptr;
T_ram_application DProxy_ram_application = nullptr;
T_ram_installed DProxy_ram_installed = nullptr;
T_ram_used DProxy_ram_used = nullptr;
T_ram_available DProxy_ram_available = nullptr;

BOOL DProxy_init(void)
{
	if (hRamDll != nullptr) return TRUE;
	//WaitForDebugger();
	hRamDll = LoadLibraryW(/* L"ram.dll" */ L"RamOrig.dll");
	if (hRamDll == nullptr)
	{
		MessageBoxW(
			nullptr,
			L"Failed to load ram.dll, is this The Swords of Ditto?",
			L"Uh oh!",
			MB_ICONERROR | MB_OK);
		ExitProcess(1);
		return FALSE;
	}

	DProxy_ram_application = reinterpret_cast<T_ram_application>(GetProcAddress(hRamDll, "ram_application"));
	DProxy_ram_installed = reinterpret_cast<T_ram_installed>(GetProcAddress(hRamDll, "ram_installed"));
	DProxy_ram_used = reinterpret_cast<T_ram_used>(GetProcAddress(hRamDll, "ram_used"));
	DProxy_ram_available = reinterpret_cast<T_ram_available>(GetProcAddress(hRamDll, "ram_available"));

	// were we able to link to the functions dynamically?
	if (DProxy_ram_application == nullptr
	||  DProxy_ram_installed == nullptr
	||  DProxy_ram_used == nullptr
	||  DProxy_ram_available == nullptr)
	{
		MessageBoxW(
			nullptr,
			L"Failed to link with ram.dll functions, is ram.dll corrupted?",
			L"Uh oh!",
			MB_ICONERROR | MB_OK);
		ExitProcess(1);
		return FALSE;
	}

	// :3
	lassebq_initYYC();
	return TRUE;
}

BOOL DProxy_quit(void)
{
	if (hRamDll == nullptr) return FALSE;
	FreeLibrary(hRamDll);
	lassebq_shutdown();
	return TRUE;
}

// call the original functions.
extern "C" __declspec(dllexport) double __cdecl ram_application(void) { return DProxy_ram_application(); }
extern "C" __declspec(dllexport) double __cdecl ram_installed(void) { return DProxy_ram_installed(); }
extern "C" __declspec(dllexport) double __cdecl ram_used(void) { return DProxy_ram_used(); }
extern "C" __declspec(dllexport) double __cdecl ram_available(void) { return DProxy_ram_available(); }
#endif