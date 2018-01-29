#ifndef ROLL_C
#define ROLL_C

#include "roll.h"

int * getRoll(char * list_of_dice_to_roll_again){
  static int roll [6] = {0,0,0,0,0,0};
  int the_i_th_dice,nb_dice,dice;

  for (the_i_th_dice = 0; list_of_dice_to_roll_again[the_i_th_dice] ; the_i_th_dice++){
    dice = list_of_dice_to_roll_again[the_i_th_dice];
    if (the_i_th_dice >= 8 || dice < '1' || dice > '6' || roll[dice - '1'] < 1){
      fprintf(stderr, "!!!choix érroné!!!\n");
      return roll;
    }
  }

  if (the_i_th_dice == 0){
    nb_dice = 8;
    for (the_i_th_dice = 0; the_i_th_dice < nb_dice; the_i_th_dice++)
      roll[the_i_th_dice] = 0;
  } else {
    nb_dice = the_i_th_dice;
    while (the_i_th_dice--)
      -- roll[list_of_dice_to_roll_again[the_i_th_dice] - '1' ];
  }

  for (the_i_th_dice = 0; the_i_th_dice < nb_dice; the_i_th_dice++)
    roll[rand() % 6]++;

  return roll;
}

int * occToDice(int * roll){
  int * dices;
  int dice = 0;
  dices = malloc(8 * sizeof(int));
  for(int face = 0; face < 6; face++)
    for(int nb_dup = roll[face]; nb_dup; nb_dup--)
      dices[dice++] = face + 1;
  return dices;
}

#endif /* ROLL_C */
