
#include "file.hpp"

GLAY_NS_BEGIN(Pipe)

/*
** Global constants.
*/
const FileOStream	err (stderr);
const FileIStream	in (stdin);
const FileOStream	out (stdout);

/**
** FileStream
** Abstract stream on a physical file.
**/
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

void	FileStream::seek (size_t offset, SeekMode mode)
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

size_t	FileStream::tell () const
{
	if (this->file)
		return ftell (this->file);

	return 0;
}

/**
** FileIStream
** Input stream on a physical file.
**/
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

size_t	FileIStream::read (void* buffer, size_t size)
{
	if (this->file)
		return fread (buffer, 1, size, this->file);

	return 0;
}

/**
** FileOStream
** Output stream on a physical file.
**/
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

size_t	FileOStream::write (const void* buffer, size_t size)
{
	if (this->file)
		return fwrite (buffer, 1, size, this->file);

	return 0;
}

GLAY_NS_END()
