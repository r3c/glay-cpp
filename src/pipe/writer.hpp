
#ifndef __GLAY_PIPE_WRITER_HPP
#define __GLAY_PIPE_WRITER_HPP

#include <cstdint>
#include "../config.hpp"
#include "stream.hpp"

GLAY_NS_BEGIN(Pipe)

class Writer
{
	public:
		Writer (Writer const&);
		Writer (OStream&);
		virtual ~Writer ();

		Writer& operator = (Writer const&);
		virtual operator bool () const;

		void flush ();
		Size write (void const*, Size);

	protected:
		OStream& stream;
};

GLAY_NS_END()

#endif
