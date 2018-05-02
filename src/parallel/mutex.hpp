
#ifndef __GLAY_PARALLEL_MUTEX_HPP
#define __GLAY_PARALLEL_MUTEX_HPP

#include "../config.hpp"

#if defined(GLAY_LIBRARY_PTHREAD)
	#include <pthread.h>
#elif defined(GLAY_SYSTEM_WINDOWS)
	#include <windows.h>
#endif

GLAY_NS_BEGIN(Parallel)

class Mutex
{
	public:
		Mutex (Mutex const&);
		Mutex (bool = false);
		virtual ~Mutex ();

		Mutex& operator = (Mutex const&);

		bool acquire (Int32u);
		bool acquire ();
		void release ();

	private:
#if defined(GLAY_LIBRARY_PTHREAD)
		pthread_mutex_t handle;
#elif defined(GLAY_SYSTEM_WINDOWS)
		HANDLE handle;
#else
	#warning "Compiling without support for Glay::Parallel::Mutex"
#endif
};

GLAY_NS_END()

#endif
