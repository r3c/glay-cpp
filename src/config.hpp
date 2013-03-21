
/*
** Groundwork Layer Library
** Global configuration.
*/

#ifndef __GLAY_CONFIG_HPP
#define __GLAY_CONFIG_HPP

#include "setup.hpp"

#if defined(GLAY_COMPILER_GCC)
	#define GLAY_BUILTIN_ATOMIC
#endif

#if !defined(GLAY_OS_WINDOWS)
	#define GLAY_LIBRARY_PTHREAD
#endif

#endif
