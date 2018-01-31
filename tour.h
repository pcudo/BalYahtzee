#ifndef TOUR_H
#define TOUR_H

#define NB_TRY_MAX 6
#define NB_DICE 8

void tourInit();
void toRoll(int nb_dice);
void removeDice(char * to_roll_again);
int strLen(char * str);

_Bool verify(char * to_roll_again);

void rollAgain(char * to_roll_again);
int * distribToRoll(int Distrib [6]);
void input(char * buf);
_Bool tryAgain(int try);
char * whatDice();
void printRoll(int * roll);

int * tour();

#endif /* TOUR_H */
