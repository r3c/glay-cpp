
#include "convert.hpp"

#include <cstdio>
#include <cstring>
#include <limits>

using namespace Glay;

namespace
{
	template<typename T>
	struct	Float
	{
		static inline bool		fromString (T* target, const char* buffer, Int32u length)
		{
			Int32u	exponent;
			T		mantissa;
			T		multiplier;
			T		value;

			if (length < 1)
				return false;

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

			value = 0;

			// Parse integral part
			while (length > 0 && *buffer >= '0' && *buffer <= '9')
			{
				value = value * 10 + *buffer - '0';

				++buffer;
				--length;
			}

			// Parse decimal separator
			if (length > 0 && *buffer == '.')
			{
				++buffer;
				--length;
			}

			// Parse decimal part
			while (length > 0 && *buffer >= '0' && *buffer <= '9')
			{
				multiplier *= 0.1;
				value = value * 10 + *buffer - '0';

				++buffer;
				--length;
			}

			// Parse exponent part
			if (length > 1 && (*buffer == 'E' || *buffer == 'e'))
			{
				++buffer;
				--length;

				switch (*buffer)
				{
					case '-':
						if (--length < 1)
							return false;

						++buffer;

						mantissa = 0.1;

						break;

					case '+':
						if (--length < 1)
							return false;

						++buffer;

					default:
						mantissa = 10;

						break;
				}

				exponent = 0;

				while (length > 0 && *buffer >= '0' && *buffer <= '9')
				{
					exponent = exponent * 10 + *buffer - '0';

					++buffer;
					--length;
				}

				while (exponent > 0)
				{
					if ((exponent & 1) != 0)
						multiplier *= mantissa;

					exponent >>= 1;
					mantissa *= mantissa;
				}
			}

			if (length > 0)
				return false;

			*target = value * multiplier;

			return true;
		}

		static inline Int32u	toString (char* target, Int32u length, T value)
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
	};

	template<typename T, bool is_signed>
	struct	IntegerSign
	{
		static inline bool	fromString (T* target, const char* buffer, Int32u length)
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

		static inline Int32u	toString (char* target, Int32u length, T value)
		{
			char	buffer[32];
			Int32u	index;
			T		next;
			Int32u	use;

			index = sizeof (buffer) / sizeof (*buffer);

			if (value < 0)
			{
				do
				{
					next = value / 10;

					buffer[--index] = '0' + next * 10 - value;

					value = next;
				}
				while (value < 0);

				buffer[--index] = '-';
			}
			else
			{
				do
				{
					next = value / 10;

					buffer[--index] = '0' + value - next * 10;

					value = next;
				}
				while (value > 0);
			}

			use = sizeof (buffer) / sizeof (*buffer) - index;

			if (use > length)
				return 0;

			memcpy (target, buffer + index, use * sizeof (*target));

			return use;
		}
	};

	template<typename T>
	struct	IntegerSign<T, false>
	{
		static inline bool	fromString (T* target, const char* buffer, Int32u length)
		{
			T	last;
			T	next;

			if (length < 1)
				return false;

			last = 0;
			next = 0;

			switch (*buffer)
			{
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

		static inline Int32u	toString (char* target, Int32u length, T value)
		{
			char	buffer[32];
			Int32u	index;
			T		next;
			Int32u	use;

			index = sizeof (buffer) / sizeof (*buffer);

			do
			{
				next = value / 10;

				buffer[--index] = '0' + value - next * 10;

				value = next;
			}
			while (value > 0);

			use = sizeof (buffer) / sizeof (*buffer) - index;

			if (use > length)
				return 0;

			memcpy (target, buffer + index, use * sizeof (*target));

			return use;
		}
	};

	template<typename T>
	struct	Integer
	{
		static inline bool	fromString (T* target, const char* buffer, Int32u length)
		{
			return IntegerSign<T, std::numeric_limits<T>::is_signed>::fromString (target, buffer, length);
		}

		static inline Int32u	toString (char* target, Int32u length, T value)
		{
			return IntegerSign<T, std::numeric_limits<T>::is_signed>::toString (target, length, value);
		}
	};
}

GLAY_NS_BEGIN(System)

bool	Convert::toFloat (Float32* target, const char* buffer, Int32u length)
{
	return Float<Float32>::fromString (target, buffer, length);
}

bool	Convert::toFloat (Float64* target, const char* buffer, Int32u length)
{
	return Float<Float64>::fromString (target, buffer, length);
}

bool	Convert::toInteger (Int8s* target, const char* buffer, Int32u length)
{
	return Integer<Int8s>::fromString (target, buffer, length);
}

bool	Convert::toInteger (Int8u* target, const char* buffer, Int32u length)
{
	return Integer<Int8u>::fromString (target, buffer, length);
}

bool	Convert::toInteger (Int16s* target, const char* buffer, Int32u length)
{
	return Integer<Int16s>::fromString (target, buffer, length);
}

bool	Convert::toInteger (Int16u* target, const char* buffer, Int32u length)
{
	return Integer<Int16u>::fromString (target, buffer, length);
}

bool	Convert::toInteger (Int32s* target, const char* buffer, Int32u length)
{
	return Integer<Int32s>::fromString (target, buffer, length);
}

bool	Convert::toInteger (Int32u* target, const char* buffer, Int32u length)
{
	return Integer<Int32u>::fromString (target, buffer, length);
}

bool	Convert::toInteger (Int64s* target, const char* buffer, Int32u length)
{
	return Integer<Int64s>::fromString (target, buffer, length);
}

bool	Convert::toInteger (Int64u* target, const char* buffer, Int32u length)
{
	return Integer<Int64u>::fromString (target, buffer, length);
}

Int32u	Convert::toString (char* target, Int32u length, Float32 value)
{
	return Float<Float32>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Float64 value)
{
	return Float<Float64>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int8s value)
{
	return Integer<Int8s>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int8u value)
{
	return Integer<Int8u>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int16s value)
{
	return Integer<Int16s>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int16u value)
{
	return Integer<Int16u>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int32s value)
{
	return Integer<Int32s>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int32u value)
{
	return Integer<Int32u>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int64s value)
{
	return Integer<Int64s>::toString (target, length, value);
}

Int32u	Convert::toString (char* target, Int32u length, Int64u value)
{
	return Integer<Int64u>::toString (target, length, value);
}

GLAY_NS_END()
