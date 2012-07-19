
#include "binary.hpp"

using namespace Glay::Runtime;

GLAY_NS_BEGIN(Pipe)

/**/		BinaryReader::BinaryReader (IStream& stream, Endian::Endianness source) :
	Reader (stream),
	native (Endian::getNativeEndianness ()),
	source (source)
{
}

/**/		BinaryReader::BinaryReader (IStream& stream) :
	Reader (stream),
	native (Endian::getNativeEndianness ())
{
}

int8_t		BinaryReader::read8s ()
{
	int8_t	value;

	this->read (&value, sizeof (value));

	return value;
}

uint8_t		BinaryReader::read8u ()
{
	uint8_t	value;

	this->read (&value, sizeof (value));

	return value;
}

int16_t		BinaryReader::read16s ()
{
	int16_t	value;

	this->read (&value, sizeof (value));

	return this->source.convert16s (value, this->native);
}

uint16_t	BinaryReader::read16u ()
{
	uint16_t	value;

	this->read (&value, sizeof (value));

	return this->source.convert16u (value, this->native);
}

float		BinaryReader::read32f ()
{
	float	value;

	this->read (&value, sizeof (value));

	return value;
}

int32_t		BinaryReader::read32s ()
{
	int32_t	value;

	this->read (&value, sizeof (value));

	return this->source.convert32s (value, this->native);
}

uint32_t	BinaryReader::read32u ()
{
	uint32_t	value;

	this->read (&value, sizeof (value));

	return this->source.convert32u (value, this->native);
}

double		BinaryReader::read64f ()
{
	double	value;

	this->read (&value, sizeof (value));

	return value;
}

int64_t		BinaryReader::read64s ()
{
	int64_t	value;

	this->read (&value, sizeof (value));

	return this->source.convert64s (value, this->native);
}

uint64_t	BinaryReader::read64u ()
{
	uint16_t	value;

	this->read (&value, sizeof (value));

	return this->source.convert64u (value, this->native);
}

GLAY_NS_END()
