
#include "endian.hpp"

using namespace Glay;
using namespace Glay::System;

namespace
{
	static inline Endian::Endianness findNativeEndianness ()
	{
		Int16u value;

		value = 0x0102;

		switch (*reinterpret_cast<Int8s*> (&value))
		{
			case 0x02:
				return Endian::LITTLE;

			default:
				return Endian::BIG;
		}
	}

	Endian::Endianness const native = findNativeEndianness ();
}

GLAY_NS_BEGIN(System)

Int16s Endian::change16s (Int16s input, Endianness from, Endianness to)
{
	Int16s output;
	Int8s* source;
	Int8s* target;

	if (from == to)
		return input;

	source = reinterpret_cast<Int8s*> (&input);
	target = reinterpret_cast<Int8s*> (&output);

	target[0] = source[1];
	target[1] = source[0];

	return output;
}

Int16u Endian::change16u (Int16u input, Endianness from, Endianness to)
{
	Int16u output;
	Int8s* source;
	Int8s* target;

	if (from == to)
		return input;

	source = reinterpret_cast<Int8s*> (&input);
	target = reinterpret_cast<Int8s*> (&output);

	target[0] = source[1];
	target[1] = source[0];

	return output;
}

Int32s Endian::change32s (Int32s input, Endianness from, Endianness to)
{
	Int32s output;
	Int8s* source;
	Int8s* target;

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

Int32u Endian::change32u (Int32u input, Endianness from, Endianness to)
{
	Int32u output;
	Int8s* source;
	Int8s* target;

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

Int64s Endian::change64s (Int64s input, Endianness from, Endianness to)
{
	Int64s output;
	Int8s* source;
	Int8s* target;

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

Int64u Endian::change64u (Int64u input, Endianness from, Endianness to)
{
	Int64u output;
	Int8s* source;
	Int8s* target;

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

Endian::Endianness Endian::getNativeEndianness ()
{
	return native;
}

/*
** Copy constructor.
** other: source instance
*/
Endian::Endian (Endian const& other) :
	from (other.from)
{
}

/*
** Endianness constructor.
** from: source endianness
*/
Endian::Endian (Endianness from) :
	from (from)
{
}

/*
** Default constructor, using native endianness as source.
*/
Endian::Endian () :
	from (native)
{
}

/*
** Copy operator.
*/
Endian& Endian::operator = (Endian const& other)
{
	this->from = other.from;

	return *this;
}

/*
** Change endianness of signed 16 bits integer.
** input: input integer
** to: target endianness
** return: changed integer
*/ 
Int16s Endian::change16s (Int16s input, Endianness to) const
{
	return Endian::change16s (input, this->from, to);
}

/*
** Change endianness of unsigned 16 bits integer.
** input: input integer
** to: target endianness
** return: changed integer
*/ 
Int16u Endian::change16u (Int16u input, Endianness to) const
{
	return Endian::change16u (input, this->from, to);
}

/*
** Change endianness of signed 32 bits integer.
** input: input integer
** to: target endianness
** return: changed integer
*/ 
Int32s Endian::change32s (Int32s input, Endianness to) const
{
	return Endian::change32s (input, this->from, to);
}

/*
** Change endianness of unsigned 32 bits integer.
** input: input integer
** to: target endianness
** return: changed integer
*/ 
Int32u Endian::change32u (Int32u input, Endianness to) const
{
	return Endian::change32u (input, this->from, to);
}

/*
** Change endianness of signed 64 bits integer.
** input: input integer
** to: target endianness
** return: changed integer
*/ 
Int64s Endian::change64s (Int64s input, Endianness to) const
{
	return Endian::change64s (input, this->from, to);
}

/*
** Change endianness of unsigned 64 bits integer.
** input: input integer
** to: target endianness
** return: changed integer
*/ 
Int64u Endian::change64u (Int64u input, Endianness to) const
{
	return Endian::change64u (input, this->from, to);
}

GLAY_NS_END()
