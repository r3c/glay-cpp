
#ifndef __GLAY_PIPE_READER_TYPE_HPP
#define __GLAY_PIPE_READER_TYPE_HPP

#include "../reader.hpp"

GLAY_NS_BEGIN(Pipe)

class	TypeReader : public Reader
{
	public:
		TypeReader (const TypeReader&);
		TypeReader (IStream&);

		TypeReader&	operator = (const TypeReader&);

		template<typename T>
		bool	read (T*);
};

GLAY_NS_END()

#include "type.hxx"

#endif
