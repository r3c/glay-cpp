
#include "writer.hpp"

GLAY_NS_BEGIN(Pipe)

Writer::Writer (Writer const& other) :
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

void Writer::flush ()
{
	this->stream.flush ();
}

Size Writer::write (void const* buffer, Size length)
{
	return this->stream.write (buffer, length);
}

GLAY_NS_END()
