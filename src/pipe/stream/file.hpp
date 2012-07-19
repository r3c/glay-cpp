
#ifndef __GLAY_PIPE_FILESTREAM_HPP
#define __GLAY_PIPE_FILESTREAM_HPP

#include <stdio.h>
#include "../stream.hpp"

GLAY_NS_BEGIN(Pipe)

class	FileStream : virtual public Stream
{
	public:
		virtual				~FileStream ();

		virtual operator	bool () const;

		void				close ();
//		void				seek (int, SeekMode);

	protected:
		/**/				FileStream (FILE*);

		FILE*				file;
};

class	FileIStream : public FileStream, public IStream
{
	public:
		/**/			FileIStream (const char*);

		virtual size_t	read (void*, size_t);
};

class	FileOStream : public FileStream, public OStream
{
	public:
		/**/			FileOStream (const char*, bool = false);

		virtual size_t	write (const void*, size_t);
};

GLAY_NS_END()

#endif
