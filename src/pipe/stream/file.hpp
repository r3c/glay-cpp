
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
		virtual void	seek (Int32u, SeekMode = SEEK_ABSOLUTE);
		virtual Int32u	tell () const;

	protected:
		FileStream (const FileStream&);
		FileStream ();

		FILE*	file;
		bool	own;
};

class	FileIStream : public FileStream, public SeekIStream
{
	public:
		using FileStream::open;

		FileIStream (const FileIStream&);
		FileIStream (const char*);
		FileIStream (FILE*);
		FileIStream ();
		virtual	~FileIStream ();

		FileIStream&	operator = (const FileIStream&);
		virtual 		operator bool () const;

		bool			open (const char*);
		virtual Int32u	read (void*, Int32u);
};

class	FileOStream : public FileStream, public SeekOStream
{
	public:
		using FileStream::open;

		FileOStream (const FileOStream&);
		FileOStream (const char*, bool = false);
		FileOStream (FILE*);
		FileOStream ();
		virtual	~FileOStream ();

		FileOStream&	operator = (const FileOStream&);
		virtual			operator bool () const;

		bool			open (const char*, bool = false);
		virtual Int32u	write (const void*, Int32u);
};

extern FileOStream	err;
extern FileIStream	in;
extern FileOStream	out;

GLAY_NS_END()

#endif
