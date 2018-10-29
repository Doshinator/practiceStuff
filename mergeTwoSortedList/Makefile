all : main

main : mtsl.o
	g++ mtsl.o -o main

mtsl.o : mtsl.cpp
	g++ -c -std=c++11 mtsl.cpp

clean :
	rm *.o main