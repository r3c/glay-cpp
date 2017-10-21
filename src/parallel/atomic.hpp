
#ifndef __GLAY_PARALLEL_ATOMIC_HPP
#define __GLAY_PARALLEL_ATOMIC_HPP

#include "../config.hpp"
#include "mutex.hpp"

GLAY_NS_BEGIN(Parallel)

class Atomic
{
	public:
		static void barrier ();
/*
		static Int8s compare (Int8s*, Int8s, Int8s);
		static Int8u compare (Int8u*, Int8u, Int8u);
		static Int16s compare (Int16s*, Int16s, Int16s);
		static Int16u compare (Int16u*, Int16u, Int16u);
		static Int32s compare (Int32s*, Int32s, Int32s);
		static Int32u compare (Int32u*, Int32u, Int32u);

		template<typename T>
		static T* compare (T**, T*, T*);

		static Int8s decrement (Int8s*, Int8s);
		static Int8u decrement (Int8u*, Int8u);
		static Int16s decrement (Int16s*, Int16s);
		static Int16u decrement (Int16u*, Int16u);
		static Int32s decrement (Int32s*, Int32s);
		static Int32u decrement (Int32u*, Int32u);
*/
		static Int8s exchange (Int8s*, Int8s);
		static Int8u exchange (Int8u*, Int8u);
		static Int16s exchange (Int16s*, Int16s);
		static Int16u exchange (Int16u*, Int16u);
		static Int32s exchange (Int32s*, Int32s);
		static Int32u exchange (Int32u*, Int32u);
		static void* exchange (void**, void*);

		template<typename T>
		static T* exchange (T**, T*);
/*
		static Int8s increment (Int8s*, Int8s);
		static Int8u increment (Int8u*, Int8u);
		static Int16s increment (Int16s*, Int16s);
		static Int16u increment (Int16u*, Int16u);
		static Int32s increment (Int32s*, Int32s);
		static Int32u increment (Int32u*, Int32u);
*/
};

GLAY_NS_END();

#include "atomic.hxx"

#endif
