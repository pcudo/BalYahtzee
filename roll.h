#ifndef ROLL_H
#define ROLL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

char * ptrCharAlloc(int nb);
char * diceAlloc();

/* rend un nombre aléatoire entre 0 et max */
long randValue(int max);

/* prend un tableau "patern" de longeur "nb" 
 et rend une copie de "patern" permutée aléatoirement */
char * randomPermutation (char * patern,int nb);

char * diceArrange ();
char * listDuplicates(int nb_dice);
char * getRoll(int nb_dice);
void printRoll (char * s);
void StatRoll (int precision);

#endif /* ROLL_H */