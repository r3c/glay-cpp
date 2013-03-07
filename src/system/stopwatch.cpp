
#include "stopwatch.hpp"

#ifdef GLAY_OS_WINDOWS
	#include <windows.h>
#else
	#include <time.h>
#endif

#define GLAY_SYSTEM_STOPWATCH_RESOLUTION	1000

using namespace Glay;

GLAY_NS_BEGIN(System)

/*
** Get resolution (number of ticks per second) for all stopwatches.
** return:	stopwatches resolution
*/
Int64u	Stopwatch::getResolution ()
{
	return GLAY_SYSTEM_STOPWATCH_RESOLUTION;
}

/*
** Get number of milliseconds elapsed since system started.
** return:	ticks in milliseconds
*/
Int64u	Stopwatch::getTicks ()
{
#ifdef GLAY_OS_WINDOWS
	#if _WIN32_WINNT >= 0x0600
		return ::GetTickCount64 ();
	#else
		return ::GetTickCount ();
	#endif
#else
	timespec	ts;

	if (clock_gettime (CLOCK_MONOTONIC, &ts) != 0)
		return 0;

	return ts.tv_sec * GLAY_SYSTEM_STOPWATCH_RESOLUTION + ts.tv_nsec * GLAY_SYSTEM_STOPWATCH_RESOLUTION / 1000000;
#endif
}

/*
** Copy constructor.
** other:	source instance
*/
Stopwatch::Stopwatch (const Stopwatch& other) :
	active (other.active),
	elapsed (other.elapsed),
	ticks (other.ticks)
{
}

/*
** Default constructor.
*/
Stopwatch::Stopwatch ()
{
	this->reset ();
}

/*
** Copy operator.
** other:	source instance
*/
Stopwatch&	Stopwatch::operator = (const Stopwatch& other)
{
	this->active = other.active;
	this->elapsed = other.elapsed;
	this->ticks = other.ticks;

	return *this;
}

/*
** Get number of elapsed milliseconds (ticks) since construction of this
** Stopwatch instance.
** return:	elapsed milliseconds
*/
Int64u	Stopwatch::getElapsed () const
{
	return this->elapsed;
}

/*
** Stop counting and reset internal stopwatch values.
*/
void	Stopwatch::reset ()
{
	this->active = false;
	this->elapsed = 0;
}

/*
** Start stopwatch.
*/
void	Stopwatch::start ()
{
	if (!this->active)
	{
		this->active = true;
		this->ticks = Stopwatch::getTicks ();
	}
}

/*
** Stop stopwatch.
*/
void	Stopwatch::stop ()
{
	if (this->active)
	{
		this->active = false;
		this->elapsed = Stopwatch::getTicks () - this->ticks;
	}
}

GLAY_NS_END()
