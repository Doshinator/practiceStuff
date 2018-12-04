all : main

main : stringMatching.o main.o
	g++ stringMatching.o main.o -o main
main.o : main.cpp stringMatching.h
	g++ -c -std=c++11 main.cpp
stringMatching.o : stringMatching.cpp stringMatching.h
	g++ -c -std=c++11 stringMatching.cpp
clean :
	rm *.o main