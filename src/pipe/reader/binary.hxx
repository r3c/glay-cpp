
#include "binary.hpp"

GLAY_NS_BEGIN(Pipe)

template<typename T>
T	BinaryReader::read ()
{
	T	value;

	this->read (&value, sizeof (value));

	return value;
	
}

GLAY_NS_END()
