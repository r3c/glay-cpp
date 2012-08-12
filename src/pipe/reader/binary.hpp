
#ifndef __GLAY_PIPE_BINARYREADER_HPP
#define __GLAY_PIPE_BINARYREADER_HPP

#include "../../config.hpp"
#include "../../system/endian.hpp"
#include "../reader.hpp"

GLAY_NS_BEGIN(Pipe)

class	BinaryReader : public Reader
{
	public:
		/**/	BinaryReader (IStream&, System::Endian::Endianness);
		/**/	BinaryReader (IStream&);

		Int8s	read8s ();
		Int8u	read8u ();
		Int16s	read16s ();
		Int16u	read16u ();
		float	read32f ();
		Int32s	read32s ();
		Int32u	read32u ();
		double	read64f ();
		Int64s	read64s ();
		Int64u	read64u ();

	private:
		System::Endian::Endianness	native;
		System::Endian				source;
};

GLAY_NS_END()

#endif
