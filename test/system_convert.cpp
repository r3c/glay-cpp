
#include <cassert>
#include "../src/include.hpp"

using namespace Glay;
using namespace Glay::System;

static const Float32	epsilon = 0.001;

template<typename T>
bool	equal_approx (T a, T b)
{
	T	delta = a - b;

	return delta <= epsilon && -delta >= -epsilon;
}

int	main (int, char* [])
{
	Float32	float32;
	Float64	float64;
	Int8s	int8s;
	Int8u	int8u;
	Int16s	int16s;
	Int16u	int16u;
	Int32s	int32s;
	Int32u	int32u;
	Int64s	int64s;
	Int64u	int64u;

	assert (Convert::toFloat32 (&float32, "1.0", 3) && equal_approx (float32, 1.0f));
	assert (Convert::toFloat32 (&float32, "-6545.546", 9) && equal_approx (float32, -6545.546f));
	assert (Convert::toFloat32 (&float32, "+1567873.56", 11) && equal_approx (float32, 1567873.56f));

	assert (Convert::toFloat64 (&float64, "1.0", 3) && equal_approx (float64, 1.0));
	assert (Convert::toFloat64 (&float64, "-6545.546", 9) && equal_approx (float64, -6545.546));
	assert (Convert::toFloat64 (&float64, "+1567873.56", 11) && equal_approx (float64, 1567873.56));

	assert (Convert::toInt8s (&int8s, "53", 2) && int8s == 53);
	assert (Convert::toInt8s (&int8s, "-98", 3) && int8s == -98);
	assert (Convert::toInt8s (&int8s, "+127", 4) && int8s == 127);
	assert (Convert::toInt8s (&int8s, "-128", 4) && int8s == -128);
	assert (!Convert::toInt8s (&int8s, "128", 3));

	assert (Convert::toInt8u (&int8u, "0", 1) && int8u == 0);
	assert (Convert::toInt8u (&int8u, "255", 3) && int8u == 255);
	assert (!Convert::toInt8u (&int8u, "-1", 2));

	assert (Convert::toInt16s (&int16s, "0", 1) && int16s == 0);
	assert (Convert::toInt16s (&int16s, "32767", 5) && int16s == 32767);
	assert (Convert::toInt16s (&int16s, "-32768", 6) && int16s == -32768);

	assert (Convert::toInt16u (&int16u, "0", 1) && int16u == 0);
	assert (Convert::toInt16u (&int16u, "65535", 5) && int16u == 65535);
	assert (!Convert::toInt16u (&int16u, "-1", 2));

	assert (Convert::toInt32s (&int32s, "0", 1) && int32s == 0);

	assert (Convert::toInt32u (&int32u, "0", 1) && int32u == 0);

	assert (Convert::toInt64s (&int64s, "0", 1) && int64s == 0);

	assert (Convert::toInt64u (&int64u, "0", 1) && int64u == 0);
}
