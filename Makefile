flags = -O2 -Wall -std=c2x
ldflags =

.PHONY: all clean

all: clean webdev

webdev: webdev.o
	cc $(flags) $< -o $@ $(ldflags)

webdev.o: webdev.c webdev.h
	cc $(flags) -c $<

clean:
	rm -f webdev webdev.o
