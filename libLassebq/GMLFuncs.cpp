#include "GMLFuncs.h"

YYGMLFunc* g_GMLScripts = nullptr;
YYVAR** g_Variables = nullptr;
RFunction** g_RFunctionTable = nullptr;
int* g_RFunctionTableLen = nullptr;

CInstance* g_Self = nullptr;
CInstance* g_Other = nullptr;

void CallRFunction(int id, RValue& ret, const RValueList& args)
{
	if (id < 0) abort();

	RFunction RFunc = (*g_RFunctionTable)[id];
	int i = 0;
	int argc = static_cast<int>(args.size());

	// allocate arguments **on the stack!** because GameMaker is stupid.
	RValue Rargs[RUNTIME_MAX_ARGS]{ /* will execute the default constructor */ };
	for (const auto& rv : args)
	{
		if (i > ((sizeof(Rargs)/sizeof(*Rargs)) - 1)) abort();
		Rargs[i] = rv;
		i++;
	}

	RFunc.f_routine(ret, g_Self, g_Other, argc, Rargs);
}

void CallScriptFunction(int id, RValue& ret, const RValueList& args, bool isEvent)
{
	if (id < 0) abort();

	// do the magic.
	YYGMLFunc myFunc = g_GMLScripts[id];
	if (isEvent)
	{
		// call
		reinterpret_cast<GML_ObjectEvent>(myFunc.ptr)(g_Self, nullptr);
	}
	else
	{
		// prepare argument memory.
		const RValue **Arguments = nullptr;
		if (args.size() > 0)
		{
			Arguments = const_cast<const RValue**>(new RValue*[args.size()]);
			int i = 0;
			for (const auto& arg : args) { Arguments[i] = &arg; i++; }
		}

		// call
		reinterpret_cast<GML_Script>(myFunc.ptr)(g_Self, g_Other, ret, static_cast<int>(args.size()), Arguments);

		// clean up.
		if (Arguments != nullptr) delete[] Arguments;
	}
}