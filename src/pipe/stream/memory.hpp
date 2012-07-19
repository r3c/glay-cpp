
#ifndef __GLAY_PIPE_MEMORYSTREAM_HPP
#define __GLAY_PIPE_MEMORYSTREAM_HPP

#include <string.h>
#include "../stream.hpp"

GLAY_NS_BEGIN(Pipe)

class	MemoryStream : public IStream, public OStream
{
	public:
		/**/				MemoryStream (void*);

		virtual operator	bool () const;

		virtual size_t		read (void*, size_t);

//			virtual void		seek (int, SeekMode);

		virtual size_t		write (const void*, size_t);

	private:
		int8_t*				buffer;
		size_t				rOffset;
		size_t				wOffset;
};

GLAY_NS_END()

#endif
