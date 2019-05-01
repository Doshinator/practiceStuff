CC = gcc
OBJ = src/main.o src/hash_table.o src/prime.o
EXE = main
CFLAGS = -Wall -Werror -Wextra -Wno-unused -g

all: $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)

main.o : src/main.c
	$(CC) $(CFLAGS) -c src/main.c
	
hash_table.o : src/hash_table.c src/hash_table.h
	$(CC) $(CFLAGS) -c src/hash_table.c

prim.o : src/prime.c src/prime.o
	$(CC) $(CFLAGS) -c src/prim.o
	
clean :
	rm src/*.o $(EXE)