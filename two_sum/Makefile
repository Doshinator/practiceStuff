all : main

main : twoSum.o
	g++ -std=c++14 twoSum.o -o main
	
twoSum.o : twoSum.cpp
	g++ -std=c++14 -c twoSum.cpp

clean:
	rm *.o main