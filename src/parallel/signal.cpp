
#include "signal.hpp"

GLAY_NS_BEGIN(Parallel)

/*
** Signal default constructor.
** state:	initial signal state (true: set, false: reset)
** manual:	true for a manual reset event, false for automatic
*/
/**/	Signal::Signal (bool state, bool manual)
{
#if defined(GLAY_LIBRARY_PTHREAD)
	this->handle = PTHREAD_COND_INITIALIZER;
	this->mutex = PTHREAD_MUTEX_INITIALIZER;
#elif defined(GLAY_OS_WINDOWS)
	this->handle = ::CreateEvent (0, manual, state, 0);
#endif
}

/*
** Destroy signal.
*/
/**/	Signal::~Signal ()
{
#if defined(GLAY_LIBRARY_PTHREAD)
	pthread_cond_destroy (&this->handle);
#elif defined(GLAY_OS_WINDOWS)
	if (this->handle)
		::CloseHandle (this->handle);
#endif
}

/*
** Check is signal is set.
** return:	true if set, false else
*/
/**/	Signal::operator bool () const
{
#if defined(GLAY_LIBRARY_PTHREAD)
	// FIXME
#elif defined(GLAY_OS_WINDOWS)
	if (this->handle)
		return ::WaitForSingleObject (this->handle, 0) == WAIT_OBJECT_0;
#endif

	return false;
}

/*
** Reset signal.
*/
void	Signal::reset ()
{
#if defined(GLAY_LIBRARY_PTHREAD)
	// FIXME
#elif defined(GLAY_OS_WINDOWS)
	if (this->handle)
		::ResetEvent (this->handle);
#endif
}

/*
** Set signal.
*/
void	Signal::set ()
{
#if defined(GLAY_LIBRARY_PTHREAD)
	pthread_cond_signal (&this->handle);
#elif defined(GLAY_OS_WINDOWS)
	if (this->handle)
		::SetEvent (this->handle);
#endif
}

/*
** Wait for signal until specified timeout expires.
*/
bool	Signal::wait (Int32u timeout) const
{
#if defined(GLAY_LIBRARY_PTHREAD)
	return pthread_cond_timedwait (&this->handle, &this->mutex) == 0;
#elif defined(GLAY_OS_WINDOWS)
	if (this->handle)
		return ::WaitForSingleObject (this->handle, timeout) == WAIT_OBJECT_0;
#endif

	return false;
}

/*
** Wait for signal.
*/
void	Signal::wait () const
{
#if defined(GLAY_LIBRARY_PTHREAD)
	pthread_cond_wait (&this->handle, &this->mutex);
#elif defined(GLAY_OS_WINDOWS)
	this->wait (INFINITE);
#endif
}

GLAY_NS_END()
