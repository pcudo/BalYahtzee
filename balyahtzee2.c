/*
 * =====================================================================================
 *
 *       Filename:  balyahtzee.c
 *
 *    Description:  Main game code
 *
 *        Version:  1.0
 *        Created:  01/24/2018 03:14:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Patrick Cudo (pcudo), patrick.cudo@etud.univ-paris8.fr
 *        Company:  Feel Good Inc.
 *
 * =====================================================================================
 */

#include "balyahtzee2.h"
#include "roll.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

game g;

scoreSheet_t * initScoreSheet(){
  scoreSheet_t * playerSheet;
  playerSheet = malloc(sizeof(scoreSheet));
  playerSheet->ones = -1;
  playerSheet->twos = -1;
  playerSheet->threes = -1;
  playerSheet->fours = -1;
  playerSheet->fives = -1;
  playerSheet->sixes = -1;
  playerSheet->three_of_a_kind = -1;
  playerSheet->four_of_a_kind = -1;
  playerSheet->five_of_a_kind = -1;
  playerSheet->six_of_a_kind = -1;
  playerSheet->seven_of_a_kind = -1;
  playerSheet->eight_of_a_kind = -1;
  playerSheet->five_and_three = -1;
  playerSheet->four_and_four = -1;
  playerSheet->full = -1;
  playerSheet->small_straight = -1;
  playerSheet->big_straight = -1;
  playerSheet->chance = -1;
  return playerSheet;
}

void initGame(){
  srand(time(NULL));
  g.player1 = malloc(sizeof(player));
  g.player2 = malloc(sizeof(player));
  g.player1->name = "Player1";
  g.player2->name = "Player2";
  g.player1->playerScore = initScoreSheet();
  g.player2->playerScore = initScoreSheet();
  g.player1->score = 0;
  g.player2->score = 0;
  g.turns = 0;
}

void printHeader(){
  printf("%s - Score: %d pts *** TURN %d *** %s - Score : %d pts\n", g.player1->name, g.player1->score, g.turns / 2 + 1, g.player2->name, g.player2->score);
}

static void printDice(int * roll){
    for (int the_i_th_dice = 0;the_i_th_dice < 8;the_i_th_dice++)
        printf("%d ",roll[the_i_th_dice]);
    printf("\n");
}

void gameLoop(){
  int * duplicates;
  char dice_to_roll_again[8];
  int nb_essai_max = 5;
 
  for (;;){
      dice_to_roll_again[0] = 0;
      for (int essai = 0; essai < nb_essai_max; essai++){
          duplicates = getRoll(dice_to_roll_again);
          printDice(occToDice(duplicates));
          char * ptr = dice_to_roll_again;
          do {
              * ptr = getchar();
              if (*ptr == ' ') ptr--;
          } while (*ptr++ != '\n');
          *--ptr = 0;


      }
      printf("____________tour terminée___________\n");
      printf("résultat du tour :\n...\n\n____________________________________\n");
      //evalRoll(duplicates);
  }
    
}

int main(){
  initGame();
  printHeader();
  gameLoop();
}
