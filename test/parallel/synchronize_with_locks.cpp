
#include <cassert>
#include <iostream>
#include <vector>
#include "../../src/glay.hpp"

using namespace std;
using namespace Glay::Parallel;

typedef pair<vector<int>*, Lock*>	MyParams;
typedef Thread<MyParams>			MyThread;

void	worker (MyParams params)
{
	Lock&			lock = *params.second;
	vector<int>&	values = *params.first;

	for (int i = 0; i < 1000; ++i)
	{
		lock.acquire ();

		values.push_back (i);

		lock.release ();
	}
}

int	main (int, char* [])
{
	Lock		lock;
	vector<int>	values;
	MyThread	thread1 (&worker);
	MyThread	thread2 (&worker);
	MyThread	thread3 (&worker);

	thread1.start (make_pair (&values, &lock));
	thread2.start (make_pair (&values, &lock));
	thread3.start (make_pair (&values, &lock));
	thread1.join ();
	thread2.join ();
	thread3.join ();

	assert (values.size () == 3000);

	return 0;
}
