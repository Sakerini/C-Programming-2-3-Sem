.PHONY: clean

CC := gcc
FLAGS := -std=c99 -Wall -Werror -pedantic

%.o: %.c *.h
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) *.o *.exe

test.exe: str.o test.o
	$(CC) $(FLAGS) -o $@ $^

%.exe: main.o io.o str.o
	$(CC) $(FLAGS) -o $@ $^
