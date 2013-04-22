
#include "string.hpp"

using namespace std;

GLAY_NS_BEGIN(Pipe)

StringWriter::StringWriter (OStream& stream) :
	Writer (stream)
{
}

bool	StringWriter::writeCString (const string& source)
{
	char	zero;

	zero = '\0';

	return
		this->write (source.c_str (), source.length ()) == source.length () &&
		this->write (&zero, sizeof (zero)) == sizeof (zero);
}

bool	StringWriter::writeString (const string& source)
{
	return this->write (source.c_str (), source.length ()) == source.length ();
}

GLAY_NS_END()
