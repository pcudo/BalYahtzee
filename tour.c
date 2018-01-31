#ifndef TOUR_C
#define TOUR_C

#include "balyahtzee"
#include "tour.h"

static int Distrib[6];

void tourInit(){
  int face;
  for (face = 0; face < 6; face++)
    Distrib[face] = 0;
}

void toRoll(int nb_dice){
  for (int i = 0; i < nb_dice; i++)
    Distrib[rand() % 6]++;
}

void removeDice(char * to_roll_again){
  for (int dice = 0; to_roll_again[dice]; dice++)
    Distrib[to_roll_again[dice]-'1']--;
}

int strLen(char * str){
  int acc;
  for (acc = 0;*str;str++)
    acc++;
  return acc;
}

_Bool verify(char * to_roll_again){
  int i,dice;
  for (i = 0; to_roll_again[i] ; i++){
    dice = to_roll_again[i];
    if (i >= 8 || dice < '1' || dice > '6' || Distrib[dice - '1'] < 1)
      return 0;
  }
  return 1;
} 

void rollAgain(char * to_roll_again){
  removeDice(to_roll_again);
  toRoll(strLen(to_roll_again));
}

int * distribToRoll(int Distrib [6]){
  static int roll [8];
  int dice = 0;
  for (int face = 0; face < 8; face++)
    for (int nb_dup = Distrib[face];nb_dup;nb_dup--)
      roll [dice++] = face+1;
  return roll;
}

void input(char * buf){
  char * ptr;
  ptr = buf;
  do { 
    *ptr = getchar();
    if (*ptr == ' ') 
      ptr--;
  } while (*ptr++ != '\n');
  *(ptr-1) = '\0';
}

_Bool tryAgain(int try){
  char buf[128];
  printf("\t\t\t(essai %d)\n",try); 
  for (;;){
    printf("voulez-vous relancer certains dés ? [\"y\" pour oui, \"n\" pour non]\n");  
    input(buf);
    if (buf[0] == 'y')
      return 1;
    if (buf[0] == 'n')
      return 0;
  }   
}

char * whatDice(){
  static char releases[128];
  input(releases); 
  return releases;
}

void printRoll(int * roll){
  printf("_______________\n");
  for (int dice = 0;dice < NB_DICE;dice++)
    printf("%d ",roll[dice]);
  printf("\n");
}



int * tour(){
  int try;
  int * roll;
  char * dice;
  
  toRoll(NB_DICE);

  do
    printf("\nSaisir 'entrer' pour lancer les dés.\n");
  while (getchar() != '\n');

  for (try = 1;try < NB_TRY_MAX;try++){
      roll = distribToRoll(Distrib);
    printRoll(roll);

    if (!tryAgain(try))
      break;

    printf("quels dés voulez-vous relancer ?\n");
    dice = whatDice();

    if (verify(dice))
      rollAgain(dice);
    else 
      fprintf(stderr, "!!!choix érroné!!!\n");
  }
    return roll;
}

#endif /* TOUR_C */
