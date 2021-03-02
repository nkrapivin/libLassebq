#include "ScriptHooker.h"
#if USE_DETOURS

void SH_initDetours()
{
}

static void dumpBuffers(const std::string prefix)
{
	for (int b = 0; b < 1000; b++)
	{
		lassebq_callr("buffer_exists", { b });
		if (Result.asBoolean())
		{
			lassebq_callr("buffer_save", { b, prefix + std::to_string(b) + ".dat" });
		}
	}
}

RValue& (*SH_orig)(CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args) = 0;
RValue& SH_argumentInspector(CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args)
{
	// TODO: get_key_array

	// gml_Script_process_string_table_buffer
	std::cout << "BEFORE:" << std::endl;
	WaitForDebugger();
	std::cout << "AFTER:" << std::endl;
	SH_orig(_pSelf, _pOther, _result, _count, _args);
	std::cout << "generate_hash(): " << _result.asString() << std::endl;

	return _result;
}

void SH_hookGMLScript(const GML_Script original, const GML_Script func)
{
	SH_orig = original;
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)SH_orig, func);
	LONG e = DetourTransactionCommit();
	if (e != NO_ERROR)
	{
		throw std::exception{ "kitty cat" };
	}
}

void SH_quitDetours()
{
}

#endif