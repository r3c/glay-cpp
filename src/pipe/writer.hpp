
#ifndef __GLAY_PIPE_WRITER_HPP
#define __GLAY_PIPE_WRITER_HPP

#include <stdint.h>
#include <string.h>
#include "../config.hpp"
#include "stream.hpp"

GLAY_NS_BEGIN(Pipe)

class	Writer
{
	public:
		virtual		~Writer () {};

		operator	bool () const;

		size_t		write (const void*, size_t);
		size_t		write (const char*);

	protected:
		/**/		Writer (OStream&);

		OStream&	stream;
};

GLAY_NS_END()

#endif
