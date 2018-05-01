
#ifndef __GLAY_PARALLEL_THREAD_HPP
#define __GLAY_PARALLEL_THREAD_HPP

#include "../config.hpp"
#include "atomic.hpp"
#include "mutex.hpp"

#if defined(GLAY_LIBRARY_PTHREAD)
	#include <pthread.h>
#elif defined(GLAY_SYSTEM_WINDOWS)
	#include <windows.h>
#endif

GLAY_NS_BEGIN(Parallel)

class ThreadBase
{
	public:
		enum State
		{
			STATE_ACTIVE,	// Thread is currently working
			STATE_PAUSED,	// Thread is paused
			STATE_READY // Thread is available for use
		};

		ThreadBase (ThreadBase const&);
		ThreadBase (Int32u);
		virtual ~ThreadBase ();

		ThreadBase& operator = (ThreadBase const&);

		Int32u getIdentifier () const;
		State getState () const;

		void abort ();
		bool join (Int32u);
		bool join ();
		void pause ();
		void resume ();

	protected:
		virtual void invoke () = 0;

#if defined(GLAY_LIBRARY_PTHREAD)
		pthread_attr_t attribute;
		pthread_t thread;
#elif defined(GLAY_SYSTEM_WINDOWS)
		HANDLE handle;
#else
	#error "Glay::Parallel::Thread can't be used on unsupported configuration"
#endif
		mutable Mutex mutex;
		State state;

	private:
#if defined(GLAY_LIBRARY_PTHREAD)
                static void* execute (void*);
#elif defined(GLAY_SYSTEM_WINDOWS)
		__stdcall static unsigned execute (void*);
#endif

		Int32u identifier;
};

template<typename T = void>
class Thread : public ThreadBase
{
	public:
		typedef void (*Callback) (T);

		Thread (Callback, Int32u = GLAY_MODULE_PARALLEL_THREAD_STACK_SIZE);

		void start (T const&);

	protected:
		virtual void invoke ();

	private:
		Callback callback;
		T value;
};

template<>
class Thread<void> : public ThreadBase
{
	public:
		typedef void (*Callback) ();

		Thread (Callback, Int32u = GLAY_MODULE_PARALLEL_THREAD_STACK_SIZE);

		void start ();

	protected:
		virtual void invoke ();

	private:
		Callback callback;
};

GLAY_NS_END()

#include "thread.hxx"

#endif
