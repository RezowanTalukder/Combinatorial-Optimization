CC=gcc
STRIP=/usr/bin/strip
CFLAGS=-Wall
LDFLAGS=

all: CLarg1 CLarg2 CLarg3

CLarg1.o: CLarg1.c
	   $(CC) -c $(CFLAGS) CLarg1.c

CLarg2.o: CLarg2.c
	   $(CC) -c $(CFLAGS) CLarg2.c

CLarg3.o: CLarg3.c
	   $(CC) -c $(CFLAGS) CLarg3.c

CLarg1: CLarg1.o
	$(CC) -o CLarg1 CLarg1.o $(LDFLAGS)
	$(STRIP) CLarg1

CLarg2: CLarg2.o
	$(CC) -o CLarg2 CLarg2.o $(LDFLAGS)
	$(STRIP) CLarg2

CLarg3: CLarg3.o
	$(CC) -o CLarg3 CLarg3.o $(LDFLAGS)
	$(STRIP) CLarg3

.PHONY: clean

clean:
	rm -rf CLarg1 CLarg2 CLarg3 *.o

