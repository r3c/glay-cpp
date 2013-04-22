
#include "type.hpp"

GLAY_NS_BEGIN(Pipe)

template<typename T>
bool	TypeWriter::write (const T& buffer)
{
	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

GLAY_NS_END()
