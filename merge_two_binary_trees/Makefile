all : main

main : mergeTwoBinaryTrees.o
	g++ -std=c++11 -g mergeTwoBinaryTrees.o -o main

mergeTwoBinaryTrees.o : mergeTwoBinaryTrees.cpp
	g++ -std=c++11 -g -c mergeTwoBinaryTrees.cpp

clean:
	rm *.o main