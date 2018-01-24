/*
 * =====================================================================================
 *
 *       Filename:  balyahtzee.h
 *
 *    Description:  Header for BalYahtzee
 *
 *        Version:  1.0
 *        Created:  01/24/2018 03:14:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Patrick Cudo (pcudo), patrick.cudo@etud.univ-paris8.fr
 *        Company:  Feel Good Inc.
 *
 * =====================================================================================
 */

typedef struct scoreSheet scoreSheet;
typedef struct player player;

struct scoreSheet{
  char ones;
  char twos;
  char threes;
  char fours;
  char fives;
  char sixes;
  char three_of_a_kind;
  char four_of_a_kind;
  char five_of_a_kind;
  char six_of_a_kind;
  char seven_of_a_kind;
  char eight_of_a_kind;
  char five_and_three;
  char four_and_four;
  char full;
  char small_straight;
  char big_straight;
  char chance;
};

struct player{
  char player;
  short int score;
  char nbRolls;
  scoreSheet * playerScore;
};

void initGame();
int * getRoll();
scoreSheet * evalRoll();
void printRoll();
void nextTurn();

