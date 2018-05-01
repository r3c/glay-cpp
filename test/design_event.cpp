
#include "../src/glay.hpp"

#include <cassert>
#include <string>

using namespace std;
using namespace Glay::Design;

static int a = 0;

void increment (int i)
{
	a += i;
}

int main (int, char* [])
{
	Event<int> e1;
	Event<std::string const&> e2;
	string s1;
	string s2;

	e1.bind (increment);
	e2.bind ([&] (std::string const& value)
	{
		s1 = value;
	});
	e2.bind ([&] (std::string const& value)
	{
		s2 = value;
	});

	e1.fire (3);
	e1.fire (7);

	assert (a == 10);

	e2.fire ("Hello, World!");

	assert (s1 == "Hello, World!");
	assert (s2 == "Hello, World!");

	e2.clear ();
	e2.fire ("Deleted");

	assert (s1 == "Hello, World!");
	assert (s2 == "Hello, World!");

	return 0;
}
