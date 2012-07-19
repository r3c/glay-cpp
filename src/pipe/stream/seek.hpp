
#ifndef __GLAY_PIPE_SEEKSTREAM_HPP
#define __GLAY_PIPE_SEEKSTREAM_HPP

#include "../stream.hpp"

GLAY_NS_BEGIN(Pipe)

class	SeekStream : public Stream
{
	public:
		enum	SeekMode
		{
			SEEK_ABSOLUTE,
			SEEK_RELATIVE
		};

		virtual				~SeekStream () {};

		virtual operator	bool () const = 0;

		virtual void		seek (size_t, SeekMode = SEEK_ABSOLUTE) = 0;
};

GLAY_NS_END()

#endif
