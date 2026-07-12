CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

build/ISHell: build/main.o build/command.o build/parser.o
	$(CC) build/main.o build/command.o build/parser.o -o build/ISHell

build/main.o: src/main.c include/command.h include/parser.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/command.o: src/command.c include/command.h
	$(CC) $(CFLAGS) -c src/command.c -o build/command.o

build/parser.o: src/parser.c include/parser.h
	$(CC) $(CFLAGS) -c src/parser.c -o build/parser.o