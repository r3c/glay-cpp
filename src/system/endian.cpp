
#include "endian.hpp"

using namespace Glay;
using namespace Glay::System;

namespace
{
	static inline Endian::Endianness	findNativeEndianness ()
	{
		Int16u	value;

		value = 0x0102;

		switch (*reinterpret_cast<Int8s*> (&value))
		{
			case 0x02:
				return Endian::LITTLE;

			default:
				return Endian::BIG;
		}
	}

	const Endian::Endianness	native = findNativeEndianness ();
}

GLAY_NS_BEGIN(System)

Int16s	Endian::convert16s (Int16s input, Endianness from, Endianness to)
{
	Int16s	output;
	Int8s*	source;
	Int8s*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<Int8s*> (&input);
	target = reinterpret_cast<Int8s*> (&output);

	target[0] = source[1];
	target[1] = source[0];

	return output;
}

Int16u	Endian::convert16u (Int16u input, Endianness from, Endianness to)
{
	Int16u	output;
	Int8s*	source;
	Int8s*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<Int8s*> (&input);
	target = reinterpret_cast<Int8s*> (&output);

	target[0] = source[1];
	target[1] = source[0];

	return output;
}

Int32s	Endian::convert32s (Int32s input, Endianness from, Endianness to)
{
	Int32s	output;
	Int8s*	source;
	Int8s*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<Int8s*> (&input);
	target = reinterpret_cast<Int8s*> (&output);

	target[0] = source[3];
	target[1] = source[2];
	target[2] = source[1];
	target[3] = source[0];

	return output;
}

Int32u	Endian::convert32u (Int32u input, Endianness from, Endianness to)
{
	Int32u	output;
	Int8s*	source;
	Int8s*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<Int8s*> (&input);
	target = reinterpret_cast<Int8s*> (&output);

	target[0] = source[3];
	target[1] = source[2];
	target[2] = source[1];
	target[3] = source[0];

	return output;
}

Int64s	Endian::convert64s (Int64s input, Endianness from, Endianness to)
{
	Int64s	output;
	Int8s*	source;
	Int8s*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<Int8s*> (&input);
	target = reinterpret_cast<Int8s*> (&output);

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

Int64u	Endian::convert64u (Int64u input, Endianness from, Endianness to)
{
	Int64u	output;
	Int8s*	source;
	Int8s*	target;

	if (from == to)
		return input;

	source = reinterpret_cast<Int8s*> (&input);
	target = reinterpret_cast<Int8s*> (&output);

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

/*
** Endian
** Perform endianness conversions from given fixed endianness.
*/
Endian::Endian (Endianness from) :
	from (from)
{
}

Endian::Endian () :
	from (native)
{
}

Int16s	Endian::convert16s (Int16s input, Endianness to) const
{
	return Endian::convert16s (input, this->from, to);
}

Int16u	Endian::convert16u (Int16u input, Endianness to) const
{
	return Endian::convert16u (input, this->from, to);
}

Int32s	Endian::convert32s (Int32s input, Endianness to) const
{
	return Endian::convert32s (input, this->from, to);
}

Int32u	Endian::convert32u (Int32u input, Endianness to) const
{
	return Endian::convert32u (input, this->from, to);
}

Int64s	Endian::convert64s (Int64s input, Endianness to) const
{
	return Endian::convert64s (input, this->from, to);
}

Int64u	Endian::convert64u (Int64u input, Endianness to) const
{
	return Endian::convert64u (input, this->from, to);
}

GLAY_NS_END()
