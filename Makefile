
CC=gcc

SRC=tour.c printRoll.c main.c
OBJ=$(SRC:.c=.o)
EXEC=yam
CFLAGS=-Wall

$(EXEC):    $(OBJ)
			$(CC) -o $@ $(OBJ)
main.o:		main.c balyahtzee.h
			$(CC) -c main.c $(CFLAGS)
printRoll.o:		printRoll.c printRoll.h balyahtzee.h
			$(CC) -c printRoll.c $(CFLAGS)
tour.o:		tour.c tour.h balyahtzee.h
			$(CC) -c tour.c $(CFLAGS)
clean:
	rm *.o *~ core