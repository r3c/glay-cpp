
#ifndef __GLAY_RUNTIME_ENDIAN_HPP
#define __GLAY_RUNTIME_ENDIAN_HPP

#include "../config.hpp"

GLAY_NS_BEGIN(Runtime)

class	Endian
{
	public:
		enum	Endianness
		{
			BIG,
			LITTLE
		};

		static Int16s		convert16s (Int16s, Endianness, Endianness);
		static Int16u		convert16u (Int16u, Endianness, Endianness);

		static Int32s		convert32s (Int32s, Endianness, Endianness);
		static Int32u		convert32u (Int32u, Endianness, Endianness);

		static Int64s		convert64s (Int64s, Endianness, Endianness);
		static Int64u		convert64u (Int64u, Endianness, Endianness);

		static Endianness	getNativeEndianness ();

		/**/		Endian (Endianness);
		/**/		Endian ();

		Int16s		convert16s (Int16s, Endianness) const;
		Int16u		convert16u (Int16u, Endianness) const;

		Int32s		convert32s (Int32s, Endianness) const;
		Int32u		convert32u (Int32u, Endianness) const;

		Int64s		convert64s (Int64s, Endianness) const;
		Int64u		convert64u (Int64u, Endianness) const;

		Endianness	getEndianness () const;

		Endianness	setEndianness (Endianness);

	private:
		Endianness	from;
};


GLAY_NS_END()

#endif
