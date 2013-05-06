
#include <cassert>
#include "../src/include.hpp"

using namespace std;
using namespace Glay;
using namespace Glay::Pipe;

int	main (int, char* [])
{
	Int32u			buffer;
	Int32u			count;	
	MemoryOStream	output;

	for (buffer = 0; buffer < 1024; ++buffer)
		assert (output.write (&buffer, sizeof (buffer)) == sizeof (buffer));

	assert (output.getSize () == 1024 * sizeof (buffer));

	MemoryIStream	input (output.getBuffer (), output.getSize ());

	for (count = 0; input.read (&buffer, sizeof (buffer)) == sizeof (buffer); ++count)
		assert (buffer == count);

	assert (count == 1024);

	return 0;
}
