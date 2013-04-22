
#ifndef __GLAY_PIPE_STREAM_MEMORY_HPP
#define __GLAY_PIPE_STREAM_MEMORY_HPP

#include <string.h>
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class	MemoryIStream : public SeekIStream
{
	public:
		MemoryIStream (const MemoryIStream&);
		MemoryIStream (const void*, Int32u = INT32U_MAX);
		virtual	~MemoryIStream ();

		MemoryIStream&	operator = (const MemoryIStream&);
		virtual 		operator bool () const;

		virtual size_t	read (void*, size_t);
		virtual void	seek (size_t, SeekMode = SEEK_ABSOLUTE);
		virtual size_t	tell () const;

	protected:
		size_t			capacity;
		size_t			cursor;
		const Int8s*	source;
};

class	MemoryIOStream : public MemoryIStream, public SeekOStream
{
	public:
		MemoryIOStream (const MemoryIOStream&);
		MemoryIOStream (void*, Int32u = INT32U_MAX);
		virtual	~MemoryIOStream ();

		MemoryIOStream&	operator = (const MemoryIOStream&);

		virtual size_t	write (const void*, size_t);

	private:
		Int8s*	target;
};

GLAY_NS_END()

#endif
