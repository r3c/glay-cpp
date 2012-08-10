
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

void	BinaryWriter::write8s (Int8s value)
{
	this->stream.write (&value, sizeof (value));
}

void	BinaryWriter::write8u (Int8u value)
{
	this->stream.write (&value, sizeof (value));
}

void	BinaryWriter::write16s (Int16s value)
{
	Int16s	buffer;

	buffer = this->native.convert16s (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write16u (Int16u value)
{
	Int16u	buffer;

	buffer = this->native.convert16u (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write32f (float value)
{
	this->stream.write (&value, sizeof (value));
}

void	BinaryWriter::write32s (Int32s value)
{
	Int32s	buffer;

	buffer = this->native.convert32s (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write32u (Int32u value)
{
	Int32u	buffer;

	buffer = this->native.convert32u (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write64f (double value)
{
	this->stream.write (&value, sizeof (value));
}

void	BinaryWriter::write64s (Int64s value)
{
	Int64s	buffer;

	buffer = this->native.convert64s (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

void	BinaryWriter::write64u (Int64u value)
{
	Int64u	buffer;

	buffer = this->native.convert64u (value, this->target);

	this->stream.write (&buffer, sizeof (buffer));
}

GLAY_NS_END()
