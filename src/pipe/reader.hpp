
#ifndef __GLAY_PIPE_READER_HPP
#define __GLAY_PIPE_READER_HPP

#include <stdint.h>
#include "../config.hpp"
#include "stream.hpp"

GLAY_NS_BEGIN(Pipe)

class	Reader
{
	public:
		Reader (const Reader&);
		Reader (IStream&);
		virtual	~Reader ();

		Reader&	operator = (const Reader&);
		virtual	operator bool () const;

		size_t	read (void*, size_t);

	protected:
		IStream&	stream;
};

GLAY_NS_END()

#endif
