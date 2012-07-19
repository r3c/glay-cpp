
#ifndef __GLAY_PARALLEL_SIGNAL_HPP
#define __GLAY_PARALLEL_SIGNAL_HPP

#include "../config.hpp"

#ifdef GLAY_OS_WINDOWS
	#include <windows.h>
#endif

GLAY_NS_BEGIN(Parallel)

class	Signal
{
	public:
		/**/		Signal (bool state = false, bool manual = true);
		/**/		~Signal ();

		operator	bool () const;

		void		reset ();
		void		set ();
		bool		wait (int);
		void		wait ();

	private:
#ifdef GLAY_OS_WINDOWS
		HANDLE		handle;
#else
	#error "Glay::Parallel::Signal can't be used on unsupported OS"
#endif
};

GLAY_NS_END()

#endif