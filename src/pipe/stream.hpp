
#ifndef __GLAY_PIPE_STREAM_HPP
#define __GLAY_PIPE_STREAM_HPP

#include <cstddef>
#include <cstdint>
#include "../config.hpp"

GLAY_NS_BEGIN(Pipe)

class IStream
{
	public:
		virtual ~IStream ();

		virtual operator bool () const = 0;

		virtual Size read (void*, Size) = 0;
};

class OStream
{
	public:
		virtual ~OStream ();

		virtual operator bool () const = 0;

		virtual void flush () = 0;
		virtual Size write (void const*, Size) = 0;
};

GLAY_NS_END()

#endif
