CC=gcc
CFLAGS=-g -Wall
SOURCES=brainfuck.c

all: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $(patsubst %.c, %, $^)
