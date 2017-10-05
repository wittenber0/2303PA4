
CFLAGS=-g

all: qSim

qSim: main.o customerEvent.o event.o tellerEvent.o tellerQue.o
	g++ -g main.o customerEvent.o event.o tellerEvent.o tellerQue.o -o qSIm

main.o: main.cpp statistics.h event.h customerEvent.h tellerEvent.h tellerQue.h
	g++ -c main.cpp

customerEvent.o: customerEvent.cpp customerEvent.h event.h
	g++ -c customerEvent.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

tellerEvent.o: tellerEvent.cpp tellerEvent.h event.h
	g++ -c tellerEvent.cpp

tellerQue.o: tellerQue.cpp tellerQue.h
	g++ -c tellerQue.cpp






clean:
	rm   -f  *.o qSim
