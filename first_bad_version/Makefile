all : main

main : firstBadVersion.o
	g++ firstBadVersion.o -o main

firstBadVersion.o : firstBadVersion.cpp
	g++ -c -std=c++11 firstBadVersion.cpp

clean:
	rm *.o main