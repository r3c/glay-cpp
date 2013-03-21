
#ifndef __GLAY_PARALLEL_SIGNAL_HPP
#define __GLAY_PARALLEL_SIGNAL_HPP

#include "../config.hpp"

#if defined(GLAY_LIBRARY_PTHREAD)
	#include <pthread>
#elif defined(GLAY_OS_WINDOWS)
	#include <windows.h>
#endif

GLAY_NS_BEGIN(Parallel)

class	Signal
{
	public:
				Signal (const Signal&);
				Signal (bool state = false, bool manual = true);
		virtual	~Signal ();

				operator bool () const;
		Signal&	operator = (const Signal&);

		void	reset ();
		void	set ();
		bool	wait (Int32u) const;
		void	wait () const;

	private:
#if defined(GLAY_LIBRARY_PTHREAD)
		pthread_cond_t	handle;
		pthread_mutex_t	mutex;
#elif defined(GLAY_OS_WINDOWS)
		HANDLE			handle;
#else
	#error "Glay::Parallel::Signal can't be used on unsupported OS"
#endif
};

GLAY_NS_END()

#endif
