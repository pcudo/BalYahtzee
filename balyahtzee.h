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
typedef struct game game;

struct game{
  player * player1;
  player * player2;
  int turns;
};

struct scoreSheet{
  int ones;
  int twos;
  int threes;
  int fours;
  int fives;
  int sixes;
  int three_of_a_kind;
  int four_of_a_kind;
  int five_of_a_kind;
  int six_of_a_kind;
  int seven_of_a_kind;
  int eight_of_a_kind;
  int five_and_three;
  int four_and_four;
  int full;
  int small_straight;
  int big_straight;
  int chance;
};

struct player{
  char * name;
  short int score;
  scoreSheet * playerScore;
};

void initGame();
int * getRoll();
scoreSheet * evalRoll(scoreSheet * previousScore, int * roll);
void printRoll(char * roll);
void nextTurn();

