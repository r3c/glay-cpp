
#include "binary.hpp"

using namespace Glay::System;

GLAY_NS_BEGIN(Pipe)

/**/	BinaryReader::BinaryReader (IStream& stream, Endian::Endianness source) :
	Reader (stream),
	native (Endian::getNativeEndianness ()),
	source (source)
{
}

/**/	BinaryReader::BinaryReader (IStream& stream) :
	Reader (stream),
	native (Endian::getNativeEndianness ())
{
}

Int8s	BinaryReader::read8s ()
{
	Int8s	value;

	this->read (&value, sizeof (value));

	return value;
}

Int8u	BinaryReader::read8u ()
{
	Int8u	value;

	this->read (&value, sizeof (value));

	return value;
}

Int16s	BinaryReader::read16s ()
{
	Int16s	value;

	this->read (&value, sizeof (value));

	return this->source.convert16s (value, this->native);
}

Int16u	BinaryReader::read16u ()
{
	Int16u	value;

	this->read (&value, sizeof (value));

	return this->source.convert16u (value, this->native);
}

float	BinaryReader::read32f ()
{
	float	value;

	this->read (&value, sizeof (value));

	return value;
}

Int32s	BinaryReader::read32s ()
{
	Int32s	value;

	this->read (&value, sizeof (value));

	return this->source.convert32s (value, this->native);
}

Int32u	BinaryReader::read32u ()
{
	Int32u	value;

	this->read (&value, sizeof (value));

	return this->source.convert32u (value, this->native);
}

double	BinaryReader::read64f ()
{
	double	value;

	this->read (&value, sizeof (value));

	return value;
}

Int64s	BinaryReader::read64s ()
{
	Int64s	value;

	this->read (&value, sizeof (value));

	return this->source.convert64s (value, this->native);
}

Int64u	BinaryReader::read64u ()
{
	Int16u	value;

	this->read (&value, sizeof (value));

	return this->source.convert64u (value, this->native);
}

GLAY_NS_END()
