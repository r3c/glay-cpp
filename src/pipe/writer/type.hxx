
#include "type.hpp"

GLAY_NS_BEGIN(Pipe)

template<typename T>
bool	TypeWriter::write (const T* buffer)
{
	return this->stream.write (buffer, sizeof (T)) == sizeof (T);
}

GLAY_NS_END()
