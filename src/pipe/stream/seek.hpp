
#ifndef __GLAY_PIPE_STREAM_SEEK_HPP
#define __GLAY_PIPE_STREAM_SEEK_HPP

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

		SeekStream (const SeekStream&);
		SeekStream ();
		virtual	~SeekStream ();

		SeekStream&		operator = (const SeekStream&);

		Int32u			back ();
		void			mark ();
		virtual void	seek (Int32u, SeekMode = SEEK_ABSOLUTE) = 0;
		virtual size_t	tell () const = 0;

	private:
		std::vector<Int32u>	offsets;
};

class	SeekIStream : public virtual SeekStream, public IStream
{
	public:
		virtual	~SeekIStream ();
};

class	SeekOStream : public virtual SeekStream, public OStream
{
	public:
		virtual	~SeekOStream ();
};

GLAY_NS_END()

#endif
