.PHONY: clean

CC := gcc
FLAGS := -std=c99 -Wall -Werror -ggdb -pedantic

%.o: %.c *.h
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) *.o *.exe

%.exe: oneproject.o
	$(CC) $(FLAGS) -o $@ $^