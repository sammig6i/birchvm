flags=-O2 -Wall -std=c2x -I./include
ldflags=-lbu

.PHONY: all clean

all: clean birchvm

birchvm: birchvm.o
	cc $(flags) $^ -o $@ $(ldflags)

birchvm.o: birchvm.c birchvm.h
	cc $(flags) -c $<

clean:
	rm -f *.o birchvm