
#include "format.hpp"

#include "../../system/convert.hpp"

using namespace std;
using namespace Glay;
using namespace Glay::System;

namespace
{
	template<typename T>
	static inline void writeConvert (Pipe::OStream& stream, Size (*converter) (char*, Size, T), T value)
	{
		char buffer[64];
		Size length = converter (buffer, sizeof (buffer) / sizeof (*buffer), value);

		stream.write (buffer, length * sizeof (*buffer));
	}
}

GLAY_NS_BEGIN(Pipe)

FormatWriter::FormatWriter (FormatWriter const& other) :
	Writer (other.stream)
{
}

FormatWriter::FormatWriter (OStream& stream) :
	Writer (stream)
{
}

FormatWriter& FormatWriter::write (Float32 value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Float64 value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Int8s value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Int8u value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Int16s value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Int16u value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Int32s value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Int32u value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Int64s value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (Int64u value)
{
	writeConvert (this->stream, Convert::toString, value);

	return *this;
}

FormatWriter& FormatWriter::write (char value)
{
	this->stream.write (&value, sizeof (value));

	return *this;
}

FormatWriter& FormatWriter::write (string const& value)
{
	char const* buffer = value.data ();

	this->stream.write (buffer, value.length () * sizeof (*buffer));

	return *this;
}

GLAY_NS_END()
