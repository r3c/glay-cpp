
#include "reader.hpp"

GLAY_NS_BEGIN(Pipe)

Reader::Reader (Reader const& other) :
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

Size Reader::read (void* buffer, Size length)
{
	return this->stream.read (buffer, length);
}

GLAY_NS_END()
