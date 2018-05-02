
#include "thread.hpp"

GLAY_NS_BEGIN(Parallel)

/*
** Parameterized thread default constructor.
** callback:	thread callback function
** stackSize:	maximum thread stack size
*/
template<typename T>
/**/ Thread<T>::Thread (Callback callback, Int32u stackSize) :
	ThreadBase (stackSize),
	callback (callback),
	value ()
{
#if !defined(GLAY_LIBRARY_PTHREAD) && !defined(GLAY_SYSTEM_WINDOWS)
	throw "Glay::Parallel::Thread was not enabled at compilation";
#endif
}

/*
** Invoke callback from current parameterized thread.
*/
template<typename T>
void Thread<T>::invoke ()
{
	this->callback (this->value);
}

/*
** Start parameterized thread execution.
** value:	parameter value
*/
template<typename T>
void Thread<T>::start (T const& value)
{
	this->mutex.acquire ();

	if (this->state == STATE_READY)
	{
		this->value = value;

		Atomic::barrier ();

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
