
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

/**
** SeekStream
** Abstract stream with offset jump ability.
**/
SeekStream::SeekStream (const SeekStream& other) :
	offsets (other.offsets)
{
}

SeekStream::SeekStream ()
{
}

SeekStream::~SeekStream ()
{
}

SeekStream&	SeekStream::operator = (const SeekStream& other)
{
	this->offsets = other.offsets;

	return *this;
}

size_t	SeekStream::back ()
{
	size_t	offset;

	if (this->offsets.size () <= 0)
		return 0;

	offset = this->offsets.back ();

	this->offsets.pop_back ();
	this->seek (offset, SEEK_ABSOLUTE);

	return offset;
}

void	SeekStream::mark ()
{
	this->offsets.push_back (this->getPosition ());
}

/**
** SeekIStream
** Input stream with offset jump ability.
**/
SeekIStream::~SeekIStream ()
{
}

/**
** SeekOStream
** Input stream with offset jump ability.
**/
SeekOStream::~SeekOStream ()
{
}

GLAY_NS_END()
