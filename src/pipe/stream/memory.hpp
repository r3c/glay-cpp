
#ifndef __GLAY_PIPE_MEMORYSTREAM_HPP
#define __GLAY_PIPE_MEMORYSTREAM_HPP

#include <string.h>
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class	MemoryStream : public SeekIStream, public SeekOStream
{
	public:
		/**/			MemoryStream (void*);

		virtual 		operator bool () const;

		virtual size_t	read (void*, size_t);
		virtual void	seek (size_t, SeekMode = SEEK_ABSOLUTE);
		virtual size_t	tell () const;
		virtual size_t	write (const void*, size_t);

	private:
		Int8s*	buffer;
		size_t	offset;
};

GLAY_NS_END()

#endif
