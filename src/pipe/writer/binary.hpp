
#ifndef __GLAY_PIPE_BINARYWRITER_HPP
#define __GLAY_PIPE_BINARYWRITER_HPP

#include "../../config.hpp"
#include "../../system/endian.hpp"
#include "../writer.hpp"

GLAY_NS_BEGIN(Pipe)

class	BinaryWriter : public Writer
{
	public:
		/**/	BinaryWriter (OStream&, System::Endian::Endianness);
		/**/	BinaryWriter (OStream&);

		void	writeFloat32 (Float32);
		void	writeFloat64 (Float64);
		void	writeInt8s (Int8s);
		void	writeInt8u (Int8u);
		void	writeInt16s (Int16s);
		void	writeInt16u (Int16u);
		void	writeInt32s (Int32s);
		void	writeInt32u (Int32u);
		void	writeInt64s (Int64s);
		void	writeInt64u (Int64u);

	private:
		System::Endian				native;
		System::Endian::Endianness	target;
};

GLAY_NS_END()

#endif
