
#ifndef __GLAY_PIPE_STREAM_SEEK_HPP
#define __GLAY_PIPE_STREAM_SEEK_HPP

#include <vector>
#include "../stream.hpp"

GLAY_NS_BEGIN(Pipe)

class SeekStream
{
	public:
		enum SeekMode
		{
			SEEK_ABSOLUTE,
			SEEK_RELATIVE,
			SEEK_REVERSE
		};

		SeekStream (SeekStream const&);
		SeekStream ();
		virtual ~SeekStream ();

		SeekStream& operator = (SeekStream const&);

		virtual Size getPosition () const = 0;
		virtual Size getSize () const = 0;

		Size back ();
		void mark ();
		virtual bool seek (Size, SeekMode = SEEK_ABSOLUTE) = 0;

	private:
		std::vector<Size> offsets;
};

class SeekIStream : public virtual SeekStream, public IStream
{
	public:
		virtual ~SeekIStream ();
};

class SeekOStream : public virtual SeekStream, public OStream
{
	public:
		virtual ~SeekOStream ();
};

GLAY_NS_END()

#endif
