#pragma once
#include "GMLFuncs.h"
#include "ScriptHooker.h"

extern GML_Script SH_DummyRoutines[];
extern PVOID SH_DummyPVOIDs[];

#define DEF_LLBQ_DTR_ROUTINE(ind) RValue& SH_routine ##ind(CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args) { return SH_hookerRoutine((ind), _pSelf, _pOther, _result, _count, _args); }
#define DEF_LLBQ_DUMMY_PVOID_TABLE PVOID SH_DummyPVOIDs[10000]{ nullptr }