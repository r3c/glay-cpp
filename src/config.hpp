
/*
** Groundwork Layer Library
** Global configuration.
*/

#ifndef __GLAY_CONFIG_HPP
#define __GLAY_CONFIG_HPP

#include <stdint.h>

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

namespace	Glay
{
	typedef int8_t		Int8s;
	typedef uint8_t		Int8u;

	typedef int16_t		Int16s;
	typedef uint16_t	Int16u;

	typedef int32_t		Int32s;
	typedef uint32_t	Int32u;

	typedef int64_t		Int64s;
	typedef uint64_t	Int64u;
};

#endif
