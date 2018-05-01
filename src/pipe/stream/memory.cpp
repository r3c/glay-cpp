
#include "memory.hpp"

#include <cstdlib>
#include <cstring>

using namespace std;

GLAY_NS_BEGIN(Pipe)

/**
** MemoryStream
** Abstract stream on memory buffer.
**/
MemoryStream::MemoryStream (MemoryStream const& other) :
	SeekStream (other),
	capacity (other.capacity),
	cursor (other.cursor)
{
}

MemoryStream::MemoryStream (Size capacity) :
	capacity (capacity),
	cursor (0)
{
}

Size MemoryStream::getPosition () const
{
	return this->cursor;
}

bool MemoryStream::seek (Size offset, SeekMode mode)
{
	Size position;

	switch (mode)
	{
		case SEEK_ABSOLUTE:
			position = offset;

			break;

		case SEEK_RELATIVE:
			position = this->cursor + offset;

			break;

		case SEEK_REVERSE:
			if (offset > this->capacity)
				return false;

			position = this->capacity - offset;

			break;

		default:
			return false;
	}

	if (position > this->capacity)
		return false;

	this->cursor = position;

	return true;
}

/**
** MemoryIStream
** In-memory readable stream.
**/
MemoryIStream::MemoryIStream (MemoryIStream const& other) :
	SeekStream (other),
	MemoryStream (other),	
	source (other.source)
{
}

MemoryIStream::MemoryIStream (void const* source, Size capacity) :
	MemoryStream (capacity),
	source (static_cast<Int8s const*> (source))
{
}

MemoryIStream& MemoryIStream::operator = (MemoryIStream const& other)
{
	MemoryStream::operator = (other);
	SeekStream::operator = (other);

	this->source = other.source;

	return *this;
}

MemoryIStream::operator bool () const
{
	return true;
}

Int8s const* MemoryIStream::getBuffer () const
{
	return this->source;
}

Size MemoryIStream::getSize () const
{
	return this->cursor;
}

Size MemoryIStream::read (void* target, Size size)
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
MemoryOStream::MemoryOStream (MemoryOStream const& other) :
	SeekStream (other),
	MemoryStream (other),
	allocate (false),
	target (other.target)
{
}

MemoryOStream::MemoryOStream (void* buffer, Size capacity) :
	MemoryStream (capacity),
	allocate (false),
	target (static_cast<Int8s*> (buffer))
{
}

MemoryOStream::MemoryOStream () :
	MemoryStream (0),
	allocate (true),
	target (0)
{
}

MemoryOStream::~MemoryOStream ()
{
	if (this->allocate && this->target)
		free (this->target);
}

MemoryOStream& MemoryOStream::operator = (MemoryOStream const& other)
{
	MemoryStream::operator = (other);
	SeekStream::operator = (other);

	this->allocate = false;
	this->target = other.target;

	return *this;
}

MemoryOStream::operator bool () const
{
	return true;
}

Int8s const* MemoryOStream::getBuffer () const
{
	return this->target;
}

Int8s* MemoryOStream::getBuffer ()
{
	return this->target;
}

Size MemoryOStream::getSize () const
{
	return this->capacity;
}

void MemoryOStream::flush ()
{
}

Size MemoryOStream::write (void const* source, Size size)
{
	Size capacity;
	Int8s* swap;

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
