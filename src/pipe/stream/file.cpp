
#include "file.hpp"

GLAY_NS_BEGIN(Pipe)

/**
** FileStream
** Abstract stream on a physical file.
**/
FileStream::FileStream (FILE* file, bool own) :
	file (file),
	own (own)
{
}

FileStream::~FileStream ()
{
	if (this->own)
		this->close ();
}

void	FileStream::close ()
{
	if (this->file)
	{
		fclose (this->file);

		this->file = 0;
	}
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
FileIStream::FileIStream (const char* path) :
	FileStream (fopen (path, "rb"), true)
{
}

FileIStream::FileIStream (FILE* file) :
	FileStream (file, false)
{
}

FileIStream::~FileIStream ()
{
}

FileIStream::operator bool () const
{
	return this->file;
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
FileOStream::FileOStream (const char* path, bool append) :
	FileStream (fopen (path, append ? "ab" : "wb"), true)
{
}

FileOStream::FileOStream (FILE* file) :
	FileStream (file, false)
{
}

FileOStream::~FileOStream ()
{
}

FileOStream::operator bool () const
{
	return this->file;
}

size_t	FileOStream::write (const void* buffer, size_t size)
{
	if (this->file)
		return fwrite (buffer, 1, size, this->file);

	return 0;
}

GLAY_NS_END()
