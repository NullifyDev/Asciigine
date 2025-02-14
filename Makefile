# Sphere Binary File

CFLAGS = -g -pg -static -Wno-builtin-declaration-mismatch
# CFLAGS = -g -fsanitize=address -Wno-builtin-declaration-mismatch

# CLFAGS = -O3 -g3 -W -Wall -Wextra -Wuninitialized -Wstrict-aliasing -pedantic
CSOURCE = $(shell find src -name '*.c')

OBJ = $(patsubst src/%.c, bin/asciigine.o, $(CSOURCE))
BIN = $(shell find bin -name '*.o')

gcc = $(shell gcc $(CFLAGS) $(OBJ))

run: rebuild
	clear
	chmod +x ./bin/asciigine.o && ./bin/asciigine.o

debug: rebuild
	chmod +x ./bin/asciigine.o
	clear

build:
	gcc $(CFLAGS) $(CSOURCE) -o bin/asciigine.o
	
bin/%.o: src/%.c
	gcc $(CFLAGS) $(CSOURCE)  -o bin/asciigine.o

clean:
	-rm -rf ./bin/*
	-rm ./bin./asciigine.o
	clear

rebuild: clean build
	clear