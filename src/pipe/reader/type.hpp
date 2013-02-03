
#ifndef __GLAY_PIPE_TYPEREADER_HPP
#define __GLAY_PIPE_TYPEREADER_HPP

#include "../reader.hpp"

GLAY_NS_BEGIN(Pipe)

class	TypeReader : public Reader
{
	public:
		/**/		TypeReader (const TypeReader&);
		/**/		TypeReader (IStream&);
		virtual		~TypeReader ();

		TypeReader&	operator = (const TypeReader&);

		template<typename T>
		bool		read(T*);
};

GLAY_NS_END()

#include "type.hxx"

#endif
