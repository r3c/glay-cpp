
#include "writer.hpp"

GLAY_NS_BEGIN(Pipe)

Writer::Writer (const Writer& other) :
	stream (other.stream)
{
}

Writer::Writer (OStream& stream) :
	stream (stream)
{
}

Writer::~Writer ()
{
}

Writer::operator bool () const
{
	return (bool)this->stream;
}

size_t	Writer::write (const void* buffer, size_t length)
{
	return this->stream.write (buffer, length);
}

GLAY_NS_END()
