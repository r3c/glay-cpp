
#include "file.hpp"

GLAY_NS_BEGIN(Pipe)

/*
** Global constants.
*/
FileOStream err (stderr);
FileIStream in (stdin);
FileOStream out (stdout);

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

size_t FileStream::getPosition () const
{
	if (this->file)
		return ftell (this->file);

	return 0;
}

size_t FileStream::getSize () const
{
	size_t position;
	size_t size;

	if (this->file)
	{
		position = ftell (this->file);

		if (fseek (this->file, 0, SEEK_END) == 0)
			size = ftell (this->file);
		else
			size = 0;

		fseek (this->file, position, SEEK_SET);

		return size;
	}

	return 0;
}

void FileStream::close ()
{
	if (this->file)
	{
		if (this->own)
			fclose (this->file);

		this->file = 0;
	}

	this->own = false;
}

bool FileStream::open (FILE* file)
{
	this->close ();

	this->file = file;
	this->own = false;

	return true;
}

bool FileStream::seek (size_t offset, SeekMode mode)
{
	if (this->file)
	{
		switch (mode)
		{
			case SEEK_ABSOLUTE:
				return fseek (this->file, offset, SEEK_SET) == 0;

			case SEEK_RELATIVE:
				return fseek (this->file, offset, SEEK_CUR) == 0;

			case SEEK_REVERSE:
				return fseek (this->file, offset, SEEK_END) == 0;
		}
	}

	return false;
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

bool FileIStream::open (const char* path)
{
	this->close ();

	this->file = fopen (path, "rb");
	this->own = true;

	return true;
}

size_t FileIStream::read (void* buffer, size_t size)
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

void FileOStream::flush ()
{
	if (this->file)
		fflush (this->file);
}

bool FileOStream::open (const char* path, bool append)
{
	this->close ();

	this->file = fopen (path, append ? "ab" : "wb");
	this->own = true;

	return true;
}

size_t FileOStream::write (const void* buffer, size_t size)
{
	if (this->file)
		return fwrite (buffer, 1, size, this->file);

	return 0;
}

GLAY_NS_END()
