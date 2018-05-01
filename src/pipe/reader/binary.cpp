
#include "binary.hpp"

using namespace std;
using namespace Glay::System;

GLAY_NS_BEGIN(Pipe)

BinaryReader::BinaryReader (BinaryReader const& other) :
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

bool BinaryReader::readFloat32 (Float32* value)
{
	return this->stream.read (value, sizeof (*value)) == sizeof (*value);
}

Float32 BinaryReader::readFloat32 ()
{
	Float32 value;

	return this->readFloat32 (&value) ? value : 0;
}

bool BinaryReader::readFloat64 (Float64* value)
{
	return this->stream.read (value, sizeof (*value)) == sizeof (*value);
}

Float64 BinaryReader::readFloat64 ()
{
	Float64 value;

	return this->readFloat64 (&value) ? value : 0;
}

bool BinaryReader::readInt8s (Int8s* value)
{
	return this->stream.read (value, sizeof (*value)) == sizeof (*value);
}

Int8s BinaryReader::readInt8s ()
{
	Int8s value;

	return this->readInt8s (&value) ? value : 0;
}

bool BinaryReader::readInt8u (Int8u* value)
{
	return this->stream.read (value, sizeof (*value)) == sizeof (*value);
}

Int8u BinaryReader::readInt8u ()
{
	Int8u value;

	return this->readInt8u (&value) ? value : 0;
}

bool BinaryReader::readInt16s (Int16s* value)
{
	Int16s raw;

	if (this->stream.read (&raw, sizeof (raw)) == sizeof (raw))
	{
		*value = this->source.change16s (raw, this->native);

		return true;
	}

	return false;
}

Int16s BinaryReader::readInt16s ()
{
	Int16s value;

	return this->readInt16s (&value) ? value : 0;
}

bool BinaryReader::readInt16u (Int16u* value)
{
	Int16u raw;

	if (this->stream.read (&raw, sizeof (raw)) == sizeof (raw))
	{
		*value = this->source.change16u (raw, this->native);

		return true;
	}

	return false;
}

Int16u BinaryReader::readInt16u ()
{
	Int16u value;

	return this->readInt16u (&value) ? value : 0;
}

bool BinaryReader::readInt32s (Int32s* value)
{
	Int32s raw;

	if (this->stream.read (&raw, sizeof (raw)) == sizeof (raw))
	{
		*value = this->source.change32s (raw, this->native);

		return true;
	}

	return false;
}

Int32s BinaryReader::readInt32s ()
{
	Int32s value;

	return this->readInt32s (&value) ? value : 0;
}

bool BinaryReader::readInt32u (Int32u* value)
{
	Int32u raw;

	if (this->stream.read (&raw, sizeof (raw)) == sizeof (raw))
	{
		*value = this->source.change32u (raw, this->native);

		return true;
	}

	return false;
}

Int32u BinaryReader::readInt32u ()
{
	Int32u value;

	return this->readInt32u (&value) ? value : 0;
}

bool BinaryReader::readInt64s (Int64s* value)
{
	Int64s raw;

	if (this->stream.read (&raw, sizeof (raw)) == sizeof (raw))
	{
		*value = this->source.change64s (raw, this->native);

		return true;
	}

	return false;
}

Int64s BinaryReader::readInt64s ()
{
	Int64s value;

	return this->readInt64s (&value) ? value : 0;
}

bool BinaryReader::readInt64u (Int64u* value)
{
	Int64u raw;

	if (this->stream.read (&raw, sizeof (raw)) == sizeof (raw))
	{
		*value = this->source.change64u (raw, this->native);

		return true;
	}

	return false;
}

Int64u BinaryReader::readInt64u ()
{
	Int64u value;

	return this->readInt64u (&value) ? value : 0;
}

bool BinaryReader::readString (string* value)
{
	char buffer;
	Int32u length;

	if (!this->readInt32u (&length))
		return false;

	value->reserve (length);

	while (length-- > 0)
	{
		if (this->stream.read (&buffer, sizeof (buffer)) != sizeof (buffer))
			return false;

		value->push_back (buffer);
	}

	return true;
}

string BinaryReader::readString ()
{
	string value;

	return this->readString (&value) ? value : "";
}

GLAY_NS_END()
