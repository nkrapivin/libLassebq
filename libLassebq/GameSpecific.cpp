#include "GameSpecific.h"

#ifdef KZ_105_STEAM
const char* const VerString = "v1.0.5\n[LLBQ]"; // LLBQ -> LibLasseBQ
#endif
#ifdef KZ_105_GOG
const char* const VerString = "v1.0.5\n[LGOG]";
#endif

void ApplyGameSpecificPatches(uintptr_t exeBase)
{
	// put your weird patches here!!!

	SIZE_T written;
	void* verStringAddr = reinterpret_cast<void*>(exeBase + MenuVersionString_Addr);
	LPCVOID buf = reinterpret_cast<LPCVOID>(&VerString);

	// just derefing the address doesn't work, Windows throws an
	// Access Violation Exception,
	// you need to use WriteProcessMemory (the same function Cheat Engine is using)
	if (WriteProcessMemory(GetCurrentProcess(), verStringAddr, buf, sizeof(buf), &written) == FALSE || written != sizeof(buf))
	{
		abort();
	}
}