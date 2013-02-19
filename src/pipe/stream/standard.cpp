
#include "standard.hpp"

using namespace std;

GLAY_NS_BEGIN(Pipe)

/**
** StandardIStream
** Input stream on a standard STL stream.
**/
StandardIStream::StandardIStream (istream* stream) :
	stream (stream)
{
}

StandardIStream::~StandardIStream ()
{
}

StandardIStream::operator bool () const
{
	return this->stream->good ();
}

size_t	StandardIStream::read (void* buffer, size_t size)
{
	return this->stream->readsome (static_cast<char*> (buffer), size);
}

/**
** StandardOStream
** Output stream on a standard STL stream.
**/
StandardOStream::StandardOStream (ostream* stream) :
	stream (stream)
{
}

StandardOStream::~StandardOStream ()
{
}

StandardOStream::operator bool () const
{
	return this->stream->good ();
}

size_t	StandardOStream::write (const void* buffer, size_t size)
{
	this->stream->write (static_cast<const char*> (buffer), size);

	return this->stream->good () ? size : 0;
}

GLAY_NS_END()
