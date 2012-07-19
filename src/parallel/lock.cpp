
#include "lock.hpp"

GLAY_NS_BEGIN(Parallel)

/*
** Lock default constructor.
** acquired:	true to initialy acquire lock, false otherwise
*/
/**/	Lock::Lock (bool acquired)
{
#ifdef GLAY_OS_WINDOWS
	this->handle = ::CreateMutex (0, acquired, 0);
#endif
}

/*
** Lock destructor.
*/
/**/	Lock::~Lock ()
{
#ifdef GLAY_OS_WINDOWS
	if (this->handle)
		::CloseHandle (this->handle);
#endif
}

/*
** Try to enter critical code section by waiting for lock to be available until
** specified timeout expires.
** timeout:	timeout delay in milliseconds
** return:	true if lock has been acquired, false else
*/
bool	Lock::acquire (int timeout)
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
** Enter critical code section by waiting for lock to be available.
*/
void	Lock::acquire ()
{
#ifdef GLAY_OS_WINDOWS
	this->acquire (INFINITE);
#endif
}

/*
** Leave critical code section by releasing lock.
*/
void	Lock::release ()
{
#ifdef GLAY_OS_WINDOWS
	if (this->handle)
		::ReleaseMutex (this->handle);
#endif
}

GLAY_NS_END()
