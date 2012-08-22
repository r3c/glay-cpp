
#include "memory.hpp"

GLAY_NS_BEGIN(Pipe)

MemoryStream::MemoryStream (void* buffer) :
	buffer (static_cast<Int8s*> (buffer)),
	offset (0)
{
}

MemoryStream::operator	bool () const
{
	return true;
}

size_t	MemoryStream::read (void* buffer, size_t size)
{
	memcpy (buffer, this->buffer + this->offset, size);

	this->offset += size;

	return size;
}

void	MemoryStream::seek (size_t offset, SeekMode mode)
{
	switch (mode)
	{
		case SEEK_ABSOLUTE:
			this->offset = offset;

			break;

		case SEEK_RELATIVE:
			this->offset += offset;

			break;
	}
}

size_t	MemoryStream::tell () const
{
	return this->offset;
}

size_t	MemoryStream::write (const void* buffer, size_t size)
{
	memcpy (this->buffer + this->offset, buffer, size);

	this->offset += size;

	return size;
}

GLAY_NS_END()
