
#include "binary.hpp"

GLAY_NS_BEGIN(Pipe)

template<typename T>
bool	BinaryReader::read (T* value)
{
	return this->stream.read (value, sizeof (*value)) == sizeof (*value);
}

template<typename T>
T	BinaryReader::read ()
{
	T	value;

	this->stream.read (&value, sizeof (value));

	return value;
}

GLAY_NS_END()
