
#include "memory.hpp"

GLAY_NS_BEGIN(Pipe)

/**
** MemoryIStream
** In-memory readable stream.
**/
MemoryIStream::MemoryIStream (const MemoryIStream& other) :
	SeekStream (other),
	capacity (other.capacity),
	cursor (other.cursor),
	source (other.source)
{
}

MemoryIStream::MemoryIStream (const void* source, Int32u capacity) :
	capacity (capacity),
	cursor (0),
	source (static_cast<const Int8s*> (source))
{
}

MemoryIStream&	MemoryIStream::operator = (const MemoryIStream& other)
{
	SeekStream::operator = (other);

	this->capacity = capacity;
	this->cursor = cursor;
	this->source = source;

	return *this;
}

MemoryIStream::operator	bool () const
{
	return true;
}

size_t	MemoryIStream::read (void* target, size_t size)
{
	size = std::min (size, this->capacity - this->cursor);

	memcpy (target, this->source + this->cursor, size);

	this->cursor += size;

	return size;
}

void	MemoryIStream::seek (size_t offset, SeekMode mode)
{
	switch (mode)
	{
		case SEEK_ABSOLUTE:
			this->cursor = std::min (offset, this->capacity);

			break;

		case SEEK_RELATIVE:
			this->cursor = std::min (this->cursor + offset, this->capacity);

			break;
	}
}

size_t	MemoryIStream::tell () const
{
	return this->cursor;
}

/**
** MemoryIOStream
** In-memory readable and writable stream.
**/
MemoryIOStream::MemoryIOStream (const MemoryIOStream& other) :
	SeekStream (other),
	MemoryIStream (other),
	target (other.target)
{
}

MemoryIOStream::MemoryIOStream (void* buffer, Int32u capacity) :
	MemoryIStream (buffer, capacity),
	target (static_cast<Int8s*> (buffer))
{
}

MemoryIOStream&	MemoryIOStream::operator = (const MemoryIOStream& other)
{
	SeekStream::operator = (other);
	MemoryIStream::operator = (other);

	this->target = other.target;

	return *this;
}

size_t	MemoryIOStream::write (const void* source, size_t size)
{
	size = std::min (size, this->capacity - this->cursor);

	memcpy (this->target + this->cursor, source, size);

	this->cursor += size;

	return size;
}

GLAY_NS_END()
