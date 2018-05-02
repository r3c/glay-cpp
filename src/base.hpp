
/*
** Groundwork Layer Library
** Master file.
*/

#ifndef __GLAY_BASE_HPP
#define __GLAY_BASE_HPP

#include <cstdint>
#include <limits>

#define GLAY_NS_BEGIN(ns)	namespace Glay { namespace ns {
#define GLAY_NS_END()		}; };

#if defined(__GNUG__)
	#define GLAY_COMPILER_GCC
#endif

#if defined(__APPLE__)
	#define GLAY_SYSTEM_MACOSX
#elif defined(__linux__)
	#define GLAY_SYSTEM_UNIX
#elif defined(__WIN32__) || defined(__WIN64__)
	#define GLAY_SYSTEM_WINDOWS

	#ifndef _WIN32_WINNT
		#define _WIN32_WINNT 0x0502
	#endif

	#ifndef WINVER
		#define WINVER 0x0502
	#endif
#endif

namespace Glay
{
	typedef float Float32;
	typedef double Float64;

	typedef int8_t Int8s;
	typedef uint8_t Int8u;

	typedef int16_t Int16s;
	typedef uint16_t Int16u;

	typedef int32_t Int32s;
	typedef uint32_t Int32u;

	typedef int64_t Int64s;
	typedef uint64_t Int64u;

	typedef std::size_t Size;

	Float32 const FLOAT32_MAX = std::numeric_limits<Float32>::max ();
	Float32 const FLOAT32_MIN = std::numeric_limits<Float32>::min ();

	Float64 const FLOAT64_MAX = std::numeric_limits<Float64>::max ();
	Float64 const FLOAT64_MIN = std::numeric_limits<Float64>::min ();

	Int8s const INT8S_MAX = std::numeric_limits<Int8s>::max ();
	Int8s const INT8S_MIN = std::numeric_limits<Int8s>::min ();

	Int8u const INT8U_MAX = std::numeric_limits<Int8u>::max ();
	Int8u const INT8U_MIN = std::numeric_limits<Int8u>::min ();

	Int16s const INT16S_MAX = std::numeric_limits<Int16s>::max ();
	Int16s const INT16S_MIN = std::numeric_limits<Int16s>::min ();

	Int16u const INT16U_MAX = std::numeric_limits<Int16u>::max ();
	Int16u const INT16U_MIN = std::numeric_limits<Int16u>::min ();

	Int32s const INT32S_MAX = std::numeric_limits<Int32s>::max ();
	Int32s const INT32S_MIN = std::numeric_limits<Int32s>::min ();

	Int32u const INT32U_MAX = std::numeric_limits<Int32u>::max ();
	Int32u const INT32U_MIN = std::numeric_limits<Int32u>::min ();

	Int64s const INT64S_MAX = std::numeric_limits<Int64s>::max ();
	Int64s const INT64S_MIN = std::numeric_limits<Int64s>::min ();

	Int64u const INT64U_MAX = std::numeric_limits<Int64u>::max ();
	Int64u const INT64U_MIN = std::numeric_limits<Int64u>::min ();
};

#endif
