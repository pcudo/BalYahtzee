
CC=gcc

SRC=roll.c balyahtzee2.c
OBJ=$(SRC:.c=.o)
EXEC=yam
CFLAGS=-Wall

$(EXEC):    $(OBJ) roll.h balyahtzee2.h
			$(CC) -o $@ $(OBJ)
%.o:		%.c
			$(CC) -c $< $(CFLAGS)

clean:
	rm *.o *~ core