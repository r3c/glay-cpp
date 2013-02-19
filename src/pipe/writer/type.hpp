
#ifndef __GLAY_PIPE_TYPEWRITER_HPP
#define __GLAY_PIPE_TYPEWRITER_HPP

#include "../writer.hpp"

GLAY_NS_BEGIN(Pipe)

class	TypeWriter : public Writer
{
	public:
				TypeWriter (const TypeWriter&);
				TypeWriter (OStream&);
		virtual	~TypeWriter ();

		template<typename T>
		bool	write (const T*);
};

GLAY_NS_END()

#include "type.hxx"

#endif
