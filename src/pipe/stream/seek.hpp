
#ifndef __GLAY_PIPE_SEEKSTREAM_HPP
#define __GLAY_PIPE_SEEKSTREAM_HPP

#include <vector>
#include "../stream.hpp"

GLAY_NS_BEGIN(Pipe)

class	SeekStream
{
	public:
		enum	SeekMode
		{
			SEEK_ABSOLUTE,
			SEEK_RELATIVE
		};

		/**/			SeekStream (const SeekStream&);
		/**/			SeekStream ();
		virtual			~SeekStream () {};

		SeekStream&		operator = (const SeekStream&);

		size_t			back ();
		void			mark ();
		virtual void	seek (size_t, SeekMode = SEEK_ABSOLUTE) = 0;
		virtual size_t	tell () const = 0;

	private:
		std::vector<size_t>	offsets;
};

class	SeekIStream : public virtual SeekStream, public IStream
{
	public:
		virtual	~SeekIStream () {};
};

class	SeekOStream : public virtual SeekStream, public OStream
{
	public:
		virtual	~SeekOStream () {};
};

GLAY_NS_END()

#endif
