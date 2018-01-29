CC=gcc
CFLAGS=-O2 -g -std=c11
SRC=balyahtzee.c roll.c
OBJ=$(SRC:.c=.o)

%.o:	%.c
	$(CC) -c $(CFLAGS) $< 

balyahtzee: 	$(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	rm *.o balyahtzee
