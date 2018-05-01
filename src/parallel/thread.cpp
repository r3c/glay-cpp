
#include "thread.hpp"

#ifdef GLAY_SYSTEM_WINDOWS
	#include <process.h>
#endif

GLAY_NS_BEGIN(Parallel)

/*
** Internal thread entry point, used to force __stdcall calling convention
** and provide automatic system resources release.
** data: untyped ThreadParams pointer
** return always 0
*/
#if defined(GLAY_LIBRARY_PTHREAD)
void* ThreadBase::execute (void* data)
#elif defined(GLAY_SYSTEM_WINDOWS)
__stdcall unsigned ThreadBase::execute (void* data)
#endif
{
	ThreadBase* thread = reinterpret_cast<ThreadBase*> (data);

	thread->invoke ();
	thread->mutex.acquire ();

#if defined(GLAY_LIBRARY_PTHREAD)
	pthread_exit (0);
#elif defined(GLAY_SYSTEM_WINDOWS)
	::_endthreadex (0);
#endif

	thread->state = STATE_READY;

	Atomic::barrier ();

	thread->mutex.release ();

	return 0;
}

/*
** Base thread default constructor.
** stackSize: maximum thread stack size
*/
/**/ ThreadBase::ThreadBase (Int32u stackSize) :
	state (STATE_READY)
{
#if defined(GLAY_LIBRARY_PTHREAD)
	if (pthread_attr_init (&this->attribute) == 0)
	{
		pthread_attr_setstacksize (&this->attribute, stackSize);

		if (pthread_create (&this->thread, 0, ThreadBase::execute, reinterpret_cast<void*> (this)) == 0)
			this->identifier = this->thread.x;
		else
			this->identifier = 0;
	}
	else
		this->identifier = 0;
#elif defined(GLAY_SYSTEM_WINDOWS)
	unsigned address;

	this->handle = (HANDLE)::_beginthreadex (0, stackSize, ThreadBase::execute, reinterpret_cast<void*> (this), CREATE_SUSPENDED, &address);
	this->identifier = static_cast<Int32u> (address);
#endif
}

/*
** Base thread destructor.
*/
/**/ ThreadBase::~ThreadBase ()
{
#if defined(GLAY_LIBRARY_PTHREAD)
	if (this->identifier != 0)
	{
		pthread_attr_destroy (&this->attribute);
		pthread_cancel (this->thread);
	}
#elif defined(GLAY_SYSTEM_WINDOWS)
	if (this->handle)
		::CloseHandle (this->handle);
#endif
}

/*
** Force thread to terminate (allocated resources won't be released).
*/
void ThreadBase::abort ()
{
	this->mutex.acquire ();

	if (this->state == STATE_ACTIVE || this->state == STATE_PAUSED)
	{
#if defined(GLAY_LIBRARY_PTHREAD)
		if (this->identifier != 0)
			pthread_cancel (this->thread);
#elif defined(GLAY_SYSTEM_WINDOWS)
		if (this->handle)
			::TerminateThread (this->handle, 0);
#endif

		this->state = STATE_READY;

		Atomic::barrier ();
	}

	this->mutex.release ();
}

/*
** Get thread unique identifier.
** return: thread identifier
*/
Int32u ThreadBase::getIdentifier () const
{
	return this->identifier;
}

/*
** Get current thread state.
** return: thread state
*/
ThreadBase::State ThreadBase::getState () const
{
	this->mutex.acquire ();

	State state = this->state;

	Atomic::barrier ();

	this->mutex.release ();

	return state;
}

/*
** Wait for thread to terminate until specified timeout expires.
** timeout: timeout delay in milliseconds
** return: true if thread is terminated, false otherwise
*/
bool ThreadBase::join (Int32u timeout)
{
#if defined(GLAY_LIBRARY_PTHREAD)
	timeout = 0; // FIXME
#elif defined(GLAY_SYSTEM_WINDOWS)
	if (this->handle)
		return ::WaitForSingleObject (this->handle, timeout) == WAIT_OBJECT_0;
#endif

	return false;
}

/*
** Wait for thread to terminate.
*/
bool ThreadBase::join ()
{
#if defined(GLAY_LIBRARY_PTHREAD)
	if (this->identifier != 0)
		return pthread_join (this->thread, 0) == 0;
#elif defined(GLAY_SYSTEM_WINDOWS)
	return this->join (INFINITE);
#endif

	return false;
}

/*
** Pause thread execution.
*/
void ThreadBase::pause ()
{
	this->mutex.acquire ();

	if (this->state == STATE_ACTIVE)
	{
#if defined(GLAY_LIBRARY_PTHREAD)
	// FIXME
#elif defined(GLAY_SYSTEM_WINDOWS)
		if (this->handle)
			::SuspendThread (this->handle);

		this->state = STATE_PAUSED;

		Atomic::barrier ();
#endif
	}

	this->mutex.release ();
}

/*
** Resume thread execution.
*/
void ThreadBase::resume ()
{
	this->mutex.acquire ();

	if (this->state == STATE_PAUSED)
	{
#if defined(GLAY_LIBRARY_PTHREAD)
	// FIXME
#elif defined(GLAY_SYSTEM_WINDOWS)
		if (this->handle)
			::ResumeThread (this->handle);

		this->state = STATE_ACTIVE;

		Atomic::barrier ();
#endif
	}

	this->mutex.release ();
}

/*
** Parameterless thread default constructor.
** callback: thread callback function
** stackSize: maximum thread stack size
*/
/**/ Thread<void>::Thread (Callback callback, Int32u stackSize) :
	ThreadBase (stackSize),
	callback (callback)
{
}

/*
** Invoke callback from current parameterless thread.
*/
void Thread<void>::invoke ()
{
	this->callback ();
}

/*
** Start parameterless thread execution.
** value: parameter value
*/
void Thread<void>::start ()
{
	this->mutex.acquire ();

	if (this->state == STATE_READY)
	{
#if defined(GLAY_LIBRARY_PTHREAD)
	// FIXME
#elif defined(GLAY_SYSTEM_WINDOWS)
		if (this->handle)
			::ResumeThread (this->handle);
#endif

		this->state = STATE_ACTIVE;

		Atomic::barrier ();
	}

	this->mutex.release ();
}

GLAY_NS_END()
