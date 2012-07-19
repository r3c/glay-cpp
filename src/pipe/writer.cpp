
#include "writer.hpp"

GLAY_NS_BEGIN(Pipe)

/**/	Writer::Writer (OStream& stream) :
	stream (stream)
{
}

/**/	Writer::operator bool () const
{
	return (bool)this->stream;
}

size_t	Writer::write (const void* buffer, size_t length)
{
	return this->stream.write (buffer, length);
}

size_t	Writer::write (const char* string)
{
	return this->stream.write (string, strlen (string));
}

GLAY_NS_END()
