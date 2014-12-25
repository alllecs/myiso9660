CC=gcc

CFLAGS=-W -Wall
LDFLAGS=-liso9660 -lcdio

all: isoread

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	$(RM) isoread
