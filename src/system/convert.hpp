
#ifndef __GLAY_SYSTEM_CONVERT_HPP
#define __GLAY_SYSTEM_CONVERT_HPP

#include "../config.hpp"

GLAY_NS_BEGIN(System)

class Convert
{
	public:
		static bool toFloat (Float32*, char const*, Int32u);
		static bool toFloat (Float64*, char const*, Int32u);

		static bool toInteger (Int8s*, char const*, Int32u);
		static bool toInteger (Int8u*, char const*, Int32u);
		static bool toInteger (Int16s*, char const*, Int32u);
		static bool toInteger (Int16u*, char const*, Int32u);
		static bool toInteger (Int32s*, char const*, Int32u);
		static bool toInteger (Int32u*, char const*, Int32u);
		static bool toInteger (Int64s*, char const*, Int32u);
		static bool toInteger (Int64u*, char const*, Int32u);

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
