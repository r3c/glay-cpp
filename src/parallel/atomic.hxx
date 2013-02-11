
#include "atomic.hpp"

GLAY_NS_BEGIN(Parallel)

/*
template<typename T>
T*	Atomic::compare (T** target, T* current, T* replace)
{
	return Atomic::compare (reinterpret_cast<void**> (target), reinterpret_cast<void*> (current), reinterpret_cast<void*> (replace));
}
*/

template<typename T>
T*	Atomic::exchange (T** target, T* value)
{
	return Atomic::exchange (reinterpret_cast<void**> (target), reinterpret_cast<void*> (value));
}

GLAY_NS_END()
