CC=GCC
CFLAGS=-g -Wall
SOURCES=brainfuck.c

all: $(patsubst, %.c, %, $(SOURCES))

$(
