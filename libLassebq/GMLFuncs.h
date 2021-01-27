#pragma once
#include "RValue.h"
#include <list>

class CInstance;
typedef void(*GML_ObjectEvent)(CInstance* _pSelf, CInstance* _pOther);
typedef RValue&(*GML_Script)(CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args);
typedef void(*TRoutine)(RValue& _result, CInstance* _pSelf, CInstance* _pOther, int _argc, RValue *_args);
typedef std::list<RValue> RValueList;
#define RUNTIME_MAX_ARGS (0x10)

struct YYVAR
{
	const char* pName;
	int val;
};

struct YYGMLFunc
{
	const char* pName;
	void* ptr;
};

struct RFunction
{
	char f_name[64];
	TRoutine f_routine;
	int f_argnumb;
	unsigned int m_UsageCount;
	int f_maxargnumb; // always 0xFFFFFFFF
};

extern YYGMLFunc* g_GMLScripts;
extern YYVAR** g_Variables;
extern RFunction** g_RFunctionTable;
extern int* g_RFunctionTableLen;

extern CInstance* g_Self;
extern CInstance* g_Other;

void CallRFunction(int id, RValue& ret, const RValueList& args);
void CallScriptFunction(int id, RValue& ret, const RValueList& args, bool isEvent = false);