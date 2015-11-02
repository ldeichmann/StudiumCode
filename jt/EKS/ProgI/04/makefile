CC      = gcc
CFLAGS  = -std=c11 -lm
#LDFLAGS = -Wall -g -lm -lpthread `gtk-config --cflags` `gtk-config --libs` -lgthread -Wall -Wextra
DEPS = pr4.c
OBJ = pr4main

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(OBJ) $(OBJ).c $(DEPS)

#%.o: %.c
#	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)
