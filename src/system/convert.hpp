
#ifndef __GLAY_SYSTEM_CONVERT_HPP
#define __GLAY_SYSTEM_CONVERT_HPP

#include "../config.hpp"

GLAY_NS_BEGIN(System)

class Convert
{
	public:
		static bool toFloat (Float32*, const char*, Int32u);
		static bool toFloat (Float64*, const char*, Int32u);

		static bool toInteger (Int8s*, const char*, Int32u);
		static bool toInteger (Int8u*, const char*, Int32u);
		static bool toInteger (Int16s*, const char*, Int32u);
		static bool toInteger (Int16u*, const char*, Int32u);
		static bool toInteger (Int32s*, const char*, Int32u);
		static bool toInteger (Int32u*, const char*, Int32u);
		static bool toInteger (Int64s*, const char*, Int32u);
		static bool toInteger (Int64u*, const char*, Int32u);

		static Int32u toString (char*, Int32u, Float32);
		static Int32u toString (char*, Int32u, Float64);
		static Int32u toString (char*, Int32u, Int8s);
		static Int32u toString (char*, Int32u, Int8u);
		static Int32u toString (char*, Int32u, Int16s);
		static Int32u toString (char*, Int32u, Int16u);
		static Int32u toString (char*, Int32u, Int32s);
		static Int32u toString (char*, Int32u, Int32u);
		static Int32u toString (char*, Int32u, Int64s);
		static Int32u toString (char*, Int32u, Int64u);
};

GLAY_NS_END()

#endif
