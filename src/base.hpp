
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
	#define GLAY_SYSTEM_MAXOSX
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

	const Float32 FLOAT32_MAX = std::numeric_limits<Float32>::max ();
	const Float32 FLOAT32_MIN = std::numeric_limits<Float32>::min ();

	const Float64 FLOAT64_MAX = std::numeric_limits<Float64>::max ();
	const Float64 FLOAT64_MIN = std::numeric_limits<Float64>::min ();

	const Int8s INT8S_MAX = std::numeric_limits<Int8s>::max ();
	const Int8s INT8S_MIN = std::numeric_limits<Int8s>::min ();

	const Int8u INT8U_MAX = std::numeric_limits<Int8u>::max ();
	const Int8u INT8U_MIN = std::numeric_limits<Int8u>::min ();

	const Int16s INT16S_MAX = std::numeric_limits<Int16s>::max ();
	const Int16s INT16S_MIN = std::numeric_limits<Int16s>::min ();

	const Int16u INT16U_MAX = std::numeric_limits<Int16u>::max ();
	const Int16u INT16U_MIN = std::numeric_limits<Int16u>::min ();

	const Int32s INT32S_MAX = std::numeric_limits<Int32s>::max ();
	const Int32s INT32S_MIN = std::numeric_limits<Int32s>::min ();

	const Int32u INT32U_MAX = std::numeric_limits<Int32u>::max ();
	const Int32u INT32U_MIN = std::numeric_limits<Int32u>::min ();

	const Int64s INT64S_MAX = std::numeric_limits<Int64s>::max ();
	const Int64s INT64S_MIN = std::numeric_limits<Int64s>::min ();

	const Int64u INT64U_MAX = std::numeric_limits<Int64u>::max ();
	const Int64u INT64U_MIN = std::numeric_limits<Int64u>::min ();
};

#endif
