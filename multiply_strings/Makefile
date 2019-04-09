all : main

main : multiply_strings.o
	gcc multiply_strings.o -o main

multiply_strings.o : multiply_strings.c
	gcc -c multiply_strings.c

clean:	
	rm *.o main