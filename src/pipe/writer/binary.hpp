
#ifndef __GLAY_PIPE_WRITER_BINARY_HPP
#define __GLAY_PIPE_WRITER_BINARY_HPP

#include <string>
#include "../../config.hpp"
#include "../../system/endian.hpp"
#include "../writer.hpp"

GLAY_NS_BEGIN(Pipe)

class BinaryWriter : public Writer
{
	public:
		BinaryWriter (BinaryWriter const&);
		BinaryWriter (OStream&, System::Endian::Endianness);
		BinaryWriter (OStream&);

		BinaryWriter& operator = (BinaryWriter const&);

		bool writeFloat32 (Float32);
		bool writeFloat64 (Float64);
		bool writeInt8s (Int8s);
		bool writeInt8u (Int8u);
		bool writeInt16s (Int16s);
		bool writeInt16u (Int16u);
		bool writeInt32s (Int32s);
		bool writeInt32u (Int32u);
		bool writeInt64s (Int64s);
		bool writeInt64u (Int64u);
		bool writeString (std::string const&);

		template<typename T>
		bool writeType (T const&);

	private:
		System::Endian native;
		System::Endian::Endianness target;
};

GLAY_NS_END()

#include "binary.hxx"

#endif
