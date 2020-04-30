.PHONY: clean

CC := gcc
FLAGS := -std=c99 -Wall -Werror -ggdb -pedantic

%.o: %.c *.h
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) *.o *.exe

%.exe: main.o io.o find.o delete.o add.o compute.o
	$(CC) $(FLAGS) -o $@ $^ -lm

test.exe: test.o io.o find.o compute.o delete.o add.o
	$(CC) $(FLAGS) -o $@ $^ -lm
