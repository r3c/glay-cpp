
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
FileStream::FileStream (FileStream const& other) :
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

Size FileStream::getPosition () const
{
	if (this->file)
		return ftello64 (this->file);

	return 0;
}

Size FileStream::getSize () const
{
	if (this->file)
	{
		Size position = ftello64 (this->file);
		Size size;

		if (fseeko64 (this->file, 0, SEEK_END) == 0)
			size = ftello64 (this->file);
		else
			size = 0;

		fseeko64 (this->file, position, SEEK_SET);

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

bool FileStream::seek (Size offset, SeekMode mode)
{
	if (this->file)
	{
		switch (mode)
		{
			case SEEK_ABSOLUTE:
				return fseeko64 (this->file, offset, SEEK_SET) == 0;

			case SEEK_RELATIVE:
				return fseeko64 (this->file, offset, SEEK_CUR) == 0;

			case SEEK_REVERSE:
				return fseeko64 (this->file, offset, SEEK_END) == 0;
		}
	}

	return false;
}

/**
** FileIStream
** Input stream on a physical file.
**/
FileIStream::FileIStream (FileIStream const& other) :
	SeekStream (other),
	FileStream (other)
{
}

FileIStream::FileIStream (char const* path)
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

bool FileIStream::open (char const* path)
{
	this->close ();

	this->file = fopen (path, "rb");
	this->own = true;

	return true;
}

Size FileIStream::read (void* buffer, Size size)
{
	if (this->file)
		return fread (buffer, 1, size, this->file);

	return 0;
}

/**
** FileOStream
** Output stream on a physical file.
**/
FileOStream::FileOStream (FileOStream const& other) :
	SeekStream (other),
	FileStream (other)
{
}

FileOStream::FileOStream (char const* path, bool append)
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

bool FileOStream::open (char const* path, bool append)
{
	this->close ();

	this->file = fopen (path, append ? "ab" : "wb");
	this->own = true;

	return true;
}

Size FileOStream::write (void const* buffer, Size size)
{
	if (this->file)
		return fwrite (buffer, 1, size, this->file);

	return 0;
}

GLAY_NS_END()
