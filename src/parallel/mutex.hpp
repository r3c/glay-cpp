
#ifndef __GLAY_PARALLEL_MUTEX_HPP
#define __GLAY_PARALLEL_MUTEX_HPP

#include "../config.hpp"

#ifdef GLAY_OS_WINDOWS
	#include <windows.h>
#endif

GLAY_NS_BEGIN(Parallel)

class	Mutex
{
	public:
		/**/	Mutex (const Mutex&);
		/**/	Mutex (bool = false);
		/**/	~Mutex ();

		Mutex&	operator = (const Mutex&);

		bool	acquire (Int32u);
		void	acquire ();
		void	release ();

	private:
#ifdef GLAY_OS_WINDOWS
		HANDLE	handle;
#else
	#error "Glay::Parallel::Mutex can't be used on unsupported configuration"
#endif
};

GLAY_NS_END()

#endif
