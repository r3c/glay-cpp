
#ifndef __GLAY_SYSTEM_ENDIAN_HPP
#define __GLAY_SYSTEM_ENDIAN_HPP

#include "../config.hpp"

GLAY_NS_BEGIN(System)

class Endian
{
	public:
		enum Endianness
		{
			BIG,
			LITTLE
		};

		static Int16s change16s (Int16s, Endianness, Endianness);
		static Int16u change16u (Int16u, Endianness, Endianness);

		static Int32s change32s (Int32s, Endianness, Endianness);
		static Int32u change32u (Int32u, Endianness, Endianness);

		static Int64s change64s (Int64s, Endianness, Endianness);
		static Int64u change64u (Int64u, Endianness, Endianness);

		static Endianness getNativeEndianness ();

		Endian (const Endian&);
		Endian (Endianness);
		Endian ();

		Endian& operator = (const Endian&);

		Int16s change16s (Int16s, Endianness) const;
		Int16u change16u (Int16u, Endianness) const;

		Int32s change32s (Int32s, Endianness) const;
		Int32u change32u (Int32u, Endianness) const;

		Int64s change64s (Int64s, Endianness) const;
		Int64u change64u (Int64u, Endianness) const;

		Endianness getEndianness () const;

		Endianness setEndianness (Endianness);

	private:
		Endianness from;
};


GLAY_NS_END()

#endif
