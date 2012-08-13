
#ifndef __GLAY_PARALLEL_ATOMIC_HPP
#define __GLAY_PARALLEL_ATOMIC_HPP

#include "../config.hpp"
#include "lock.hpp"

GLAY_NS_BEGIN(Parallel)

class	Atomic
{
	public:
/*
		static Int8s	compare (Int8s*, Int8s, Int8s);
		static Int8u	compare (Int8u*, Int8u, Int8u);
		static Int16s	compare (Int16s*, Int16s, Int16s);
		static Int16u	compare (Int16u*, Int16u, Int16u);
		static Int32s	compare (Int32s*, Int32s, Int32s);
		static Int32u	compare (Int32u*, Int32u, Int32u);

		template<typename T>
		static T*		compare (T**, T*, T*);
*/
		static Int8s	swap (Int8s*, Int8s);
		static Int8u	swap (Int8u*, Int8u);
		static Int16s	swap (Int16s*, Int16s);
		static Int16u	swap (Int16u*, Int16u);
		static Int32s	swap (Int32s*, Int32s);
		static Int32u	swap (Int32u*, Int32u);

		template<typename T>
		static T*		swap (T**, T*);
};

GLAY_NS_END();

#endif
