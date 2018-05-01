
#ifndef __GLAY_PIPE_STREAM_FILE_HPP
#define __GLAY_PIPE_STREAM_FILE_HPP

#include <cstdio>
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class FileStream : public virtual SeekStream
{
	public:
		virtual ~FileStream ();

		virtual Size getPosition () const;
		virtual Size getSize () const;

		void close ();
		bool open (FILE*);
		virtual bool seek (Size, SeekMode = SEEK_ABSOLUTE);

	protected:
		FileStream (FileStream const&);
		FileStream ();

		FILE* file;
		bool own;
};

class FileIStream : public FileStream, public SeekIStream
{
	public:
		using FileStream::open;

		FileIStream (FileIStream const&);
		FileIStream (char const*);
		FileIStream (FILE*);
		FileIStream ();
		virtual ~FileIStream ();

		FileIStream& operator = (FileIStream const&);
		virtual operator bool () const;

		bool open (char const*);
		virtual Size read (void*, Size);
};

class FileOStream : public FileStream, public SeekOStream
{
	public:
		using FileStream::open;

		FileOStream (FileOStream const&);
		FileOStream (char const*, bool = false);
		FileOStream (FILE*);
		FileOStream ();
		virtual ~FileOStream ();

		FileOStream& operator = (FileOStream const&);
		virtual operator bool () const;

		virtual void flush ();
		bool open (char const*, bool = false);
		virtual Size write (void const*, Size);
};

extern FileOStream err;
extern FileIStream in;
extern FileOStream out;

GLAY_NS_END()

#endif
