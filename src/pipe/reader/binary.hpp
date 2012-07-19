
#ifndef __GLAY_PIPE_BINARYREADER_HPP
#define __GLAY_PIPE_BINARYREADER_HPP

#include "../../config.hpp"
#include "../../runtime/endian.hpp"
#include "../reader.hpp"

GLAY_NS_BEGIN(Pipe)

class	BinaryReader : public Reader
{
	public:
		/**/		BinaryReader (IStream&, Runtime::Endian::Endianness);
		/**/		BinaryReader (IStream&);

		int8_t		read8s ();
		uint8_t		read8u ();
		int16_t		read16s ();
		uint16_t	read16u ();
		float		read32f ();
		int32_t		read32s ();
		uint32_t	read32u ();
		double		read64f ();
		int64_t		read64s ();
		uint64_t	read64u ();

	private:
		Runtime::Endian::Endianness	native;
		Runtime::Endian				source;
};

GLAY_NS_END()

#endif
