
#include "file.hpp"

GLAY_NS_BEGIN(Pipe)

/*
** Global constants.
*/
FileOStream	err (stderr);
FileIStream	in (stdin);
FileOStream	out (stdout);

/**
** FileStream
** Abstract stream on a physical file.
**/
FileStream::FileStream (const FileStream& other) :
	SeekStream (other),
	file (other.file),
	own (false)
{
}

FileStream::FileStream () :
	file (0),
	own (false)
{
}

FileStream::~FileStream ()
{
	this->close ();
}

void	FileStream::close ()
{
	if (this->file)
	{
		if (this->own)
			fclose (this->file);

		this->file = 0;
	}

	this->own = false;
}

bool	FileStream::open (FILE* file)
{
	this->close ();

	this->file = file;
	this->own = false;

	return this;
}

void	FileStream::seek (Int32u offset, SeekMode mode)
{
	if (this->file)
	{
		switch (mode)
		{
			case SEEK_ABSOLUTE:
				fseek (this->file, offset, SEEK_SET);

				break;

			case SEEK_RELATIVE:
				fseek (this->file, offset, SEEK_CUR);

				break;
		}
	}
}

Int32u	FileStream::tell () const
{
	if (this->file)
		return ftell (this->file);

	return 0;
}

/**
** FileIStream
** Input stream on a physical file.
**/
FileIStream::FileIStream (const FileIStream& other) :
	SeekStream (other),
	FileStream (other)
{
}

FileIStream::FileIStream (const char* path)
{
	this->open (path);
}

FileIStream::FileIStream (FILE* file)
{
	this->FileStream::open (file);
}

FileIStream::FileIStream ()
{
}

FileIStream::~FileIStream ()
{
}

FileIStream::operator bool () const
{
	return this->file;
}

bool	FileIStream::open (const char* path)
{
	this->close ();

	this->file = fopen (path, "rb");
	this->own = true;

	return this;
}

Int32u	FileIStream::read (void* buffer, Int32u size)
{
	if (this->file)
		return fread (buffer, 1, size, this->file);

	return 0;
}

/**
** FileOStream
** Output stream on a physical file.
**/
FileOStream::FileOStream (const FileOStream& other) :
	SeekStream (other),
	FileStream (other)
{
}

FileOStream::FileOStream (const char* path, bool append)
{
	this->open (path, append);
}

FileOStream::FileOStream (FILE* file)
{
	this->FileStream::open (file);
}

FileOStream::FileOStream ()
{
}

FileOStream::~FileOStream ()
{
}

FileOStream::operator bool () const
{
	return this->file;
}

bool	FileOStream::open (const char* path, bool append)
{
	this->close ();

	this->file = fopen (path, append ? "ab" : "wb");
	this->own = true;

	return this;
}

Int32u	FileOStream::write (const void* buffer, Int32u size)
{
	if (this->file)
		return fwrite (buffer, 1, size, this->file);

	return 0;
}

GLAY_NS_END()
