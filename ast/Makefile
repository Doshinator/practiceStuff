all: main

main: AST.o
	g++ AST.o -o main

AST.o: AST.cpp
	g++ -c -std=c++11 AST.cpp

clean: 
	rm *.o main