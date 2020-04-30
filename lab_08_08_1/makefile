.PHONY: clean run

CC := gcc
FLAGS := -std=c99 -Wall -Werror -ggdb

clean:
	$(RM) *.o *.exe
	
main.o: main.c io.h err.h process.h add_or_delete.h
	$(CC) $(FLAGS) -c main.c

io.o: io.c io.h err.h
	$(CC) $(FLAGS) -c io.c
	
process.o: process.c process.h
	$(CC) $(FLAGS) -c process.c
	
add_or_delete.o: add_or_delete.c add_or_delete.h process.h err.h
	$(CC) $(FLAGS) -c add_or_delete.c
	
app.exe: main.o io.o process.o add_or_delete.o
	$(CC) $(FLAGS) -o app.exe main.o io.o process.o add_or_delete.o
	
test.exe: add_or_delete.o test.o process.o
	gcc -std=c99 -Wall -Werror -ggdb -o test.exe add_or_delete.o test.o process.o