CC=gcc

CFLAGS=-W -Wall

all: isofile2.c  isofuzzy.c  isolsn.c isofile.c   isolist.c   isorr.c

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	$(RM) isofile2.c  isofuzzy.c  isolsn.c isofile.c   isolist.c   isorr.c
