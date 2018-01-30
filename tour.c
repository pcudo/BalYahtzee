#ifndef TOUR_C
#define TOUR_C

#include "tour.h"

static int Distrib[6];

void tourInit(){
  int face;
  for (face = 0; face < 6; face++)
    Distrib[face] = 0;
}

void roll(int nb_dice){
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
  roll(strLen(to_roll_again));
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

int whatCombination(){
  int num_comb;
  do {
    printf("\nquelle combinaison voulez-vous garder ?\n");
    printf("{1 : ones} {2 : twos} {3 : threes} {4 : fours} {5 : fives} {6 : sixes}");
    printf("{7 : Brelan} {8 : Carré} {9 : Full} {10 : Petite Suite} {11 : Grande Suite} {12 : Yams} { 13 Chance}\n");
    scanf("%d",&num_comb);
  } while (num_comb > 18 && num_comb < 1); 
  return num_comb;
}

int tour(){
  int try;
  char * dice;
  roll(NB_DICE);

  do
    printf("\nSaisir 'entrer' pour lancer les dés.\n");
  while (getchar() != '\n');

  for (try = 1;try < NB_TRY_MAX;try++){

    printRoll(distribToRoll(Distrib));

    if (!tryAgain(try))
      break;

    printf("quels dés voulez-vous relancer ?\n");
    dice = whatDice();

    if (verify(dice))
      rollAgain(dice);
    else 
      fprintf(stderr, "!!!choix érroné!!!\n");
  }
  return whatCombination();
}

int main(){
  printf("resultat du tour : %d\n", tour());
}






#endif /* TOUR_C */
