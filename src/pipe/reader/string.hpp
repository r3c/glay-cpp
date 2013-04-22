
#ifndef __GLAY_PIPE_READER_STRING_HPP
#define __GLAY_PIPE_READER_STRING_HPP

#include <string>
#include "../../config.hpp"
#include "../reader.hpp"

GLAY_NS_BEGIN(Pipe)

class	StringReader : public Reader
{
	public:
		StringReader (const StringReader&);
		StringReader (IStream&);

		StringReader&	operator = (const StringReader&);

		bool	readCString (std::string*);
		bool	readString (std::string*, Int32u);
};

GLAY_NS_END()

#endif
