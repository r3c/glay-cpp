
#ifndef __GLAY_SYSTEM_STOPWATCH_HPP
#define __GLAY_SYSTEM_STOPWATCH_HPP

#include "../config.hpp"

GLAY_NS_BEGIN(Time)

class	Stopwatch
{
	public:
		static Int64u	getResolution ();
		static Int64u	getTicks ();

		Stopwatch ();

		Int64u	getElapsed () const;

		void	reset ();
		void	start ();
		void	stop ();

	private:
		bool	active;
		Int64u	elapsed;
		Int64u	ticks;
};

GLAY_NS_END()

#endif
