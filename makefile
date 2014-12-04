CC=gcc

CFLAGS=-W -Wall
LDFLAGS=-liso9660 -lcdio

all: isolist

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	$(RM) isolist
