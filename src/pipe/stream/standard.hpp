
#ifndef __GLAY_PIPE_STANDARDSTREAM_HPP
#define __GLAY_PIPE_STANDARDSTREAM_HPP

#include <istream>
#include <ostream>
#include "../stream.hpp"

GLAY_NS_BEGIN(Pipe)

class	StandardIStream : public IStream
{
	public:
				StandardIStream (const StandardIStream&);
				StandardIStream (std::istream*);
		virtual	~StandardIStream ();

		StandardIStream&	operator = (const StandardIStream&);
		virtual 			operator bool () const;

		virtual size_t	read (void*, size_t);

	private:
		std::istream*	stream;
};

class	StandardOStream : public OStream
{
	public:
				StandardOStream (const StandardOStream&);
				StandardOStream (std::ostream*);
		virtual	~StandardOStream ();

		StandardOStream&	operator = (const StandardOStream&);
		virtual				operator bool () const;

		virtual size_t	write (const void*, size_t);

	private:
		std::ostream*	stream;
};

GLAY_NS_END()

#endif
