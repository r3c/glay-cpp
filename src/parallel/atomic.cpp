
#include "atomic.hpp"

#if defined(GLAY_BUILTIN_ATOMIC)
namespace
{
	// See:
	// http://gcc.gnu.org/onlinedocs/gcc-4.1.1/gcc/Atomic-Builtins.html

	struct	AtomicBarrier
	{
		static inline void	call ()
		{
			__sync_synchronize ();
		}
	};

	template<typename T>
	struct	AtomicCompare
	{
		static inline T	call (T* target, T current, T replace)
		{
			return __sync_val_compare_and_swap (target, current, replace);
		}
	};

	template<typename T>
	struct	AtomicDecrement
	{
		static inline T	call (T* target, T value)
		{
			return __sync_fetch_and_sub (target, value);
		}
	};

	template<typename T>
	struct	AtomicIncrement
	{
		static inline T	call (T* target, T value)
		{
			return __sync_fetch_and_add (target, value);
		}
	};

	template<typename T>
	struct	AtomicExchange
	{
		static inline T	call (T* target, T value)
		{
			return __sync_lock_test_and_set (target, value);
		}
	};
}
#elif defined(GLAY_SYSTEM_WINDOWS)
#include <windows.h>

namespace
{
	struct	AtomicBarrier ()
	{
		static inline void	call ()
		{
			::_ReadWriteBarrier ();
		}
	};

	template<typename T>
	struct	AtomicExchange
	{
	};

	template<typename T>
	struct	AtomicExchange<T*>
	{
		static inline T*	call (T* target, T value)
		{
			return ::InterlockedExchangePointer (target, value);
		}
	};

	template<>
	struct	AtomicExchange<Int8s>
	{
		static inline Int8s	call (Int8s* target, Int8s value)
		{
			return ::InterlockedExchange8 (target, value);
		}
	};

	template<>
	struct	AtomicExchange<Int8u>
	{
		static inline Int8u	call (Int8u* target, Int8u value)
		{
			return ::InterlockedExchange8 (target, value);
		}
	};

	template<>
	struct	AtomicExchange<Int16s>
	{
		static inline Int16s	call (Int16s* target, Int16s value)
		{
			return ::InterlockedExchange16 (target, value);
		}
	};

	template<>
	struct	AtomicExchange<Int16u>
	{
		static inline Int16u	call (Int16u* target, Int16u value)
		{
			return ::InterlockedExchange16 (target, value);
		}
	};

	template<>
	struct	AtomicExchange<Int32s>
	{
		static inline Int32s	call (Int32s* target, Int32s value)
		{
			return ::InterlockedExchange32 (target, value);
		}
	};

	template<>
	struct	AtomicExchange<Int32u>
	{
		static inline Int32u	call (Int32u* target, Int32u value)
		{
			return ::InterlockedExchange32 (target, value);
		}
	};
}
#else
	#error "Glay::Parallel::Atomic can't be used on unsupported configuration"
#endif

GLAY_NS_BEGIN(Parallel)

void	Atomic::barrier ()
{
	AtomicBarrier::call ();
}
/*
Int8s	Atomic::compare (Int8s* target, Int8s current, Int8s replace)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int8u	Atomic::compare (Int8u* target, Int8u current, Int8u replace)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int16s	Atomic::compare (Int16s* target, Int16s current, Int16s replace)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int16u	Atomic::compare (Int16u* target, Int16u current, Int16u replace)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (static_cast<LONG> (target), static_cast<LONG> (replace), static_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int32s	Atomic::compare (Int32s* target, Int32s current, Int32s replace)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int32u	Atomic::compare (Int32u* target, Int32u current, Int32u replace)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

void*	Atomic::compare (void** target, void* current, void* replace)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	::InterlockedCompareExchange (reinterpret_cast<LONG> (target), reinterpret_cast<LONG> (replace), reinterpret_cast<LONG> (current));
#else
	return atomicCompare (target, current, replace);
#endif
}

Int8s	Atomic::decrement (Int8s* target, Int8s value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicDecrement (target, value);
#endif
}

Int8u	Atomic::decrement (Int8u* target, Int8u value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicDecrement (target, value);
#endif
}

Int16s	Atomic::decrement (Int16s* target, Int16s value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicDecrement (target, value);
#endif
}

Int16u	Atomic::decrement (Int16u* target, Int16u value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicDecrement (target, value);
#endif
}

Int32s	Atomic::decrement (Int32s* target, Int32s value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedAdd (target, value);
#else
	return atomicDecrement (target, value);
#endif
}

Int32u	Atomic::decrement (Int32u* target, Int32u value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicDecrement (target, value);
#endif
}
*/
Int8s	Atomic::exchange (Int8s* target, Int8s value)
{
	return AtomicExchange<Int8s>::call (target, value);
}

Int8u	Atomic::exchange (Int8u* target, Int8u value)
{
	return AtomicExchange<Int8u>::call (target, value);
}

Int16s	Atomic::exchange (Int16s* target, Int16s value)
{
	return AtomicExchange<Int16s>::call (target, value);
}

Int16u	Atomic::exchange (Int16u* target, Int16u value)
{
	return AtomicExchange<Int16u>::call (target, value);
}

Int32s	Atomic::exchange (Int32s* target, Int32s value)
{
	return AtomicExchange<Int32s>::call (target, value);
}

Int32u	Atomic::exchange (Int32u* target, Int32u value)
{
	return AtomicExchange<Int32u>::call (target, value);
}

void*	Atomic::exchange (void** target, void* value)
{
	return AtomicExchange<void*>::call (target, value);
}
/*
Int8s	Atomic::increment (Int8s* target, Int8s value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicIncrement (target, value);
#endif
}

Int8u	Atomic::increment (Int8u* target, Int8u value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicIncrement (target, value);
#endif
}

Int16s	Atomic::increment (Int16s* target, Int16s value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicIncrement (target, value);
#endif
}

Int16u	Atomic::increment (Int16u* target, Int16u value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicIncrement (target, value);
#endif
}

Int32s	Atomic::increment (Int32s* target, Int32s value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	return ::InterlockedAdd (target, value);
#else
	return atomicIncrement (target, value);
#endif
}

Int32u	Atomic::increment (Int32u* target, Int32u value)
{
#if defined(GLAY_SYSTEM_WINDOWS) && defined(GLAY_PARALLEL_ATOMIC_NATIVE)
	#error FIXME
#else
	return atomicIncrement (target, value);
#endif
}
*/

GLAY_NS_END()
