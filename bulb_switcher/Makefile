all : main

main: bulbSwitcher.o
	g++ bulbSwitcher.o -o main
bulbSwitcher.o : bulbSwitcher.cpp
	g++ -c -std=c++11 bulbSwitcher.cpp
clean:
	rm *.o main