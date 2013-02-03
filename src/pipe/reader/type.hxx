
#include "type.hpp"

GLAY_NS_BEGIN(Pipe)

template<typename T>
bool	TypeReader::read (T* buffer)
{
	return this->stream.read (buffer, sizeof (T)) == sizeof (T);
}

GLAY_NS_END()
