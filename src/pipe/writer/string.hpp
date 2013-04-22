
#ifndef __GLAY_PIPE_WRITER_STRING_HPP
#define __GLAY_PIPE_WRITER_STRING_HPP

#include <string>
#include "../../config.hpp"
#include "../writer.hpp"

GLAY_NS_BEGIN(Pipe)

class	StringWriter : public Writer
{
	public:
		StringWriter (const StringWriter&);
		StringWriter (OStream&);

		StringWriter&	operator = (const StringWriter&);

		bool	writeCString (const std::string&);
		bool	writeString (const std::string&);
};

GLAY_NS_END()

#endif
