
#ifndef __GLAY_PIPE_WRITER_FORMAT_HPP
#define __GLAY_PIPE_WRITER_FORMAT_HPP

#include <string>
#include "../../config.hpp"
#include "../writer.hpp"

GLAY_NS_BEGIN(Pipe)

class	FormatWriter : public Writer
{
	public:
		FormatWriter (const FormatWriter&);
		FormatWriter (OStream&);

		FormatWriter&	operator = (const FormatWriter&);

		FormatWriter&	write (Float32);
		FormatWriter&	write (Float64);
		FormatWriter&	write (Int32s);
		FormatWriter&	write (Int32u);
		FormatWriter&	write (Int64s);
		FormatWriter&	write (Int64u);
		FormatWriter&	write (const std::string&);
};

GLAY_NS_END()

#endif
