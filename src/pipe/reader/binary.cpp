
#include "binary.hpp"

using namespace std;
using namespace Glay::System;

GLAY_NS_BEGIN(Pipe)

BinaryReader::BinaryReader (const BinaryReader& other) :
	Reader (other),
	native (other.native),
	source (other.source)
{
}

BinaryReader::BinaryReader (IStream& stream, Endian::Endianness source) :
	Reader (stream),
	native (Endian::getNativeEndianness ()),
	source (source)
{
}

BinaryReader::BinaryReader (IStream& stream) :
	Reader (stream),
	native (Endian::getNativeEndianness ())
{
}

Float32	BinaryReader::readFloat32 ()
{
	Float32	value;

	this->stream.read (&value, sizeof (value));

	return value;
}

Float64	BinaryReader::readFloat64 ()
{
	Float64	value;

	this->stream.read (&value, sizeof (value));

	return value;
}

Int8s	BinaryReader::readInt8s ()
{
	Int8s	value;

	this->stream.read (&value, sizeof (value));

	return value;
}

Int8u	BinaryReader::readInt8u ()
{
	Int8u	value;

	this->stream.read (&value, sizeof (value));

	return value;
}

Int16s	BinaryReader::readInt16s ()
{
	Int16s	value;

	this->stream.read (&value, sizeof (value));

	return this->source.change16s (value, this->native);
}

Int16u	BinaryReader::readInt16u ()
{
	Int16u	value;

	this->stream.read (&value, sizeof (value));

	return this->source.change16u (value, this->native);
}

Int32s	BinaryReader::readInt32s ()
{
	Int32s	value;

	this->stream.read (&value, sizeof (value));

	return this->source.change32s (value, this->native);
}

Int32u	BinaryReader::readInt32u ()
{
	Int32u	value;

	this->stream.read (&value, sizeof (value));

	return this->source.change32u (value, this->native);
}

Int64s	BinaryReader::readInt64s ()
{
	Int64s	value;

	this->stream.read (&value, sizeof (value));

	return this->source.change64s (value, this->native);
}

Int64u	BinaryReader::readInt64u ()
{
	Int16u	value;

	this->stream.read (&value, sizeof (value));

	return this->source.change64u (value, this->native);
}

string	BinaryReader::readString ()
{
	char	buffer;
	Int32u	length;
	string	value;

	length = this->readInt32u ();
	value.reserve (length);

	while (length-- > 0)
	{
		if (this->stream.read (&buffer, sizeof (buffer)) != sizeof (buffer))
			return "";

		value.push_back (buffer);
	}

	return value;
}

GLAY_NS_END()
