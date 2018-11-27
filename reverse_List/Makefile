all : main

main : reverseList.o
	g++ reverseList.o -o main

reverseList.o : reverseList.cpp
	g++ -c -std=c++11 reverseList.cpp

clean:
	rm *.o main