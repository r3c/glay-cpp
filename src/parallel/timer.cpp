
#include "timer.hpp"

GLAY_NS_BEGIN(Parallel)

/*
** Internal timer tick method.
** timer:	timer reference
*/
void	Timer::tick (Timer* timer)
{
	while (!timer->signal.wait (timer->period) || !timer->interrupt)
		timer->callback ();
}

/*
** Timer default constructor.
*/
/**/	Timer::Timer (Callback callback, int period) :
	callback (callback),
	interrupt (false),
	period (period),
	thread (&Timer::tick)
{
}

/**/	Timer::~Timer ()
{
	this->interrupt = true;
	this->signal.set ();
	this->thread.join ();
}

/*
** Get timer period.
** return:	timer period in milliseconds
*/
Int32u	Timer::getPeriod () const
{
	return this->period;
}

/*
** Set timer period
** period:	timer period in milliseconds
*/
void	Timer::setPeriod (Int32u period)
{
	this->period = period;
}

/*
** Force timer to fire immediately.
*/
void	Timer::fire ()
{
	this->signal.set ();
}

/*
** Start timer.
*/
void	Timer::start ()
{
	this->thread.resume ();
}

/*
** Stop timer.
*/
void	Timer::stop ()
{
	this->thread.pause ();
}

GLAY_NS_END()
