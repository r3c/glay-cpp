
#ifndef __GLAY_SYSTEM_CONVERT_HPP
#define __GLAY_SYSTEM_CONVERT_HPP

#include "../config.hpp"

GLAY_NS_BEGIN(System)

class	Convert
{
	public:
		static bool	toFloat32 (Float32*, const char*, Int32u);
		static bool	toFloat64 (Float64*, const char*, Int32u);

		static bool	toInt8s (Int8s*, const char*, Int32u);
		static bool	toInt8u (Int8u*, const char*, Int32u);

		static bool	toInt16s (Int16s*, const char*, Int32u);
		static bool	toInt16u (Int16u*, const char*, Int32u);

		static bool	toInt32s (Int32s*, const char*, Int32u);
		static bool	toInt32u (Int32u*, const char*, Int32u);

		static bool	toInt64s (Int64s*, const char*, Int32u);
		static bool	toInt64u (Int64u*, const char*, Int32u);
};


GLAY_NS_END()

#endif
