
#include "thread.hpp"

GLAY_NS_BEGIN(Parallel)

/*
** Thread default constructor.
** callback:	thread callback function
** stackSize:	maximum thread stack size
*/
template<typename T>
/**/	Thread<T>::Thread (Callback callback, int stackSize)
{
	this->params.callback = callback;
	this->params.state = STATE_CREATED;

#ifdef GLAY_OS_WINDOWS
	this->handle = (HANDLE)::_beginthreadex (0, stackSize, Thread<T>::execute, static_cast<void*> (&params), CREATE_SUSPENDED, &this->identifier);
#endif
}

/*
** Destroy thread.
*/
template<typename T>
/**/	Thread<T>::~Thread ()
{
#ifdef GLAY_OS_WINDOWS
	if (this->handle)
		::CloseHandle (this->handle);
#endif
}

/*
** Force thread to terminate (allocated resources won't be released).
*/
template<typename T>
void	Thread<T>::abort ()
{
#ifdef GLAY_OS_WINDOWS
	if (this->handle)
		::TerminateThread (this->handle, 0);
#endif

	this->params.lock.acquire ();
	this->params.state = STATE_ABORTED;
	this->params.lock.release ();
}

/*
** Internal thread entry point, used to force __stdcall calling convention
** and provide automatic system resources release.
** data:	untyped ThreadParams pointer
** return	always 0
*/
#ifdef GLAY_OS_WINDOWS
template<typename T>
__stdcall unsigned	Thread<T>::execute (void* data)
#endif
{
	Thread<T>::Params*	params = (Thread<T>::Params*)data;

	params->callback (params->value);

#ifdef GLAY_OS_WINDOWS
	::_endthreadex (0);
#endif
	params->lock.acquire ();
	params->state = STATE_ENDED;
	params->lock.release ();

	return 0;
}

/*
** Get thread unique identifier.
** return:	thread identifier
*/
template<typename T>
unsigned int	Thread<T>::getIdentifier ()
{
	return this->identifier;
}

/*
** Get current thread state.
** return:	thread state
*/
template<typename T>
typename Thread<T>::State	Thread<T>::getState ()
{
	State	state;

	this->params.lock.acquire ();

	state = this->params.state;

	this->params.lock.release ();

	return state;
}

/*
** Wait for thread to terminate until specified timeout expires.
** timeout: timeout delay in milliseconds
** return:	true if thread is terminated, false otherwise
*/
template<typename T>
bool	Thread<T>::join (int timeout)
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
template<typename T>
void	Thread<T>::join ()
{
#ifdef GLAY_OS_WINDOWS
	this->join (INFINITE);
#endif
}

/*
** Pause thread execution.
*/
template<typename T>
void	Thread<T>::pause ()
{
	this->params.lock.acquire ();

	if (this->params.state == STATE_STARTED)
	{
#ifdef GLAY_OS_WINDOWS
		if (this->handle)
			::SuspendThread (this->handle);

		this->params.state = STATE_PAUSED;
	}
#endif

	this->params.lock.release ();
}

/*
** Resume thread execution.
*/
template<typename T>
void	Thread<T>::resume ()
{
	this->params.lock.acquire ();

	if (this->params.state == STATE_PAUSED)
	{
#ifdef GLAY_OS_WINDOWS
		if (this->handle)
			::ResumeThread (this->handle);

		this->params.state = STATE_STARTED;
#endif
	}

	this->params.lock.release ();
}

/*
** Start thread execution.
*/
template<typename T>
void	Thread<T>::start (T value)
{
	this->params.lock.acquire ();

	if (this->params.state == STATE_CREATED)
	{
		this->params.value = value;

#ifdef GLAY_OS_WINDOWS
		if (this->handle)
			::ResumeThread (this->handle);
#endif

		this->params.state = STATE_STARTED;
	}

	this->params.lock.release ();
}

GLAY_NS_END()
