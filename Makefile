TARG ?= quine
SRC = $(TARG).c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -O2

$(TARG):	$(OBJ)

clean:
	rm -f $(TARG) $(OBJ) $(TARG).exe

.PHONY: all clean

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
