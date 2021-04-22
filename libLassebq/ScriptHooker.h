#pragma once
#include "GMLFuncs.h"
#include "Utils.h"
#include "libLassebq.h"
#include "GMLua.h"
void SH_pushCInstance(lua_State* _pL, CInstance* _pInst);
#define USE_DETOURS 1 /* Do you happen to have the Detours v4.0.1 from Microsoft Research's github? */

#if USE_DETOURS
#include "targetver.h"
#include "stdafx.h"
#include "detours\detours.h"


void SH_hookGMLScript(const YYGMLFunc& ref, const int index);
RValue& SH_hookerRoutine(const int _myIndex, CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args);
void SH_quitDetours(void);

#endif