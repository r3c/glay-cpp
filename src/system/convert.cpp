
#include "convert.hpp"

#include <cstdio>
#include <cstring>
#include <limits>

using namespace Glay;

namespace
{
	template<typename T, bool is_signed>
	struct	Integer
	{
		static inline bool	negative (const T& value)
		{
			return value < 0;
		}
	};

	template<typename T>
	struct	Integer<T, false>
	{
		static inline bool	negative (const T&)
		{
			return false;
		}
	};

	template<typename T>
	static inline Int32u	convertFloatToString (char* target, Int32u length, T value)
	{
		char	buffer[64];
		Int32u	use;

		use = sprintf (buffer, "%.10f", value);

		if (use > length)
			return 0;

		while (use > 1 && buffer[use - 1] == '0')
			--use;

		if (use > 0 && buffer[use - 1] == '.')
			--use;

		memcpy (target, buffer, use * sizeof (*target));

		return use;
	}

	template<typename T>
	static inline Int32u	convertIntegerToString (char* target, Int32u length, T value)
	{
		char	buffer[32];
		Int32u	index;
		bool	negative;
		T		next;
		Int32u	use;

		index = sizeof (buffer) / sizeof (*buffer);
		negative = Integer<T, std::numeric_limits<T>::is_signed>::negative (value);

		if (negative)
			value = -value;

		do
		{
			next = value / 10;

			buffer[--index] = value - next * 10;

			value = next;
		}
		while (value > 0);

		if (negative)
			buffer[--index] = '-';

		use = (sizeof (buffer) / sizeof (*buffer)) - index;

		if (use > length)
			return 0;

		memcpy (target, buffer + index, use * sizeof (*target));

		return use;
	}

	template<typename T>
	static inline bool	convertStringToFloat (T* target, const char* buffer, Int32u length)
	{
		bool	decimal;
		T		multiplier;
		T		value;

		if (length < 1)
			return false;

		decimal = false;
		value = 0;

		switch (*buffer)
		{
			case '-':
				if (--length < 1)
					return false;

				++buffer;

				multiplier = -1;

				break;

			case '+':
				if (--length < 1)
					return false;

				++buffer;

			default:
				multiplier = 1;

				break;
		}

		for (Int32u i = length; i-- > 0; ++buffer)
		{
			if (*buffer == '.')
			{
				if (decimal)
					return false;

				decimal = true;

				continue;
			}
			else if (*buffer < '0' || *buffer > '9')
				return false;

			if (decimal)
				multiplier *= 0.1;

			value = value * 10 + *buffer - '0';
		}

		*target = value * multiplier;

		return true;
	}

	template<typename T>
	static inline bool	convertStringToInteger (T* target, const char* buffer, Int32u length)
	{
		T	last;
		T	next;

		if (length < 1)
			return false;

		last = 0;
		next = 0;

		switch (*buffer)
		{
			case '-':
				if (--length < 1)
					return false;

				++buffer;

				for (Int32u i = length; i-- > 0; ++buffer)
				{
					if (*buffer < '0' || *buffer > '9')
						return false;

					next = last * 10 - *buffer + '0';

					if (last < next)
						return false;

					last = next;
				}

				break;

			case '+':
				if (--length < 1)
					return false;

				++buffer;

			default:
				for (Int32u i = length; i-- > 0; ++buffer)
				{
					if (*buffer < '0' || *buffer > '9')
						return false;

					next = last * 10 + *buffer - '0';

					if (last > next)
						return false;

					last = next;
				}

				break;
		}

		*target = last;

		return true;
	}
}

GLAY_NS_BEGIN(System)

bool	Convert::toFloat32 (Float32* target, const char* buffer, Int32u length)
{
	return convertStringToFloat<Float32> (target, buffer, length);
}

bool	Convert::toFloat64 (Float64* target, const char* buffer, Int32u length)
{
	return convertStringToFloat<Float64> (target, buffer, length);
}

bool	Convert::toInt8s (Int8s* target, const char* buffer, Int32u length)
{
	return convertStringToInteger<Int8s> (target, buffer, length);
}

bool	Convert::toInt8u (Int8u* target, const char* buffer, Int32u length)
{
	return convertStringToInteger<Int8u> (target, buffer, length);
}

bool	Convert::toInt16s (Int16s* target, const char* buffer, Int32u length)
{
	return convertStringToInteger<Int16s> (target, buffer, length);
}

bool	Convert::toInt16u (Int16u* target, const char* buffer, Int32u length)
{
	return convertStringToInteger<Int16u> (target, buffer, length);
}

bool	Convert::toInt32s (Int32s* target, const char* buffer, Int32u length)
{
	return convertStringToInteger<Int32s> (target, buffer, length);
}

bool	Convert::toInt32u (Int32u* target, const char* buffer, Int32u length)
{
	return convertStringToInteger<Int32u> (target, buffer, length);
}

bool	Convert::toInt64s (Int64s* target, const char* buffer, Int32u length)
{
	return convertStringToInteger<Int64s> (target, buffer, length);
}

bool	Convert::toInt64u (Int64u* target, const char* buffer, Int32u length)
{
	return convertStringToInteger<Int64u> (target, buffer, length);
}

Int32u	Convert::toString (char* target, Int32u length, Float32 value)
{
	return convertFloatToString<Float32> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Float64 value)
{
	return convertFloatToString<Float64> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int8s value)
{
	return convertIntegerToString<Int8s> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int8u value)
{
	return convertIntegerToString<Int8u> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int16s value)
{
	return convertIntegerToString<Int16s> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int16u value)
{
	return convertIntegerToString<Int16u> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int32s value)
{
	return convertIntegerToString<Int32s> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int32u value)
{
	return convertIntegerToString<Int32u> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int64s value)
{
	return convertIntegerToString<Int64s> (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int64u value)
{
	return convertIntegerToString<Int64u> (target, length, value);
}

GLAY_NS_END()
