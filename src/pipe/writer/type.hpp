
#ifndef __GLAY_PIPE_WRITER_TYPE_HPP
#define __GLAY_PIPE_WRITER_TYPE_HPP

#include "../writer.hpp"

GLAY_NS_BEGIN(Pipe)

class	TypeWriter : public Writer
{
	public:
		TypeWriter (const TypeWriter&);
		TypeWriter (OStream&);

		template<typename T>
		bool	write (const T&);
};

GLAY_NS_END()

#include "type.hxx"

#endif
