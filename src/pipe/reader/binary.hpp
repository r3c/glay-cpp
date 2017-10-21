
#ifndef __GLAY_PIPE_READER_BINARY_HPP
#define __GLAY_PIPE_READER_BINARY_HPP

#include <string>
#include "../../config.hpp"
#include "../../system/endian.hpp"
#include "../reader.hpp"

GLAY_NS_BEGIN(Pipe)

class BinaryReader : public Reader
{
	public:
		BinaryReader (const BinaryReader&);
		BinaryReader (IStream&, System::Endian::Endianness);
		BinaryReader (IStream&);

		BinaryReader& operator = (const BinaryReader&);

		bool readFloat32 (Float32*);
		Float32 readFloat32 ();
		bool readFloat64 (Float64*);
		Float64 readFloat64 ();
		bool readInt8s (Int8s*);
		Int8s readInt8s ();
		bool readInt8u (Int8u*);
		Int8u readInt8u ();
		bool readInt16s (Int16s*);
		Int16s readInt16s ();
		bool readInt16u (Int16u*);
		Int16u readInt16u ();
		bool readInt32s (Int32s*);
		Int32s readInt32s ();
		bool readInt32u (Int32u*);
		Int32u readInt32u ();
		bool readInt64s (Int64s*);
		Int64s readInt64s ();
		bool readInt64u (Int64u*);
		Int64u readInt64u ();
		bool readString (std::string*);
		std::string readString ();

		template<typename T>
		bool readType (T*);

		template<typename T>
		T readType ();

	private:
		System::Endian::Endianness native;
		System::Endian source;
};

GLAY_NS_END()

#include "binary.hxx"

#endif
