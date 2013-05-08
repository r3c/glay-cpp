
/*
** Groundwork Layer Library
** Master setup.
*/

#ifndef __GLAY_SETUP_HPP
#define __GLAY_SETUP_HPP

#include <cstdint>

#define GLAY_NS_BEGIN(ns)	namespace Glay { namespace ns {
#define GLAY_NS_END()		}; };

#if defined(__GNUG__)
	#define GLAY_COMPILER_GCC
#endif

#if defined(__APPLE__)
	#define GLAY_SYSTEM_MAXOSX
#elif defined(__linux__)
	#define GLAY_SYSTEM_UNIX
#elif defined(__WIN32__) || defined(__WIN64__)
	#define GLAY_SYSTEM_WINDOWS

	#define _WIN32_WINNT	0x0502
	#define WINVER			0x0502
#endif

namespace	Glay
{
	typedef float		Float32;
	typedef double		Float64;

	typedef int8_t		Int8s;
	typedef uint8_t		Int8u;

	typedef int16_t		Int16s;
	typedef uint16_t	Int16u;

	typedef int32_t		Int32s;
	typedef uint32_t	Int32u;

	typedef int64_t		Int64s;
	typedef uint64_t	Int64u;

	const Int8s		INT8S_MAX = +0x7F;
	const Int8s		INT8S_MIN = -0x80;

	const Int8u		INT8U_MAX = +0xFF;
	const Int8u		INT8U_MIN = +0x00;

	const Int16s	INT16S_MAX = +0x7FFF;
	const Int16s	INT16S_MIN = -0x8000;

	const Int16u	INT16U_MAX = +0xFFFF;
	const Int16u	INT16U_MIN = +0x0000;

	const Int32s	INT32S_MAX = +0x7FFFFFFFL;
	const Int32s	INT32S_MIN = -0x80000000L;

	const Int32u	INT32U_MAX = +0xFFFFFFFFLU;
	const Int32u	INT32U_MIN = +0x00000000LU;

	const Int64s	INT64S_MAX = +0x7FFFFFFFFFFFFFFFLL;
	const Int64s	INT64S_MIN = -0x8000000000000000LL;

	const Int64u	INT64U_MAX = +0xFFFFFFFFFFFFFFFFLLU;
	const Int64u	INT64U_MIN = +0x0000000000000000LLU;
};

#endif
