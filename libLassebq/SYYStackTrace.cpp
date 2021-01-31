#include "SYYStackTrace.h"

SYYStackTrace** SYYStackTrace::s_pStart = nullptr; // will be set to an address that points to s_pStart in lassebq_initYYC()

SYYStackTrace::SYYStackTrace(const char* _pName, int _line)
{
	pName = _pName;
	line = _line;
	pNext = *s_pStart;
	*s_pStart = this;
}

SYYStackTrace::~SYYStackTrace()
{
	*s_pStart = pNext;
}