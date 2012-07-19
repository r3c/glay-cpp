
#include "binary.hpp"

using namespace Glay::Runtime;

GLAY_NS_BEGIN(Pipe)

/**/	BinaryWriter::BinaryWriter (OStream& stream, Endian::Endianness target) :
	Writer (stream),
	target (target)
{
}

/**/	BinaryWriter::BinaryWriter (OStream& stream) :
	Writer (stream),
	target (Endian::getNativeEndianness ())
{
}

void	BinaryWriter::write8s (int8_t value)
{
	this->stream.write (&value, sizeof (value));
}

void	BinaryWriter::write8u (uint8_t value)
{
	this->stream.write (&value, sizeof (value));
}

void	BinaryWriter::write16s (int16_t value)
{
	int16_t	buffer;

	buffer = this->native.convert16s (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write16u (uint16_t value)
{
	uint16_t	buffer;

	buffer = this->native.convert16u (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write32f (float value)
{
	this->stream.write (&value, sizeof (value));
}

void	BinaryWriter::write32s (int32_t value)
{
	int32_t	buffer;

	buffer = this->native.convert32s (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write32u (uint32_t value)
{
	uint32_t	buffer;

	buffer = this->native.convert32u (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write64f (double value)
{
	this->stream.write (&value, sizeof (value));
}

void	BinaryWriter::write64s (int64_t value)
{
	int64_t	buffer;

	buffer = this->native.convert64s (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write64u (uint64_t value)
{
	uint64_t	buffer;

	buffer = this->native.convert64u (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

GLAY_NS_END()
