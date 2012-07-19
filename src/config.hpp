
#ifndef __GLAY_CONFIG_HPP
#define __GLAY_CONFIG_HPP

#include <stddef.h>

#define GLAY_NS_BEGIN(ns)	namespace Glay { namespace ns {
#define GLAY_NS_END()		}; };

#if defined(__APPLE__)
	#define GLAY_OS_MAXOSX
#elif defined(__linux__)
	#define GLAY_OS_UNIX
#elif defined(__WIN32__) || defined(__WIN64__)
	#define GLAY_OS_WINDOWS

	#define _WIN32_WINNT	0x0502
	#define WINVER			0x0502
#endif

#endif
