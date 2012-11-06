
#include "mutex.hpp"

GLAY_NS_BEGIN(Parallel)

/*
** Mutex default constructor.
** acquired:	true to initialy acquire mutex, false otherwise
*/
/**/	Mutex::Mutex (bool acquired)
{
#ifdef GLAY_OS_WINDOWS
	this->handle = ::CreateMutex (0, acquired, 0);
#endif
}

/*
** Mutex destructor.
*/
/**/	Mutex::~Mutex ()
{
#ifdef GLAY_OS_WINDOWS
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
	bool	state;

#ifdef GLAY_OS_WINDOWS
	if (this->handle && ::WaitForSingleObject (this->handle, timeout) == WAIT_OBJECT_0)
		state = true;
	else
		state = false;
#endif

	return state;
}

/*
** Enter critical code section by waiting for mutex to be available.
*/
void	Mutex::acquire ()
{
#ifdef GLAY_OS_WINDOWS
	this->acquire (INFINITE);
#endif
}

/*
** Leave critical code section by releasing mutex.
*/
void	Mutex::release ()
{
#ifdef GLAY_OS_WINDOWS
	if (this->handle)
		::ReleaseMutex (this->handle);
#endif
}

GLAY_NS_END()
