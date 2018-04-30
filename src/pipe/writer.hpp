
#ifndef __GLAY_PIPE_WRITER_HPP
#define __GLAY_PIPE_WRITER_HPP

#include <cstdint>
#include "../config.hpp"
#include "stream.hpp"

GLAY_NS_BEGIN(Pipe)

class Writer
{
	public:
		Writer (const Writer&);
		Writer (OStream&);
		virtual ~Writer ();

		Writer& operator = (const Writer&);
		virtual operator bool () const;

		void flush ();
		Size write (const void*, Size);

	protected:
		OStream& stream;
};

GLAY_NS_END()

#endif
