
#ifndef __GLAY_PIPE_STREAM_FILE_HPP
#define __GLAY_PIPE_STREAM_FILE_HPP

#include <cstdio>
#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class FileStream : public virtual SeekStream
{
	public:
		virtual ~FileStream ();

		virtual size_t getPosition () const;
		virtual size_t getSize () const;

		void close ();
		bool open (FILE*);
		virtual bool seek (size_t, SeekMode = SEEK_ABSOLUTE);

	protected:
		FileStream (const FileStream&);
		FileStream ();

		FILE* file;
		bool own;
};

class FileIStream : public FileStream, public SeekIStream
{
	public:
		using FileStream::open;

		FileIStream (const FileIStream&);
		FileIStream (const char*);
		FileIStream (FILE*);
		FileIStream ();
		virtual ~FileIStream ();

		FileIStream& operator = (const FileIStream&);
		virtual 		operator bool () const;

		bool open (const char*);
		virtual size_t read (void*, size_t);
};

class FileOStream : public FileStream, public SeekOStream
{
	public:
		using FileStream::open;

		FileOStream (const FileOStream&);
		FileOStream (const char*, bool = false);
		FileOStream (FILE*);
		FileOStream ();
		virtual ~FileOStream ();

		FileOStream& operator = (const FileOStream&);
		virtual operator bool () const;

		virtual void flush ();
		bool open (const char*, bool = false);
		virtual size_t write (const void*, size_t);
};

extern FileOStream err;
extern FileIStream in;
extern FileOStream out;

GLAY_NS_END()

#endif
