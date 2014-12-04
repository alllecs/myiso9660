CC=gcc

CFLAGS=-W -Wall

all: isolist

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	$(RM) isolist
