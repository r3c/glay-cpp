# Glay
# Makefile resource file

TARGET	= glay.dll
OBJ		= obj
SRC		= src
TEST	= test

SOURCE	= \
	parallel/atomic.cpp \
	parallel/lock.cpp \
	parallel/signal.cpp \
	parallel/thread.cpp \
	pipe/reader/binary.cpp \
	pipe/stream/file.cpp \
	pipe/stream/memory.cpp \
	pipe/writer/binary.cpp \
	pipe/reader.cpp \
	pipe/writer.cpp \
	runtime/endian.cpp

UNITS	= \
	test/parallel/synchronize_with_locks.exe \
	test/parallel/synchronize_with_signals.exe
