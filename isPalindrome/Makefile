all: main

main: ispalindrome.o
	g++ ispalindrome.o -o main

ispalindrome.o : ispalindrome.cpp
	g++ -c -std=c++11 ispalindrome.cpp

clean:
	rm *.o main