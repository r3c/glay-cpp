
#include "atomic.hpp"

#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#include <windows.h>
#else
static Glay::Parallel::Lock	lock;

template <typename T>
static inline T	atomicLockedExchange (volatile T* target, T value)
{
	T	previous;

	lock.acquire ();
	previous = *target;
	*target = value;
	lock.release ();

	return previous;
}
#endif

GLAY_NS_BEGIN(Parallel)

Int8s		Atomic::Exchange (volatile Int8s* target, Int8s value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange8 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

Int8u		Atomic::Exchange (volatile Int8u* target, Int8u value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange8 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

Int16s		Atomic::Exchange (volatile Int16s* target, Int16s value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange16 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

Int16u	Atomic::Exchange (volatile Int16u* target, Int16u value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange16 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

Int32s		Atomic::Exchange (volatile Int32s* target, Int32s value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange32 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

Int32u	Atomic::Exchange (volatile Int32u* target, Int32u value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange32 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

Int64s		Atomic::Exchange (volatile Int64s* target, Int64s value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange64 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

Int64u	Atomic::Exchange (volatile Int64u* target, Int64u value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange64 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

template<typename T>
T*	Atomic::Exchange (volatile T** target, T* value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchangePointer (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

GLAY_NS_END()
