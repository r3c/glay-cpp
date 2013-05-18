
#include "binary.hpp"

GLAY_NS_BEGIN(Pipe)

template<typename T>
bool	BinaryWriter::writeType (const T& buffer)
{
	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

GLAY_NS_END()
