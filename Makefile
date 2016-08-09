TARG = quine
SRC = quine.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -O2

$(TARG):	$(OBJ)

clean:
	rm -f $(TARG) $(OBJ)

.PHONY: all clean

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
