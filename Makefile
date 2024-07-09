FLAGS = -g -Wall -pedantic -Iclass
OBJECT = obj/main.o obj/sistemaGestao.o obj/astronautas.o obj/voos.o
INCLUDE = class/sistemaGestao.hpp

all: sistemaGestao

compile: ${OBJECT}
	g++ ${OBJECT} -o sistemaGestao

run:
	./sistemaGestao

clean:
	rm -f obj/*.o sistemaGestao

obj/main.o: src/main.cpp ${INCLUDE}
	g++ ${FLAGS} -c src/main.cpp -o obj/main.o

obj/sistemaGestao.o: src/sistemaGestao.cpp ${INCLUDE}
	g++ ${FLAGS} -c src/sistemaGestao.cpp -o obj/sistemaGestao.o

obj/astronautas.o: src/astronautas.cpp ${INCLUDE}
	g++ ${FLAGS} -c src/astronautas.cpp -o obj/astronautas.o

obj/voos.o: src/voos.cpp ${INCLUDE}
	g++ ${FLAGS} -c src/voos.cpp -o obj/voos.o