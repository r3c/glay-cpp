
#include <cassert>
#include <iostream>
#include <vector>
#include "../src/glay.hpp"

using namespace std;
using namespace Glay::Parallel;

typedef pair<vector<int>*, Mutex*>	MyParams;
typedef Thread<MyParams>			MyThread;

void	worker (MyParams params)
{
	Mutex&			mutex = *params.second;
	vector<int>&	values = *params.first;

	for (int i = 0; i < 1000; ++i)
	{
		mutex.acquire ();

		values.push_back (i);

		mutex.release ();
	}
}

int	main (int, char* [])
{
	Mutex		mutex;
	vector<int>	values;
	MyThread	thread1 (&worker);
	MyThread	thread2 (&worker);
	MyThread	thread3 (&worker);

	thread1.start (make_pair (&values, &mutex));
	thread2.start (make_pair (&values, &mutex));
	thread3.start (make_pair (&values, &mutex));
	thread1.join ();
	thread2.join ();
	thread3.join ();

	assert (values.size () == 3000);

	return 0;
}
