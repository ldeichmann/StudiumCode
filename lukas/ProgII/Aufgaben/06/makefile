CC       = gcc
CFLAGS   = -std=c11 -Wall
DEPS = queue.c tasks.c

OBJ = main

all: $(OBJ).c
	$(CC) $(CFLAGS) $(OBJ).c $(DEPS) -o $(OBJ).out

clean:
	rm -f $(OBJ)
