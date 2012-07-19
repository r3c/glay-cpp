
#include "memory.hpp"

GLAY_NS_BEGIN(Pipe)

/**/	MemoryStream::MemoryStream (void* buffer) :
	buffer (reinterpret_cast<int8_t*> (buffer)),
	rOffset (0),
	wOffset (0)
{
}

MemoryStream::operator	bool () const
{
	return true;
}

size_t	MemoryStream::read (void* buffer, size_t size)
{
	memcpy (buffer, this->buffer + this->rOffset, size);

	this->rOffset += size;

	return size;
}
/*
void	MemoryStream::seek (int offset, SeekMode mode)
{
	switch (mode)
	{
		case SEEK_ABSOLUTE:
			this->rOffset = offset;

			break;

		case SEEK_RELATIVE:
			this->rOffset += offset;

			break;
	}
}
*/
size_t	MemoryStream::write (const void* buffer, size_t size)
{
	memcpy (this->buffer + this->wOffset, buffer, size);

	this->wOffset += size;

	return size;
}

GLAY_NS_END()
