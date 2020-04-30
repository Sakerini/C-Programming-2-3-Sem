.PHONY: clean

CC := gcc
FLAGS := -std=c99 -Wall -Werror -ggdb -pedantic

%.o: %.c *.h
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) *.o *.exe

%.exe: main.o readfile.o stud_arr.o process.o
	$(CC) $(FLAGS) -o $@ $^