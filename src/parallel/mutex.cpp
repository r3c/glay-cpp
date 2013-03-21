
#include "mutex.hpp"

#if defined(GLAY_LIBRARY_PTHREAD)
#include <time.h>
#endif

GLAY_NS_BEGIN(Parallel)

/*
** Mutex default constructor.
** acquired:	true to initialy acquire mutex, false otherwise
*/
/**/	Mutex::Mutex (bool acquired)
{
#if defined(GLAY_LIBRARY_PTHREAD)
	this->handle = PTHREAD_MUTEX_INITIALIZER;

	if (acquired)
		this->acquire ();
#elif defined(GLAY_OS_WINDOWS)
	this->handle = ::CreateMutex (0, acquired, 0);
#endif
}

/*
** Mutex destructor.
*/
/**/	Mutex::~Mutex ()
{
#if defined(GLAY_LIBRARY_PTHREAD)
#elif defined(GLAY_OS_WINDOWS)
	if (this->handle)
		::CloseHandle (this->handle);
#endif
}

/*
** Try to enter critical code section by waiting for mutex to be available
** until specified timeout expires.
** timeout:	timeout delay in milliseconds
** return:	true if mutex has been acquired, false else
*/
bool	Mutex::acquire (Int32u timeout)
{
#if defined(GLAY_LIBRARY_PTHREAD)
	struct timespec	delta;

	delta.tv_sec = timeout / 1000;
	delta.tv_nsec = timeout * 1000;

	return pthread_mutex_timedlock (&this->handle, &delta) == 0;
#elif defined(GLAY_OS_WINDOWS)
	return this->handle && ::WaitForSingleObject (this->handle, timeout) == WAIT_OBJECT_0;
#endif
}

/*
** Enter critical code section by waiting for mutex to be available.
*/
bool	Mutex::acquire ()
{
#if defined(GLAY_LIBRARY_PTHREAD)
	return pthread_mutex_lock (&this->handle) == 0;
#elif defined(GLAY_OS_WINDOWS)
	return this->acquire (INFINITE);
#endif
}

/*
** Leave critical code section by releasing mutex.
*/
void	Mutex::release ()
{
#if defined(GLAY_LIBRARY_PTHREAD)
	pthread_mutex_unlock (&this->handle);
#elif defined(GLAY_OS_WINDOWS)
	if (this->handle)
		::ReleaseMutex (this->handle);
#endif
}

GLAY_NS_END()
