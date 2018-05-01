
#include "binary.hpp"

using namespace std;
using namespace Glay::System;

GLAY_NS_BEGIN(Pipe)

BinaryWriter::BinaryWriter (BinaryWriter const& other) :
	Writer (other),
	native (other.native),
	target (other.target)
{
}

BinaryWriter::BinaryWriter (OStream& stream, Endian::Endianness target) :
	Writer (stream),
	target (target)
{
}

BinaryWriter::BinaryWriter (OStream& stream) :
	Writer (stream),
	target (Endian::getNativeEndianness ())
{
}

bool BinaryWriter::writeFloat32 (Float32 value)
{
	return this->stream.write (&value, sizeof (value)) == sizeof (value);
}

bool BinaryWriter::writeFloat64 (Float64 value)
{
	return this->stream.write (&value, sizeof (value)) == sizeof (value);
}

bool BinaryWriter::writeInt8s (Int8s value)
{
	return this->stream.write (&value, sizeof (value)) == sizeof (value);
}

bool BinaryWriter::writeInt8u (Int8u value)
{
	return this->stream.write (&value, sizeof (value)) == sizeof (value);
}

bool BinaryWriter::writeInt16s (Int16s value)
{
	Int16s buffer;

	buffer = this->native.change16s (value, this->target);

	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

bool BinaryWriter::writeInt16u (Int16u value)
{
	Int16u buffer;

	buffer = this->native.change16u (value, this->target);

	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

bool BinaryWriter::writeInt32s (Int32s value)
{
	Int32s buffer;

	buffer = this->native.change32s (value, this->target);

	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

bool BinaryWriter::writeInt32u (Int32u value)
{
	Int32u buffer;

	buffer = this->native.change32u (value, this->target);

	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

bool BinaryWriter::writeInt64s (Int64s value)
{
	Int64s buffer;

	buffer = this->native.change64s (value, this->target);

	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

bool BinaryWriter::writeInt64u (Int64u value)
{
	Int64u buffer;

	buffer = this->native.change64u (value, this->target);

	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

bool BinaryWriter::writeString (string const& value)
{
	char const* buffer;
	Int32u length;

	buffer = value.data ();
	length = value.length ();

	return this->stream.write (buffer, length * sizeof (*buffer)) == length;
}

GLAY_NS_END()
