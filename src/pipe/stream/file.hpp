
#ifndef __GLAY_PIPE_FILESTREAM_HPP
#define __GLAY_PIPE_FILESTREAM_HPP

#include <stdio.h>
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class	FileStream : public SeekStream
{
	public:
		virtual				~FileStream ();

		virtual size_t		getOffset () const;

		virtual void		setOffset (size_t, SeekMode = SEEK_ABSOLUTE);

		void				close ();

	protected:
		/**/				FileStream (FILE*);

		FILE*				file;
};

class	FileIStream : public FileStream, public IStream
{
	public:
		/**/			FileIStream (const char*);

		virtual 		operator bool () const;

		virtual size_t	read (void*, size_t);
};

class	FileOStream : public FileStream, public OStream
{
	public:
		/**/			FileOStream (const char*, bool = false);

		virtual			operator bool () const;

		virtual size_t	write (const void*, size_t);
};

GLAY_NS_END()

#endif
