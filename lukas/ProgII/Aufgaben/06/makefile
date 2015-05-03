CC      = gcc
CFLAGS  = -std=c11 -Wall
#LDFLAGS = -Wall -g -lm -lpthread `gtk-config --cflags` `gtk-config --libs` -lgthread
DEPS = tasks.c queue.c

OBJ = main

prog: $(OBJ)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ) -o $(OBJ).out

#%.o: %.c
#	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)
