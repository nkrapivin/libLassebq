#pragma once
#define USE_DETOURS 1 /* Do you happen to have the Detours v4.0.1 from Microsoft Research's github? */

#if USE_DETOURS
#include "targetver.h"
#include "stdafx.h"
#include "detours\detours.h"
#include "GMLFuncs.h"
#include "Utils.h"
#include "libLassebq.h"
#include <unordered_map>

void SH_initDetours(void);
void SH_hookGMLScript(const GML_Script original, const GML_Script func);
RValue& SH_argumentInspector(CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args);
void SH_quitDetours(void);

#endif