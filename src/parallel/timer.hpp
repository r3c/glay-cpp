
#ifndef __GLAY_PARALLEL_TIMER_HPP
#define __GLAY_PARALLEL_TIMER_HPP

#include "../config.hpp"
#include "signal.hpp"
#include "thread.hpp"

GLAY_NS_BEGIN(Parallel)

class	Timer
{
	public:
		typedef void	(*Callback) ();

		Timer (Callback, Int32u);
		virtual	~Timer ();

		Int32u	getPeriod () const;

		void	setPeriod (Int32u);

		void	fire ();
		void	start ();
		void	stop ();

	private:
		static void	tick (Timer*);

		Callback		callback;
		volatile bool	interrupt;
		Int32u			period;
		Signal			signal;
		Thread<Timer*>	thread;
};

GLAY_NS_END()

#endif
