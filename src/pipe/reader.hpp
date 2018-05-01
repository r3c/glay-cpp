
#ifndef __GLAY_PIPE_READER_HPP
#define __GLAY_PIPE_READER_HPP

#include <cstdint>
#include "../config.hpp"
#include "stream.hpp"

GLAY_NS_BEGIN(Pipe)

class Reader
{
	public:
		Reader (Reader const&);
		Reader (IStream&);
		virtual ~Reader ();

		Reader& operator = (Reader const&);
		virtual operator bool () const;

		Size read (void*, Size);

	protected:
		IStream& stream;
};

GLAY_NS_END()

#endif
