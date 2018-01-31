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

typedef struct scoreSheet_t scoreSheet_t;
typedef struct player_t player_t;
typedef struct game_t game_t;

struct game_t{
  player_t * player1;
  player_t * player2;
  int * dices;
  char * rerollStr;
  int rollId;
  int turns;
};

struct scoreSheet_t{
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

struct player_t{
  char * name;
  short int score;
  scoreSheet_t * playerScore;
};

void initGame();
int * getRoll();
scoreSheet_t * evalRoll(scoreSheet_t * previousScore, int * roll);
void printRoll(char * roll);
void nextTurn();

