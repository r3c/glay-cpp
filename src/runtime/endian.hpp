
#ifndef __GLAY_RUNTIME_ENDIAN_HPP
#define __GLAY_RUNTIME_ENDIAN_HPP

#include <stddef.h>
#include <stdint.h>
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

		static int16_t		convert16s (int16_t, Endianness, Endianness);
		static uint16_t		convert16u (uint16_t, Endianness, Endianness);

		static int32_t		convert32s (int32_t, Endianness, Endianness);
		static uint32_t		convert32u (uint32_t, Endianness, Endianness);

		static int64_t		convert64s (int64_t, Endianness, Endianness);
		static uint64_t		convert64u (uint64_t, Endianness, Endianness);

		static Endianness	getNativeEndianness ();

		/**/		Endian (Endianness);
		/**/		Endian ();

		int16_t		convert16s (int16_t, Endianness) const;
		uint16_t	convert16u (uint16_t, Endianness) const;

		int32_t		convert32s (int32_t, Endianness) const;
		uint32_t	convert32u (uint32_t, Endianness) const;

		int64_t		convert64s (int64_t, Endianness) const;
		uint64_t	convert64u (uint64_t, Endianness) const;

		Endianness	getEndianness () const;

		Endianness	setEndianness (Endianness);

	private:
		Endianness	endianness;
};


GLAY_NS_END()

#endif
