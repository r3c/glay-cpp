
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

		void	write8s (Int8s);
		void	write8u (Int8u);
		void	write16s (Int16s);
		void	write16u (Int16u);
		void	write32f (float);
		void	write32s (Int32s);
		void	write32u (Int32u);
		void	write64f (double);
		void	write64s (Int64s);
		void	write64u (Int64u);

	private:
		Runtime::Endian				native;
		Runtime::Endian::Endianness	target;
};

GLAY_NS_END()

#endif
