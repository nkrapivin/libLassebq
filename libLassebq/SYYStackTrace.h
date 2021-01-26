#pragma once

struct SYYStackTrace
{
	SYYStackTrace* pNext;
	const char* pName;
	int line;
	static SYYStackTrace** s_pStart;

	SYYStackTrace(const char* _pName, int _line);
	~SYYStackTrace();
};

#define YY_STACKTRACE_FUNC_ENTRY(_name, _line) SYYStackTrace __stackFunc(((_name)), ((_line)))
#define YY_STACKTRACE_LINE(_line) __stackFunc.line = ((_line))