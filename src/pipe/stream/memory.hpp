
#ifndef __GLAY_PIPE_STREAM_MEMORY_HPP
#define __GLAY_PIPE_STREAM_MEMORY_HPP

#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class MemoryStream : public virtual SeekStream
{
	public:
		virtual Size getPosition () const;

		virtual bool seek (Size, SeekMode = SEEK_ABSOLUTE);

	protected:
		MemoryStream (MemoryStream const&);
		MemoryStream (Size);

		Size capacity;
		Size cursor;
};

class MemoryIStream : public MemoryStream, public SeekIStream
{
	public:
		MemoryIStream (MemoryIStream const&);
		MemoryIStream (void const*, Size = SIZE_MAX);

		MemoryIStream& operator = (MemoryIStream const&);
		virtual 		operator bool () const;

		Int8s const* getBuffer () const;
		virtual Size getSize () const;

		virtual Size read (void*, Size);

	protected:
		Int8s const* source;
};

class MemoryOStream : public MemoryStream, public SeekOStream
{
	public:
		MemoryOStream (MemoryOStream const&);
		MemoryOStream (void*, Size = SIZE_MAX);
		MemoryOStream ();
		virtual ~MemoryOStream ();

		MemoryOStream& operator = (MemoryOStream const&);
		virtual 		operator bool () const;

		Int8s const* getBuffer () const;
		Int8s* getBuffer ();
		virtual Size getSize () const;

		virtual void flush ();
		virtual Size write (void const*, Size);

	private:
		bool allocate;
		Int8s* target;
};

GLAY_NS_END()

#endif
