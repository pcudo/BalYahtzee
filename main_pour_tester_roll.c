#ifndef MAIN_POUR_TESTER_ROLL_C
#define MAIN_POUR_TESTER_ROLL_C

#include "roll.h"

/* pour tester :
 * gcc roll.c main_pour_tester_roll.c roll.h -Wall
 */

static void localPrintRoll(int * roll){
  for (int the_i_th_dice = 0;the_i_th_dice < 8;the_i_th_dice++)
    printf("%d ",roll[the_i_th_dice]);
  printf("\n");
}


int main(){
  srand(time(NULL));
  char dice_to_roll_again [8] = "";
   
  for (;;){
    localPrintRoll(occToDice(getRoll(dice_to_roll_again)));
    printf("\n\tsaisisez les dés que vous souhaitez relancer.\n\texemple : \"134\" pour relancer les dés 1, 3 et 4\n\n");
        
    char * ptr = dice_to_roll_again; 
    do * ptr = getchar();
    while (*ptr++ != '\n');
    *--ptr = 0;
  }
  return 0;
}

#endif /* MAIN_POUR_TESTER_ROLL_C */
