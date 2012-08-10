
#ifndef __GLAY_PARALLEL_ATOMIC_HPP
#define __GLAY_PARALLEL_ATOMIC_HPP

#include "../config.hpp"
#include "lock.hpp"

GLAY_NS_BEGIN(Parallel)

class	Atomic
{
	public:
		static Int8s	Exchange (volatile Int8s*, Int8s);
		static Int8u	Exchange (volatile Int8u*, Int8u);
		static Int16s	Exchange (volatile Int16s*, Int16s);
		static Int16u	Exchange (volatile Int16u*, Int16u);
		static Int32s	Exchange (volatile Int32s*, Int32s);
		static Int32u	Exchange (volatile Int32u*, Int32u);
		static Int64s	Exchange (volatile Int64s*, Int64s);
		static Int64u	Exchange (volatile Int64u*, Int64u);

		template<typename T>
		static T*		Exchange (volatile T**, T*);
};

GLAY_NS_END();

#endif
