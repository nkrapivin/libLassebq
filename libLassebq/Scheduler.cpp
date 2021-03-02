#include "Scheduler.h"
#include "stdafx.h"
#include "timeapi.h"

void sch_begin(void)
{
#ifdef USE_SCHEDULER_FIX
	timeBeginPeriod(1U);
#endif
}

void sch_end(void)
{
#ifdef USE_SCHEDULER_FIX
	timeEndPeriod(1U);
#endif
}