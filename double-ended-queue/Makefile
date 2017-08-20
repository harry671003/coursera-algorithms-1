all: a.out

a.out: main.o dequeue.o
	g++ main.o dequeue.o

main.o: main.cpp
	g++ -c main.cpp

dequeue.o: dequeue.cpp dequeue.hpp node.hpp
	g++ -c dequeue.cpp

