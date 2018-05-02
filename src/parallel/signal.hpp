
#ifndef __GLAY_PARALLEL_SIGNAL_HPP
#define __GLAY_PARALLEL_SIGNAL_HPP

#include "../config.hpp"

#if defined(GLAY_LIBRARY_PTHREAD)
	#include <pthread.h>
#elif defined(GLAY_SYSTEM_WINDOWS)
	#include <windows.h>
#endif

GLAY_NS_BEGIN(Parallel)

class Signal
{
	public:
		Signal (Signal const&);
		Signal (bool state = false, bool manual = true);
		virtual ~Signal ();

				operator bool () const;
		Signal& operator = (Signal const&);

		void reset ();
		void set ();
		bool wait (Int32u);
		bool wait ();

	private:
#if defined(GLAY_LIBRARY_PTHREAD)
		pthread_cond_t handle;
		pthread_mutex_t mutex;
#elif defined(GLAY_SYSTEM_WINDOWS)
		HANDLE handle;
#else
	#warning "Compiling without support for Glay::Parallel::Signal"
#endif
};

GLAY_NS_END()

#endif
