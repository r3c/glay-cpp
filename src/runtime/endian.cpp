
#include "endian.hpp"

using namespace Glay::Runtime;

namespace
{
	static inline Endian::Endianness	findEndianness ()
	{
		uint16_t	value;

		value = 0x0102;

		switch (*reinterpret_cast<int8_t*> (&value))
		{
			case 0x02:
				return Endian::LITTLE;

			default:
				return Endian::BIG;
		}
	}

	const Endian::Endianness	native = findEndianness ();
}

GLAY_NS_BEGIN(Runtime)

int16_t		Endian::convert16s (int16_t input, Endianness from, Endianness to)
{
	int16_t	output;
	int8_t*	source;
	int8_t*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<int8_t*> (&input);
	target = reinterpret_cast<int8_t*> (&output);

	target[0] = source[1];
	target[1] = source[0];

	return output;
}

uint16_t	Endian::convert16u (uint16_t input, Endianness from, Endianness to)
{
	uint16_t	output;
	int8_t*		source;
	int8_t*		target;

	if (from == to)
		return input;

	source = reinterpret_cast<int8_t*> (&input);
	target = reinterpret_cast<int8_t*> (&output);

	target[0] = source[1];
	target[1] = source[0];

	return output;
}

int32_t		Endian::convert32s (int32_t input, Endianness from, Endianness to)
{
	int32_t	output;
	int8_t*	source;
	int8_t*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<int8_t*> (&input);
	target = reinterpret_cast<int8_t*> (&output);

	target[0] = source[3];
	target[1] = source[2];
	target[2] = source[1];
	target[3] = source[0];

	return output;
}

uint32_t	Endian::convert32u (uint32_t input, Endianness from, Endianness to)
{
	uint32_t	output;
	int8_t*		source;
	int8_t*		target;

	if (from == to)
		return input;

	source = reinterpret_cast<int8_t*> (&input);
	target = reinterpret_cast<int8_t*> (&output);

	target[0] = source[3];
	target[1] = source[2];
	target[2] = source[1];
	target[3] = source[0];

	return output;
}

int64_t		Endian::convert64s (int64_t input, Endianness from, Endianness to)
{
	int64_t	output;
	int8_t*	source;
	int8_t*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<int8_t*> (&input);
	target = reinterpret_cast<int8_t*> (&output);

	target[0] = source[7];
	target[1] = source[6];
	target[2] = source[5];
	target[3] = source[4];
	target[4] = source[3];
	target[5] = source[2];
	target[6] = source[1];
	target[7] = source[0];

	return output;
}

uint64_t	Endian::convert64u (uint64_t input, Endianness from, Endianness to)
{
	uint64_t	output;
	int8_t*		source;
	int8_t*		target;

	if (from == to)
		return input;

	source = reinterpret_cast<int8_t*> (&input);
	target = reinterpret_cast<int8_t*> (&output);

	target[0] = source[7];
	target[1] = source[6];
	target[2] = source[5];
	target[3] = source[4];
	target[4] = source[3];
	target[5] = source[2];
	target[6] = source[1];
	target[7] = source[0];

	return output;
}

Endian::Endianness	Endian::getNativeEndianness ()
{
	return native;
}

/**/	Endian::Endian (Endianness endianness) :
	endianness (endianness)
{
}

/**/	Endian::Endian () :
	endianness (native)
{
}

int16_t		Endian::convert16s (int16_t input, Endianness to) const
{
	return Endian::convert16s (input, this->endianness, to);
}

uint16_t	Endian::convert16u (uint16_t input, Endianness to) const
{
	return Endian::convert16u (input, this->endianness, to);
}

int32_t		Endian::convert32s (int32_t input, Endianness to) const
{
	return Endian::convert32s (input, this->endianness, to);
}

uint32_t	Endian::convert32u (uint32_t input, Endianness to) const
{
	return Endian::convert32u (input, this->endianness, to);
}

int64_t		Endian::convert64s (int64_t input, Endianness to) const
{
	return Endian::convert64s (input, this->endianness, to);
}

uint64_t	Endian::convert64u (uint64_t input, Endianness to) const
{
	return Endian::convert64u (input, this->endianness, to);
}

GLAY_NS_END()
