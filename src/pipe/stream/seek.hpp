
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

		SeekStream (const SeekStream&);
		SeekStream ();
		virtual ~SeekStream ();

		SeekStream& operator = (const SeekStream&);

		virtual size_t getPosition () const = 0;
		virtual size_t getSize () const = 0;

		size_t back ();
		void mark ();
		virtual bool seek (size_t, SeekMode = SEEK_ABSOLUTE) = 0;

	private:
		std::vector<size_t> offsets;
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
