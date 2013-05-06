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
	pipe/stream/file.cpp \
	pipe/stream/memory.cpp \
	pipe/stream/seek.cpp \
	pipe/writer/binary.cpp \
	pipe/writer/format.cpp \
	pipe/reader.cpp \
	pipe/stream.cpp \
	pipe/writer.cpp \
	system/convert.cpp \
	system/endian.cpp \
	system/stopwatch.cpp

TESTS	= \
	test/design_event.exe \
	test/parallel_mutex.exe \
	test/parallel_signal.exe \
	test/pipe_stream_memory.exe \
	test/system_convert.exe
