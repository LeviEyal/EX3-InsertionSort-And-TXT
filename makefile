
CC = gcc
FLAGS = -Wall
.PHONY: all clean

all: isort txtfind

isort: part1/main.c
	$(CC) $(FLAGS) -o isort part1/main.c

txtfind: part2/main.c
	$(CC) $(FLAGS) -o txtfind part2/main.c

runIsort: isort
	./isort < part1/test1.txt
clean:
	rm *.o isort txtfind