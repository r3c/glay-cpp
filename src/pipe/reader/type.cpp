
#include "type.hpp"

GLAY_NS_BEGIN(Pipe)

TypeReader::TypeReader (const TypeReader& other) :
	Reader (other)
{
}

TypeReader::TypeReader (IStream& stream) :
	Reader (stream)
{
}

GLAY_NS_END()
