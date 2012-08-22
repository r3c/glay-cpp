
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

/**
** SeekStream
** Abstract stream with offset jump ability.
**/
SeekStream::~SeekStream ()
{
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
	this->offsets.push_back (this->tell ());
}

GLAY_NS_END()
