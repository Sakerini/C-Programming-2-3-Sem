.PHONY: clean

CC := gcc
FLAGS := -std=c99 -Wall -Werror -ggdb -pedantic

%.o: %.c *.h
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) *.o *.exe

%.exe: main.o readfile.o obj_arr.o
	$(CC) $(FLAGS) -o $@ $^

test.exe: test.o obj_arr.o readfile.o
	$(CC) $(FLAGS) -o $@ $^