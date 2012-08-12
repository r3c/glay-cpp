
#ifndef __GLAY_PARALLEL_THREAD_HPP
#define __GLAY_PARALLEL_THREAD_HPP

#include "../config.hpp"
#include "lock.hpp"

#ifdef GLAY_OS_WINDOWS
	#include <windows.h>
#endif

#define GLAY_PARALLEL_THREAD_STACK_SIZE	10 * 1024 * 1024

GLAY_NS_BEGIN(Parallel)

class	ThreadBase
{
	public:
		enum	State
		{
			STATE_ACTIVE,	// Thread is currently working
			STATE_PAUSED,	// Thread is paused
			STATE_READY		// Thread is available for use
		};

		/**/			ThreadBase (const ThreadBase&);
		/**/			ThreadBase (Int32u);
		/**/			~ThreadBase ();

		ThreadBase&		operator = (const ThreadBase&);

		Int32u			getIdentifier ();
		State			getState ();

		void			abort ();
		bool			join (Int32u);
		void			join ();
		void			pause ();
		void			resume ();

	protected:
		virtual void	invoke () = 0;

#ifdef GLAY_OS_WINDOWS
		HANDLE			handle;
#else
	#error "Glay::Parallel::Thread can't be used on unsupported OS"
#endif
		Lock			lock;
		State			state;

	private:
#ifdef GLAY_OS_WINDOWS
		__stdcall static unsigned	execute (void*);
#endif

		Int32u			identifier;
};

template<typename T = void>
class	Thread : public ThreadBase
{
	public:
		typedef void	(*Callback) (T);

		/**/			Thread (Callback, Int32u = GLAY_PARALLEL_THREAD_STACK_SIZE);

		void			start (const T&);

	protected:
		virtual void	invoke ();

	private:
		Callback		callback;
		T				value;
};

template<>
class	Thread<void> : public ThreadBase
{
	public:
		typedef void	(*Callback) ();

		/**/			Thread (Callback, Int32u = GLAY_PARALLEL_THREAD_STACK_SIZE);

		void			start ();

	protected:
		virtual void	invoke ();

	private:
		Callback		callback;
};

GLAY_NS_END()

#include "thread.hxx"

#endif
