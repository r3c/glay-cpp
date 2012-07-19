
#ifndef __GLAY_PARALLEL_LOCK_HPP
#define __GLAY_PARALLEL_LOCK_HPP

#include "../config.hpp"

#ifdef GLAY_OS_WINDOWS
	#include <windows.h>
#endif

GLAY_NS_BEGIN(Parallel)

class	Lock
{
	public:
		/**/	Lock (const Lock&);
		/**/	Lock (bool = false);
		/**/	~Lock ();

		Lock&	operator = (const Lock&);

		bool	acquire (int);
		void	acquire ();
		void	release ();

	private:
#ifdef GLAY_OS_WINDOWS
		HANDLE	handle;
#else
	#error "Glay::Parallel::Lock can't be used on unsupported OS"
#endif
};

GLAY_NS_END()

#endif
