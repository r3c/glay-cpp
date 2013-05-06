
#include "memory.hpp"

#include <cstdlib>
#include <cstring>

using namespace std;

GLAY_NS_BEGIN(Pipe)

/**
** MemoryStream
** Abstract stream on memory buffer.
**/
MemoryStream::MemoryStream (const MemoryStream& other) :
	SeekStream (other),
	capacity (other.capacity),
	cursor (other.cursor)
{
}

MemoryStream::MemoryStream (Int32u capacity, Int32u cursor) :
	capacity (capacity),
	cursor (cursor)
{
}

void	MemoryStream::seek (Int32u offset, SeekMode mode)
{
	switch (mode)
	{
		case SEEK_ABSOLUTE:
			this->cursor = min (offset, this->capacity);

			break;

		case SEEK_RELATIVE:
			this->cursor = min (this->cursor + offset, this->capacity);

			break;
	}
}

Int32u	MemoryStream::tell () const
{
	return this->cursor;
}

/**
** MemoryIStream
** In-memory readable stream.
**/
MemoryIStream::MemoryIStream (const MemoryIStream& other) :
	SeekStream (other),
	MemoryStream (other),	
	source (other.source)
{
}

MemoryIStream::MemoryIStream (const void* source, Int32u capacity) :
	MemoryStream (capacity, 0),
	source (static_cast<const Int8s*> (source))
{
}

MemoryIStream&	MemoryIStream::operator = (const MemoryIStream& other)
{
	MemoryStream::operator = (other);
	SeekStream::operator = (other);

	this->source = other.source;

	return *this;
}

MemoryIStream::operator	bool () const
{
	return true;
}

const Int8s*	MemoryIStream::getBuffer () const
{
	return this->source;
}

Int32u	MemoryIStream::getSize () const
{
	return this->cursor;
}

Int32u	MemoryIStream::read (void* target, Int32u size)
{
	size = min (size, this->capacity - this->cursor);

	memcpy (target, this->source + this->cursor, size);

	this->cursor += size;

	return size;
}

/**
** MemoryOStream
** In-memory writable stream.
**/
MemoryOStream::MemoryOStream (const MemoryOStream& other) :
	SeekStream (other),
	MemoryStream (other),
	allocate (false),
	target (other.target)
{
}

MemoryOStream::MemoryOStream (void* buffer, Int32u capacity) :
	MemoryStream (capacity, 0),
	allocate (false),
	target (static_cast<Int8s*> (buffer))
{
}

MemoryOStream::MemoryOStream () :
	MemoryStream (0, 0),
	allocate (true),
	target (0)
{
}

MemoryOStream::~MemoryOStream ()
{
	if (this->allocate && this->target)
		free (this->target);
}

MemoryOStream&	MemoryOStream::operator = (const MemoryOStream& other)
{
	MemoryStream::operator = (other);
	SeekStream::operator = (other);

	this->allocate = false;
	this->target = other.target;

	return *this;
}

MemoryOStream::operator	bool () const
{
	return true;
}

const Int8s*	MemoryOStream::getBuffer () const
{
	return this->target;
}

Int8s*	MemoryOStream::getBuffer ()
{
	return this->target;
}

Int32u	MemoryOStream::getSize () const
{
	return this->cursor;
}

Int32u	MemoryOStream::write (const void* source, Int32u size)
{
	Int32u	capacity;
	Int8s*	swap;

	if (this->cursor + size > this->capacity)
	{
		if (this->allocate)
		{
			capacity = max (this->cursor + size, this->capacity * 2);
			swap = static_cast<Int8s*> (realloc (this->target, capacity * sizeof (*this->target)));

			if (!swap)
				return 0;

			this->capacity = capacity;
			this->target = swap;
		}
		else
			size = this->capacity - this->cursor;
	}

	memcpy (this->target + this->cursor, source, size * sizeof (*this->target));

	this->cursor += size;

	return size;
}

GLAY_NS_END()
