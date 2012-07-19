
#ifndef __GLAY_PIPE_STREAM_HPP
#define __GLAY_PIPE_STREAM_HPP

#include <stddef.h>
#include <stdint.h>
#include "../config.hpp"

GLAY_NS_BEGIN(Pipe)

class	Stream
{
	public:
		virtual				~Stream () {};

		virtual operator	bool () const = 0;
};

class	IStream : virtual public Stream
{
	public:
		virtual				~IStream () {};

		virtual size_t		read (void*, size_t) = 0;
};

class	OStream : virtual public Stream
{
	public:
		virtual				~OStream () {};

		virtual size_t		write (const void*, size_t) = 0;
};

GLAY_NS_END()

#endif
