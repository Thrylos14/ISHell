CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

ISHell: main.o
	$(CC) build/main.o -o build/ISHell

main.o: src/main.c include/command.h include/parser.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o