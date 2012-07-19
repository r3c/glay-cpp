
#ifndef __GLAY_PARALLEL_THREAD_HPP
#define __GLAY_PARALLEL_THREAD_HPP

#include <stdint.h>
#include "../config.hpp"
#include "lock.hpp"

#ifdef GLAY_OS_WINDOWS
	#include <process.h>
	#include <windows.h>
#endif

#define GLAY_PARALLEL_THREAD_STACK_SIZE	10 * 1024 * 1024

GLAY_NS_BEGIN(Parallel)

template<typename T>
class	Thread
{
	public:
		typedef void	(*Callback) (T);

		enum	State
		{
			STATE_ABORTED,
			STATE_CREATED,
			STATE_STARTED,
			STATE_PAUSED,
			STATE_ENDED
		};

		/**/			Thread (Callback, int = GLAY_PARALLEL_THREAD_STACK_SIZE);
		/**/			~Thread ();

		unsigned int	getIdentifier ();
		State			getState ();

		void			abort ();
		bool			join (int);
		void			join ();
		void			pause ();
		void			resume ();
		void			start (T);

	private:
		struct	Params
		{
			Callback	callback;
			Lock		lock;
			State		state;
			T			value;
		};

#ifdef GLAY_OS_WINDOWS
		__stdcall static unsigned	execute (void*);
#endif

		unsigned int	identifier;
#ifdef GLAY_OS_WINDOWS
		HANDLE			handle;
#else
	#error "Glay::Parallel::Thread can't be used on unsupported OS"
#endif
		Params			params;
};

GLAY_NS_END()

#include "thread.hxx"

#endif
