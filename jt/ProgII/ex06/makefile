CC      = gcc
CFLAGS  = -Wall -g -lm -std=c11
#LDFLAGS = -lm -lpthread `gtk-config --cflags` `gtk-config --libs` -lgthread
LIBS = tasks.c queue.c

OBJ = main

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(OBJ) $(OBJ).c $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)
