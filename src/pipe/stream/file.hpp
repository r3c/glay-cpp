
#ifndef __GLAY_PIPE_FILESTREAM_HPP
#define __GLAY_PIPE_FILESTREAM_HPP

#include <stdio.h>
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class	FileStream : public virtual SeekStream
{
	public:
		virtual			~FileStream ();

		void			close ();
		virtual void	seek (size_t, SeekMode = SEEK_ABSOLUTE);
		virtual size_t	tell () const;

	protected:
		/**/	FileStream (FILE*);

		FILE*	file;
};

class	FileIStream : public FileStream, public SeekIStream
{
	public:
		/**/			FileIStream (const FileIStream&);
		/**/			FileIStream (const char*);

		FileIStream&	operator = (const FileIStream&);
		virtual 		operator bool () const;

		virtual size_t	read (void*, size_t);
};

class	FileOStream : public FileStream, public SeekOStream
{
	public:
		/**/			FileOStream (const FileOStream&);
		/**/			FileOStream (const char*, bool = false);

		FileOStream&	operator = (const FileOStream&);
		virtual			operator bool () const;

		virtual size_t	write (const void*, size_t);
};

GLAY_NS_END()

#endif
