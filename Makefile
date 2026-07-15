CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = build/ISHell.exe

SRC = \
	src/main.c \
	src/parser.c

BUILTINS = \
	builtin/builtin.c \
	builtin/cd.c \
	builtin/pwd.c \
	builtin/clear.c \
	builtin/exit.c \

OBJECTS = $(SRC:src/%.c=build/%.o) \
			$(BUILTINS:builtin/%.c=build/%.o)


$(TARGET): $(OBJECTS) | $(dir $(OBJECTS))
	$(CC) $(OBJECTS) -o $@

build/%.o: src/%.c include/parser.h | $(dir $(OBJECTS))
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: builtin/%.c include/builtin.h | $(dir $(OBJECTS))
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*.o build/ISHell.exe

%/:
	mkdir "$@"