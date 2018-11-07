all: main

main: lvOrder.o
	g++ lvOrder.o -o main
lvOrder.o: lvOrder.cpp
	g++ -c -std=c++11 lvOrder.cpp
clean:
	rm *.o main