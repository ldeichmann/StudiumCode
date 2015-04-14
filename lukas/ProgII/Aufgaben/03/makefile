CC      = gcc
CFLAGS  = -std=c11 -Wall
#LDFLAGS = -Wall -g -lm -lpthread `gtk-config --cflags` `gtk-config --libs` -lgthread
DEPS = anacae.c caesar.c

OBJ = main

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(OBJ) $(OBJ).c $(DEPS)

#%.o: %.c
#	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)
