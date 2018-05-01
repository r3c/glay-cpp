
#ifndef __GLAY_PIPE_WRITER_FORMAT_HPP
#define __GLAY_PIPE_WRITER_FORMAT_HPP

#include <string>
#include "../../config.hpp"
#include "../writer.hpp"

GLAY_NS_BEGIN(Pipe)

class FormatWriter : public Writer
{
	public:
		FormatWriter (FormatWriter const&);
		FormatWriter (OStream&);

		FormatWriter& operator = (FormatWriter const&);

		FormatWriter& write (Float32);
		FormatWriter& write (Float64);
		FormatWriter& write (Int8s);
		FormatWriter& write (Int8u);
		FormatWriter& write (Int16s);
		FormatWriter& write (Int16u);
		FormatWriter& write (Int32s);
		FormatWriter& write (Int32u);
		FormatWriter& write (Int64s);
		FormatWriter& write (Int64u);
		FormatWriter& write (char);
		FormatWriter& write (std::string const&);
};

GLAY_NS_END()

#endif
