
#include "reader.hpp"

GLAY_NS_BEGIN(Pipe)

Reader::Reader (const Reader& other) :
	stream (other.stream)
{
}

Reader::Reader (IStream& stream) :
	stream (stream)
{
}

Reader::~Reader ()
{
}

Reader::operator bool () const
{
	return (bool)this->stream;
}

size_t Reader::read (void* buffer, size_t length)
{
	return this->stream.read (buffer, length);
}

GLAY_NS_END()
