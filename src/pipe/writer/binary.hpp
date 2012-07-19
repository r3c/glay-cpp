
#ifndef __GLAY_PIPE_BINARYWRITER_HPP
#define __GLAY_PIPE_BINARYWRITER_HPP

#include "../../config.hpp"
#include "../../runtime/endian.hpp"
#include "../writer.hpp"

GLAY_NS_BEGIN(Pipe)

class	BinaryWriter : public Writer
{
	public:
		/**/	BinaryWriter (OStream&, Runtime::Endian::Endianness);
		/**/	BinaryWriter (OStream&);

		void	write8s (int8_t);
		void	write8u (uint8_t);
		void	write16s (int16_t);
		void	write16u (uint16_t);
		void	write32f (float);
		void	write32s (int32_t);
		void	write32u (uint32_t);
		void	write64f (double);
		void	write64s (int64_t);
		void	write64u (uint64_t);

	private:
		Runtime::Endian				native;
		Runtime::Endian::Endianness	target;
};

GLAY_NS_END()

#endif
