# Glay
# Makefile resource file

TARGET	= glay.dll
OBJ		= obj
SRC		= src
TEST	= test

SOURCE	= \
	parallel/lock.cpp \
	parallel/signal.cpp \
	pipe/reader/binary.cpp \
	pipe/stream/file.cpp \
	pipe/stream/memory.cpp \
	pipe/writer/binary.cpp \
	pipe/reader.cpp \
	pipe/writer.cpp \
	runtime/endian.cpp

UNITS	= \
	test/parallel/thread/concurrent.exe
