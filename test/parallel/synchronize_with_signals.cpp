
#include <cassert>
#include <iostream>
#include <map>
#include "../../src/glay.hpp"

using namespace std;
using namespace Glay::Parallel;

typedef pair<map<int, int>*, Signal*>	MyParams;
typedef Thread<MyParams>				MyThread;

void	worker (MyParams params)
{
	map<int, int>&	counters = *params.first;
	Signal&			signal = *params.second;

	for (int i = 0; i < 64; ++i)
	{
		signal.wait ();

		++counters[i % 4];

		signal.set ();
	}
}

int	main (int, char* [])
{
	map<int, int>	counters;
	Signal			signal (false, false);
	MyThread**		threads;

	threads = new MyThread*[16];

	for (int i = 0; i < 16; ++i)
	{
		threads[i] = new MyThread (worker);
		threads[i]->start (make_pair(&counters, &signal));
	}

	signal.set ();

	for (int i = 0; i < 16; ++i)
	{
		threads[i]->join ();

		delete threads[i];
	}

	delete [] threads;

	for (int i = 0; i < 4; ++i)
		assert (counters[i] == 256);

	return 0;
}
