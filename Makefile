BIN = quine

CFLAGS = -Wall -O2

all: ${BIN}

install: ${BIN}
	cp ${BIN} ${HOME}/bin

clean:
	rm -f ${BIN} *.o

.PHONY: all clean
