
#ifndef __GLAY_PARALLEL_ATOMIC_HPP
#define __GLAY_PARALLEL_ATOMIC_HPP

#include <stdint.h>
#include "../config.hpp"
#include "lock.hpp"

GLAY_NS_BEGIN(Parallel)

class	Atomic
{
	public:
		static int8_t	Exchange (volatile int8_t*, int8_t);
		static uint8_t	Exchange (volatile uint8_t*, uint8_t);
		static int16_t	Exchange (volatile int16_t*, int16_t);
		static uint16_t	Exchange (volatile uint16_t*, uint16_t);
		static int32_t	Exchange (volatile int32_t*, int32_t);
		static uint32_t	Exchange (volatile uint32_t*, uint32_t);
		static int64_t	Exchange (volatile int64_t*, int64_t);
		static uint64_t	Exchange (volatile uint64_t*, uint64_t);

		template<typename T>
		static T*		Exchange (volatile T**, T*);
};

GLAY_NS_END();

#endif
