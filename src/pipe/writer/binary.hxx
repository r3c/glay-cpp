
#include "binary.hpp"

GLAY_NS_BEGIN(Pipe)

template<typename T>
bool	BinaryWriter::writeType (T const& buffer)
{
	return this->stream.write (&buffer, sizeof (buffer)) == sizeof (buffer);
}

GLAY_NS_END()
