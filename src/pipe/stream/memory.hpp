
#ifndef __GLAY_PIPE_STREAM_MEMORY_HPP
#define __GLAY_PIPE_STREAM_MEMORY_HPP

#include "seek.hpp"

GLAY_NS_BEGIN(Pipe)

class	MemoryStream : public virtual SeekStream
{
	public:
		virtual void	seek (Int32u, SeekMode = SEEK_ABSOLUTE);
		virtual Int32u	tell () const;

	protected:
		MemoryStream (const MemoryStream&);
		MemoryStream (Int32u, Int32u);

		Int32u	capacity;
		Int32u	cursor;
};

class	MemoryIStream : public MemoryStream, public SeekIStream
{
	public:
		MemoryIStream (const MemoryIStream&);
		MemoryIStream (const void*, Int32u = INT32U_MAX);

		MemoryIStream&	operator = (const MemoryIStream&);
		virtual 		operator bool () const;

		const Int8s*	getBuffer () const;
		Int32u			getSize () const;

		virtual Int32u	read (void*, Int32u);

	protected:
		const Int8s*	source;
};

class	MemoryOStream : public MemoryStream, public SeekOStream
{
	public:
		MemoryOStream (const MemoryOStream&);
		MemoryOStream (void*, Int32u = INT32U_MAX);
		MemoryOStream ();
		virtual ~MemoryOStream ();

		MemoryOStream&	operator = (const MemoryOStream&);
		virtual 		operator bool () const;

		const Int8s*	getBuffer () const;
		Int8s*			getBuffer ();
		Int32u			getSize () const;

		virtual Int32u	write (const void*, Int32u);

	private:
		bool	allocate;
		Int8s*	target;
};

GLAY_NS_END()

#endif
