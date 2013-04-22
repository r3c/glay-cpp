
#include "type.hpp"

GLAY_NS_BEGIN(Pipe)

TypeWriter::TypeWriter (const TypeWriter& other) :
	Writer (other)
{
}

TypeWriter::TypeWriter (OStream& stream) :
	Writer (stream)
{
}

GLAY_NS_END()
