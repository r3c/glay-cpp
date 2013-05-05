
#ifndef __GLAY_PIPE_STREAM_FILE_HPP
#define __GLAY_PIPE_STREAM_FILE_HPP

#include <cstdio>
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class	FileStream : public virtual SeekStream
{
	public:
		virtual	~FileStream ();

		void			close ();
		bool			open (FILE*);
		virtual void	seek (size_t, SeekMode = SEEK_ABSOLUTE);
		virtual size_t	tell () const;

	protected:
		FileStream ();

		FILE*	file;
		bool	own;
};

class	FileIStream : public FileStream, public SeekIStream
{
	public:
		FileIStream (const FileIStream&);
		FileIStream (const char*);
		FileIStream (FILE*);
		FileIStream ();
		virtual	~FileIStream ();

		FileIStream&	operator = (const FileIStream&);
		virtual 		operator bool () const;

		bool			open (const char*);
		virtual size_t	read (void*, size_t);
};

class	FileOStream : public FileStream, public SeekOStream
{
	public:
		FileOStream (const FileOStream&);
		FileOStream (const char*, bool = false);
		FileOStream (FILE*);
		FileOStream ();
		virtual	~FileOStream ();

		FileOStream&	operator = (const FileOStream&);
		virtual			operator bool () const;

		bool			open (const char*, bool = false);
		virtual size_t	write (const void*, size_t);
};

extern FileOStream	err;
extern FileIStream	in;
extern FileOStream	out;

GLAY_NS_END()

#endif
