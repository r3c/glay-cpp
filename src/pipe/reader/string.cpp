
#include "string.hpp"

#include <sstream>

using namespace std;

GLAY_NS_BEGIN(Pipe)

StringReader::StringReader (IStream& stream) :
	Reader (stream)
{
}

bool	StringReader::readCString (string* target)
{
	stringstream	buffer;
	char			byte;

	while (this->read (&byte, sizeof (byte)) == sizeof (byte) && byte != '\0')
		buffer.put (byte);

	*target = buffer.str ();

	return byte == '\0';
}

bool	StringReader::readString (string* target, Int32u length)
{
	char	byte;

	target->resize (length);

	for (Int32u i = 0; i < length; ++i)
	{
		if (this->read (&byte, sizeof (byte)) != sizeof (byte))
			return false;

		(*target)[i] = byte;
	}

	return true;
}

GLAY_NS_END()
