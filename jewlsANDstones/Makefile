all:main

main: JS.o
	g++ JS.o -o main

JS.o : JS.cpp
	g++ -c -std=c++11 JS.cpp

clean:
	rm *.o main