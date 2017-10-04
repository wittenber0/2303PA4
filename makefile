CFLAGS=-g

all: LIFE
LIFE: main.o play.o InitialBoard.o PrintBoard.o
	gcc main.o -o LIFE

main.o: main.c life.h
	gcc -c   main.c

play.o: play.c life.h
	gcc -c   play.c

InitialBoard.o: InitialBoard.c life.h
	gcc -c   InitialBoard.c	

PrintBoard.o: PrintBoard.c life.h
	gcc -c   PrintBoard.c	

clean:
	rm   =f  *.o LIFE 