all : main

main : reverseString.o
	g++ reverseString.o -o main

reverseString.o : reverseString.cpp
	g++ -c -std=c++11 reverseString.cpp

clean:
	rm *.o main