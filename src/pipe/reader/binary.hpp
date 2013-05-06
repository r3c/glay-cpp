
#ifndef __GLAY_PIPE_READER_BINARY_HPP
#define __GLAY_PIPE_READER_BINARY_HPP

#include <string>
#include "../../config.hpp"
#include "../../system/endian.hpp"
#include "../reader.hpp"

GLAY_NS_BEGIN(Pipe)

class	BinaryReader : public Reader
{
	public:
		BinaryReader (const BinaryReader&);
		BinaryReader (IStream&, System::Endian::Endianness);
		BinaryReader (IStream&);

		BinaryReader&	operator = (const BinaryReader&);

		Float32		readFloat32 ();
		Float64		readFloat64 ();
		Int8s		readInt8s ();
		Int8u		readInt8u ();
		Int16s		readInt16s ();
		Int16u		readInt16u ();
		Int32s		readInt32s ();
		Int32u		readInt32u ();
		Int64s		readInt64s ();
		Int64u		readInt64u ();
		std::string	readString ();

		template<typename T>
		T			read ();

	private:
		System::Endian::Endianness	native;
		System::Endian				source;
};

GLAY_NS_END()

#endif
