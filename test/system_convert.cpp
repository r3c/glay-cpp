
#include <cassert>
#include "../src/include.hpp"

using namespace Glay;
using namespace Glay::System;

static const Float32 epsilon = 0.001;

template<typename T>
bool equal_approx (T a, T b)
{
	T delta = a - b;

	return delta <= epsilon && -delta >= -epsilon;
}

void toFloat ()
{
	Float32 float32;
	Float64 float64;

	assert (Convert::toFloat (&float32, "1.0", 3) && equal_approx (float32, 1.0f));
	assert (Convert::toFloat (&float32, "-6545.546", 9) && equal_approx (float32, -6545.546f));
	assert (Convert::toFloat (&float32, "+1567873.56", 11) && equal_approx (float32, 1567873.56f));

	assert (Convert::toFloat (&float64, ".03", 3) && equal_approx (float64, .03));
	assert (Convert::toFloat (&float64, "-6545.", 6) && equal_approx (float64, -6545.));
	assert (Convert::toFloat (&float64, "+1567873.56", 11) && equal_approx (float64, 1567873.56));

	assert (Convert::toFloat (&float32, "1.0e1", 5) && equal_approx (float32, 1.0e1f));
	assert (Convert::toFloat (&float32, "17.0e-3", 7) && equal_approx (float32, 17.0e-3f));
	assert (Convert::toFloat (&float32, "48.6e12", 7) && equal_approx (float32, 48.6e12f));

	assert (!Convert::toFloat (&float32, "1.0 e1", 6));
	assert (!Convert::toFloat (&float32, ".0-", 3));
	assert (!Convert::toFloat (&float32, "0.0.0", 5));
	assert (!Convert::toFloat (&float32, "..5", 3));
}

void toInteger ()
{
	Int8s int8s;
	Int8u int8u;
	Int16s int16s;
	Int16u int16u;
	Int32s int32s;
	Int32u int32u;
	Int64s int64s;
	Int64u int64u;

	assert (Convert::toInteger (&int8s, "53", 2) && int8s == 53);
	assert (Convert::toInteger (&int8s, "-98", 3) && int8s == -98);
	assert (Convert::toInteger (&int8s, "+127", 4) && int8s == 127);
	assert (Convert::toInteger (&int8s, "-128", 4) && int8s == -128);
	assert (!Convert::toInteger (&int8s, "128", 3));

	assert (Convert::toInteger (&int8u, "0", 1) && int8u == 0);
	assert (Convert::toInteger (&int8u, "255", 3) && int8u == 255);
	assert (!Convert::toInteger (&int8u, "-1", 2));

	assert (Convert::toInteger (&int16s, "0", 1) && int16s == 0);
	assert (Convert::toInteger (&int16s, "32767", 5) && int16s == 32767);
	assert (Convert::toInteger (&int16s, "-32768", 6) && int16s == -32768);

	assert (Convert::toInteger (&int16u, "0", 1) && int16u == 0);
	assert (Convert::toInteger (&int16u, "65535", 5) && int16u == 65535);
	assert (!Convert::toInteger (&int16u, "-1", 2));

	assert (Convert::toInteger (&int32s, "0", 1) && int32s == 0);

	assert (Convert::toInteger (&int32u, "0", 1) && int32u == 0);

	assert (Convert::toInteger (&int64s, "0", 1) && int64s == 0);

	assert (Convert::toInteger (&int64u, "0", 1) && int64u == 0);
}

void toString ()
{
	char buffer[32];
	Int32u length;

	assert ((length = Convert::toString (buffer, 32, 1.0f)) > 0 && !memcmp (buffer, "1", length));
	assert ((length = Convert::toString (buffer, 32, 17.0f)) > 0 && !memcmp (buffer, "17", length));
	assert ((length = Convert::toString (buffer, 32, -42.0f)) > 0 && !memcmp (buffer, "-42", length));
	assert ((length = Convert::toString (buffer, 32, 0.0f)) > 0 && !memcmp (buffer, "0", length));
	assert ((length = Convert::toString (buffer, 32, 1.5f)) > 0 && !memcmp (buffer, "1.5", length));

	assert ((length = Convert::toString (buffer, 32, 1.0d)) > 0 && !memcmp (buffer, "1", length));
	assert ((length = Convert::toString (buffer, 32, 17.0d)) > 0 && !memcmp (buffer, "17", length));
	assert ((length = Convert::toString (buffer, 32, -42.0d)) > 0 && !memcmp (buffer, "-42", length));
	assert ((length = Convert::toString (buffer, 32, 0.0d)) > 0 && !memcmp (buffer, "0", length));
	assert ((length = Convert::toString (buffer, 32, 1.5d)) > 0 && !memcmp (buffer, "1.5", length));

	assert ((length = Convert::toString (buffer, 32, (Int8s)0)) > 0 && !memcmp (buffer, "0", length));
	assert ((length = Convert::toString (buffer, 32, (Int8s)-5)) > 0 && !memcmp (buffer, "-5", length));
	assert ((length = Convert::toString (buffer, 32, (Int8s)-128)) > 0 && !memcmp (buffer, "-128", length));
	assert ((length = Convert::toString (buffer, 32, (Int8s)127)) > 0 && !memcmp (buffer, "127", length));
	assert ((length = Convert::toString (buffer, 2, (Int8s)100)) == 0);
	assert ((length = Convert::toString (buffer, 3, (Int8s)-100)) == 0);

	assert ((length = Convert::toString (buffer, 1, (Int8u)0)) > 0 && !memcmp (buffer, "0", length));
	assert ((length = Convert::toString (buffer, 1, (Int8u)5)) > 0 && !memcmp (buffer, "5", length));
	assert ((length = Convert::toString (buffer, 3, (Int8u)200)) > 0 && !memcmp (buffer, "200", length));
	assert ((length = Convert::toString (buffer, 3, (Int8u)255)) > 0 && !memcmp (buffer, "255", length));
	assert ((length = Convert::toString (buffer, 2, (Int8u)200)) == 0);
}

int main (int, char* [])
{
	toFloat ();
	toInteger ();
	toString ();
}
