# Glay
# Makefile resource file

TARGET	= glay.dll
OBJ		= obj
SRC		= src
TEST	= test

SOURCE	= \
	parallel/atomic.cpp \
	parallel/mutex.cpp \
	parallel/signal.cpp \
	parallel/thread.cpp \
	parallel/timer.cpp \
	pipe/reader/binary.cpp \
	pipe/reader/type.cpp \
	pipe/stream/file.cpp \
	pipe/stream/memory.cpp \
	pipe/stream/seek.cpp \
	pipe/stream/standard.cpp \
	pipe/writer/binary.cpp \
	pipe/writer/type.cpp \
	pipe/reader.cpp \
	pipe/writer.cpp \
	system/endian.cpp \
	system/stopwatch.cpp

UNITS	= \
	test/parallel/synchronize_with_mutex.exe \
	test/parallel/synchronize_with_signal.exe
