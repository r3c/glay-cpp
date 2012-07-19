
#ifndef __GLAY_PIPE_READER_HPP
#define __GLAY_PIPE_READER_HPP

#include <stdint.h>
#include "../config.hpp"
#include "stream.hpp"

GLAY_NS_BEGIN(Pipe)

class	Reader
{
	public:
		virtual		~Reader () {};

		operator	bool () const;

		size_t		read (void*, size_t);

	protected:
		/**/		Reader (IStream&);

		IStream&	stream;
};

GLAY_NS_END()

#endif
