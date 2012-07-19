
#include "atomic.hpp"

#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#include <windows.h>
#else
static Glay::Parallel::Lock	lock;

template <typename T>
static T	atomicLockedExchange (volatile T* target, T value)
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

int8_t		Atomic::Exchange (volatile int8_t* target, int8_t value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange8 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

uint8_t		Atomic::Exchange (volatile uint8_t* target, uint8_t value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange8 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

int16_t		Atomic::Exchange (volatile int16_t* target, int16_t value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange16 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

uint16_t	Atomic::Exchange (volatile uint16_t* target, uint16_t value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange16 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

int32_t		Atomic::Exchange (volatile int32_t* target, int32_t value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange32 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

uint32_t	Atomic::Exchange (volatile uint32_t* target, uint32_t value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange32 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

int64_t		Atomic::Exchange (volatile int64_t* target, int64_t value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange64 (target, value);
#else
	return atomicLockedExchange (target, value);
#endif
}

uint64_t	Atomic::Exchange (volatile uint64_t* target, uint64_t value)
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
