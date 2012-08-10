
#include "thread.hpp"

GLAY_NS_BEGIN(Parallel)

/*
** Internal thread entry point, used to force __stdcall calling convention
** and provide automatic system resources release.
** data:	untyped ThreadParams pointer
** return	always 0
*/
#ifdef GLAY_OS_WINDOWS
__stdcall unsigned	ThreadBase::execute (void* data)
#endif
{
	ThreadBase*	thread = reinterpret_cast<ThreadBase*> (data);

	thread->invoke ();
	thread->lock.acquire ();

#ifdef GLAY_OS_WINDOWS
	::_endthreadex (0);
#endif

	thread->state = STATE_READY;
	thread->lock.release ();

	return 0;
}

/*
** Base thread default constructor.
** stackSize:	maximum thread stack size
*/
/**/	ThreadBase::ThreadBase (Int32u stackSize) :
	state (STATE_READY)
{
#ifdef GLAY_OS_WINDOWS
	unsigned	threadAddress;

	this->handle = (HANDLE)::_beginthreadex (0, stackSize, ThreadBase::execute, reinterpret_cast<void*> (this), CREATE_SUSPENDED, &threadAddress);
	this->identifier = static_cast<Int32u> (threadAddress);
#endif
}

/*
** Base thread destructor.
*/
/**/	ThreadBase::~ThreadBase ()
{
#ifdef GLAY_OS_WINDOWS
	if (this->handle)
		::CloseHandle (this->handle);
#endif
}

/*
** Force thread to terminate (allocated resources won't be released).
*/
void	ThreadBase::abort ()
{
	this->lock.acquire ();

	if (this->state == STATE_ACTIVE || this->state == STATE_PAUSED)
	{
#ifdef GLAY_OS_WINDOWS
		if (this->handle)
			::TerminateThread (this->handle, 0);
#endif

		this->state = STATE_READY;
	}

	this->lock.release ();
}

/*
** Get thread unique identifier.
** return:	thread identifier
*/
Int32u	ThreadBase::getIdentifier ()
{
	return this->identifier;
}

/*
** Get current thread state.
** return:	thread state
*/
ThreadBase::State	ThreadBase::getState ()
{
	State	state;

	this->lock.acquire ();

	state = this->state;

	this->lock.release ();

	return state;
}

/*
** Wait for thread to terminate until specified timeout expires.
** timeout: timeout delay in milliseconds
** return:	true if thread is terminated, false otherwise
*/
bool	ThreadBase::join (Int32u timeout)
{
#ifdef GLAY_OS_WINDOWS
	if (this->handle)
		return ::WaitForSingleObject (this->handle, timeout) == WAIT_OBJECT_0;
#endif

	return false;
}

/*
** Wait for thread to terminate.
*/
void	ThreadBase::join ()
{
#ifdef GLAY_OS_WINDOWS
	this->join (INFINITE);
#endif
}

/*
** Pause thread execution.
*/
void	ThreadBase::pause ()
{
	this->lock.acquire ();

	if (this->state == STATE_ACTIVE)
	{
#ifdef GLAY_OS_WINDOWS
		if (this->handle)
			::SuspendThread (this->handle);

		this->state = STATE_PAUSED;
	}
#endif

	this->lock.release ();
}

/*
** Resume thread execution.
*/
void	ThreadBase::resume ()
{
	this->lock.acquire ();

	if (this->state == STATE_PAUSED)
	{
#ifdef GLAY_OS_WINDOWS
		if (this->handle)
			::ResumeThread (this->handle);

		this->state = STATE_ACTIVE;
#endif
	}

	this->lock.release ();
}

/*
** Parameterless thread default constructor.
** callback:	thread callback function
** stackSize:	maximum thread stack size
*/
/**/	Thread<void>::Thread (Callback callback, Int32u stackSize) :
	ThreadBase (stackSize),
	callback (callback)
{
}

/*
** Invoke callback from current parameterless thread.
*/
void	Thread<void>::invoke ()
{
	this->callback ();
}

/*
** Start parameterless thread execution.
** value:	parameter value
*/
void	Thread<void>::start ()
{
	this->lock.acquire ();

	if (this->state == STATE_READY)
	{
#ifdef GLAY_OS_WINDOWS
		if (this->handle)
			::ResumeThread (this->handle);
#endif

		this->state = STATE_ACTIVE;
	}

	this->lock.release ();
}

GLAY_NS_END()
