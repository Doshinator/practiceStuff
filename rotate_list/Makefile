all : main

main : rotate_list.o
	g++ rotate_list.o -o main

rotate_list.o : rotate_list.cpp
	g++ -c -std=c++11 rotate_list.cpp

clean :
	rm *.o main