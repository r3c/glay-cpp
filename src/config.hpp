
/*
** Groundwork Layer Library
** Global configuration.
*/

#ifndef __GLAY_CONFIG_HPP
#define __GLAY_CONFIG_HPP

#include "base.hpp"

#if defined(GLAY_COMPILER_GCC)
	#define GLAY_BUILTIN_ATOMIC
#endif

#if !defined(GLAY_SYSTEM_WINDOWS)
	#define GLAY_LIBRARY_PTHREAD
#endif

#define GLAY_MODULE_PARALLEL_THREAD_STACK_SIZE (16 * 1024 * 1024)
#define GLAY_MODULE_SYSTEM_STOPWATCH_RESOLUTION 1000

#endif
