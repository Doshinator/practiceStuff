all : main

main : findFirst.o
	gcc findFirst.o -o main

findFirst.o : findFirst.c
	gcc -c findFirst.c

clean:
	rm *.o main