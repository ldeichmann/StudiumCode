CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra
#LDFLAGS = -Wall -g -lm -lpthread `gtk-config --cflags` `gtk-config --libs` -lgthread
#DEPS =
OBJ = ex04

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(OBJ) $(OBJ).c $(DEPS)

#%.o: %.c
#	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)
