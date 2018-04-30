
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
		MemoryStream (const MemoryStream&);
		MemoryStream (Size);

		Size capacity;
		Size cursor;
};

class MemoryIStream : public MemoryStream, public SeekIStream
{
	public:
		MemoryIStream (const MemoryIStream&);
		MemoryIStream (const void*, Size = SIZE_MAX);

		MemoryIStream& operator = (const MemoryIStream&);
		virtual 		operator bool () const;

		const Int8s* getBuffer () const;
		virtual Size getSize () const;

		virtual Size read (void*, Size);

	protected:
		const Int8s* source;
};

class MemoryOStream : public MemoryStream, public SeekOStream
{
	public:
		MemoryOStream (const MemoryOStream&);
		MemoryOStream (void*, Size = SIZE_MAX);
		MemoryOStream ();
		virtual ~MemoryOStream ();

		MemoryOStream& operator = (const MemoryOStream&);
		virtual 		operator bool () const;

		const Int8s* getBuffer () const;
		Int8s* getBuffer ();
		virtual Size getSize () const;

		virtual void flush ();
		virtual Size write (const void*, Size);

	private:
		bool allocate;
		Int8s* target;
};

GLAY_NS_END()

#endif
