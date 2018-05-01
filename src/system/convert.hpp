
#ifndef __GLAY_SYSTEM_CONVERT_HPP
#define __GLAY_SYSTEM_CONVERT_HPP

#include "../config.hpp"

GLAY_NS_BEGIN(System)

class Convert
{
	public:
		static bool toFloat (Float32*, char const*, Size);
		static bool toFloat (Float64*, char const*, Size);

		static bool toInteger (Int8s*, char const*, Size);
		static bool toInteger (Int8u*, char const*, Size);
		static bool toInteger (Int16s*, char const*, Size);
		static bool toInteger (Int16u*, char const*, Size);
		static bool toInteger (Int32s*, char const*, Size);
		static bool toInteger (Int32u*, char const*, Size);
		static bool toInteger (Int64s*, char const*, Size);
		static bool toInteger (Int64u*, char const*, Size);

		static Size toString (char*, Size, Float32);
		static Size toString (char*, Size, Float64);
		static Size toString (char*, Size, Int8s);
		static Size toString (char*, Size, Int8u);
		static Size toString (char*, Size, Int16s);
		static Size toString (char*, Size, Int16u);
		static Size toString (char*, Size, Int32s);
		static Size toString (char*, Size, Int32u);
		static Size toString (char*, Size, Int64s);
		static Size toString (char*, Size, Int64u);
};

GLAY_NS_END()

#endif
