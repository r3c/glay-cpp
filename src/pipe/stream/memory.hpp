
#ifndef __GLAY_PIPE_STREAM_MEMORY_HPP
#define __GLAY_PIPE_STREAM_MEMORY_HPP

#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class	MemoryStream : public virtual SeekStream
{
	public:
		virtual void	seek (size_t, SeekMode = SEEK_ABSOLUTE);
		virtual size_t	tell () const;

	protected:
		MemoryStream (const MemoryStream&);
		MemoryStream (size_t, size_t);

		size_t	capacity;
		size_t	cursor;
};

class	MemoryIStream : public MemoryStream, public SeekIStream
{
	public:
		MemoryIStream (const MemoryIStream&);
		MemoryIStream (const void*, size_t = SIZE_MAX);

		MemoryIStream&	operator = (const MemoryIStream&);
		virtual 		operator bool () const;

		const Int8s*	getBuffer () const;
		size_t			getSize () const;

		virtual size_t	read (void*, size_t);

	protected:
		const Int8s*	source;
};

class	MemoryOStream : public MemoryStream, public SeekOStream
{
	public:
		MemoryOStream (const MemoryOStream&);
		MemoryOStream (void*, size_t = SIZE_MAX);
		MemoryOStream ();
		virtual ~MemoryOStream ();

		MemoryOStream&	operator = (const MemoryOStream&);
		virtual 		operator bool () const;

		const Int8s*	getBuffer () const;
		Int8s*			getBuffer ();
		size_t			getSize () const;

		virtual size_t	write (const void*, size_t);

	private:
		bool	allocate;
		Int8s*	target;
};

GLAY_NS_END()

#endif
