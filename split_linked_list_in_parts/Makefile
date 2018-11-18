all : main

main : splitList.o
	g++ splitList.o -o main

splitList.o : splitList.cpp
	g++ -c -std=c++11 splitList.cpp

clean:
	rm *.o main