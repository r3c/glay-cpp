
#include "atomic.hpp"

#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#include <windows.h>
#elif defined(__GNUG__)
// See:
// http://gcc.gnu.org/onlinedocs/gcc-4.1.1/gcc/Atomic-Builtins.html

static inline void	atomicBarrier ()
{
	__sync_synchronize ();
}

template <typename T>
static inline T	atomicCompare (T* target, T current, T replace)
{
	return __sync_val_compare_and_swap (target, current, replace);
}

template <typename T>
static inline T	atomicSwap (T* target, T value)
{
	return __sync_lock_test_and_set (target, value);
}
#else
	#error "Glay::Parallel::Atomic can't be used on unsupported configuration"
#endif

GLAY_NS_BEGIN(Parallel)

void	Atomic::barrier ()
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::_ReadWriteBarrier ();
#else
	atomicBarrier ();
#endif
}

/*
Int8s	Atomic::compare (Int8s* target, Int8s current, Int8s replace)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int8u	Atomic::compare (Int8u* target, Int8u current, Int8u replace)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int16s	Atomic::compare (Int16s* target, Int16s current, Int16s replace)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int16u	Atomic::compare (Int16u* target, Int16u current, Int16u replace)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (static_cast<LONG> (target), static_cast<LONG> (replace), static_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int32s	Atomic::compare (Int32s* target, Int32s current, Int32s replace)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int32u	Atomic::compare (Int32u* target, Int32u current, Int32u replace)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

template<typename T>
T*	Atomic::compare (T** target, T* current, T* replace)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}
*/

Int8s	Atomic::swap (Int8s* target, Int8s value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange8 (target, value);
#else
	return atomicSwap (target, value);
#endif
}

Int8u	Atomic::swap (Int8u* target, Int8u value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange8 (target, value);
#else
	return atomicSwap (target, value);
#endif
}

Int16s	Atomic::swap (Int16s* target, Int16s value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange16 (target, value);
#else
	return atomicSwap (target, value);
#endif
}

Int16u	Atomic::swap (Int16u* target, Int16u value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange16 (target, value);
#else
	return atomicSwap (target, value);
#endif
}

Int32s	Atomic::swap (Int32s* target, Int32s value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange32 (target, value);
#else
	return atomicSwap (target, value);
#endif
}

Int32u	Atomic::swap (Int32u* target, Int32u value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchange32 (target, value);
#else
	return atomicSwap (target, value);
#endif
}

template<typename T>
T*	Atomic::swap (T** target, T* value)
{
#if defined(GLAY_OS_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedExchangePointer (target, value);
#else
	return atomicSwap (target, value);
#endif
}

GLAY_NS_END()
