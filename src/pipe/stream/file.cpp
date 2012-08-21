
#include "file.hpp"

GLAY_NS_BEGIN(Pipe)

/**
** FileStream
** Abstract stream on a physical file.
**/
/**/	FileStream::FileStream (FILE* file) :
	file (file)
{
}

/**/	FileStream::~FileStream ()
{
	this->close ();
}

size_t	FileStream::getOffset () const
{
	if (this->file)
		return ftell (this->file);

	return 0;
}

void	FileStream::setOffset (size_t offset, SeekMode mode)
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

void	FileStream::close ()
{
	if (this->file)
	{
		fclose (this->file);

		this->file = 0;
	}
}

/**
** FileIStream
** Input stream on a physical file.
**/
/**/	FileIStream::FileIStream (const char* path) :
	FileStream (fopen (path, "rb"))
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
/**/	FileOStream::FileOStream (const char* path, bool append) :
	FileStream (fopen (path, append ? "ab" : "wb"))
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
