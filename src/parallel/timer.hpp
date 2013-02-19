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

				Timer (Callback, int);
		virtual	~Timer ();

		Int32u	getPeriod () const;

		void	setPeriod (Int32u);

		void	fire ();
		void	start ();
		void	stop ();

	private:
		Callback				callback;
		volatile bool			interrupt;
		Int32u					period;
		Signal					signal;
		Thread<const Timer*>	thread;

		static void	tick (const Timer*);
};

GLAY_NS_END()

#endif
