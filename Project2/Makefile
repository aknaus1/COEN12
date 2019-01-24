CC	= gcc
CFLAGS	= -g -Wall
LDFLAGS	=
PROGS	= unique-unsorted unique-sorted parity-unsorted parity-sorted

all:			$(PROGS)

clean:;			$(RM) $(PROGS) *.c core

unique-unsorted:	unique.c unsorted.c
			$(CC) -o $@ $(LDFLAGS) unique.c unsorted.c

unique-sorted:		unique.c sorted.c
			$(CC) -o $@ $(LDFLAGS) unique.c sorted.c

parity-unsorted:	parity.c unsorted.c
			$(CC) -o $@ $(LDFLAGS) parity.c unsorted.c

parity-sorted:		parity.c sorted.c
			$(CC) -o $@ $(LDFLAGS) parity.c sorted.c
