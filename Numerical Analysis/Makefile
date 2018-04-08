CC=gcc
STRIP=/usr/bin/strip
CFLAGS=-Wall
LDFLAGS=

all: HexDump03

HexDump03.o: HexDump03.c HexDump02.h
	     $(CC) -c $(CFLAGS) HexDump03.c

Hex02-fnc.o: Hex02-fnc.c HexDump02.h
	     $(CC) -c $(CFLAGS) Hex02-fnc.c

HexDump03: HexDump03.o Hex02-fnc.o
	   $(CC) -o HexDump03 HexDump03.o Hex02-fnc.o $(LDFLAGS)
	   $(STRIP) HexDump03

.PHONY: clean

clean:
	rm -rf HexDump03 HexDump03.o Hex02-fnc.o

