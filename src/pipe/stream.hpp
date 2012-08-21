
#ifndef __GLAY_PIPE_STREAM_HPP
#define __GLAY_PIPE_STREAM_HPP

#include <stddef.h>
#include <stdint.h>
#include "../config.hpp"

GLAY_NS_BEGIN(Pipe)

class	IStream
{
	public:
		virtual			~IStream () {};

		virtual 		operator bool () const = 0;

		virtual size_t	read (void*, size_t) = 0;
};

class	OStream
{
	public:
		virtual			~OStream () {};

		virtual			operator bool () const = 0;

		virtual size_t	write (const void*, size_t) = 0;
};

GLAY_NS_END()

#endif
