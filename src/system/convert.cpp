
#include "convert.hpp"

using namespace Glay;

namespace
{
	template<typename T>
	static inline bool	convertToFloat (T* target, const char* buffer, Int32u length)
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
	static inline bool	convertToInt (T* target, const char* buffer, Int32u length)
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
	return convertToFloat<Float32> (target, buffer, length);
}

bool	Convert::toFloat64 (Float64* target, const char* buffer, Int32u length)
{
	return convertToFloat<Float64> (target, buffer, length);
}

bool	Convert::toInt8s (Int8s* target, const char* buffer, Int32u length)
{
	return convertToInt<Int8s> (target, buffer, length);
}

bool	Convert::toInt8u (Int8u* target, const char* buffer, Int32u length)
{
	return convertToInt<Int8u> (target, buffer, length);
}

bool	Convert::toInt16s (Int16s* target, const char* buffer, Int32u length)
{
	return convertToInt<Int16s> (target, buffer, length);
}

bool	Convert::toInt16u (Int16u* target, const char* buffer, Int32u length)
{
	return convertToInt<Int16u> (target, buffer, length);
}

bool	Convert::toInt32s (Int32s* target, const char* buffer, Int32u length)
{
	return convertToInt<Int32s> (target, buffer, length);
}

bool	Convert::toInt32u (Int32u* target, const char* buffer, Int32u length)
{
	return convertToInt<Int32u> (target, buffer, length);
}

bool	Convert::toInt64s (Int64s* target, const char* buffer, Int32u length)
{
	return convertToInt<Int64s> (target, buffer, length);
}

bool	Convert::toInt64u (Int64u* target, const char* buffer, Int32u length)
{
	return convertToInt<Int64u> (target, buffer, length);
}

GLAY_NS_END()
