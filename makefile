
CC = gcc
FLAGS = -Wall
.PHONY: all clean

all: isort txtfind

isort: isort.c
	$(CC) $(FLAGS) -o isort isort.c

txtfind: txtfind.c
	$(CC) $(FLAGS) -o txtfind txtfind.c

clean:
	rm isort txtfind