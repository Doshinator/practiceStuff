all: main

main: LCS.o
	g++ LCS.o -o main

LCS.o: LCS.cpp
	g++ -c -std=c++11 LCS.cpp

clean:
	rm *.o main