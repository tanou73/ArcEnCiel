SRC = ArcEnCiel.cpp Contexte.cpp Cracker.cpp main.cpp sha1.cpp

HEADERS = ArcEnCiel.h Contexte.h Cracker.h sha1.h

all: crack

crack: ${SRC} ${HEADERS}
	g++ ${SRC} -o crack

clean:
	rm -f crack

