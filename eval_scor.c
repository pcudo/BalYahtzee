#include <stdlib.h>
#include <stdio.h>
#include "balyahtzee.h"
#include "eval_scor.h"

/*
int main(){
  int t[8] = {1,2,1,2,0,2}; // rool de test
  scoreSheet_t s = initialize_scoreSheet(s); // initialisation
  s = eval(t);   // eval
  print_scoreSheet(s);      // affiche les score
  s = which_scoreSheet(s); //choisir scoreSheet 
  print_scoreSheet(s);
}
*/

//calcule les cas d'occurences
scoreSheet_t occurences(int* roll,scoreSheet_t s){
  for(int i = 0;i < 6;++i){
    if(roll[i] != 0){
      switch(i){
      case 0:
        s.ones   = 1 * roll[i];
        break;
      case 1:
        s.twos   = 2 * roll[i];
        break;
      case 2:
        s.threes = 3 * roll[i];
        break;
      case 3:
        s.fours  = 4 * roll[i];
        break;
      case 4:
        s.fives  = 5 * roll[i];
        break;
      case 5:
        s.sixes  = 6 * roll[i];
        break;
      }
    }
  }
  return s;
}

//calcul les cas identiques
scoreSheet_t identical(int* roll, scoreSheet_t s){
  for(int i = 0;i < 6;++i){
    if(roll[i] > 2){
      switch(roll[i]){
      case 3:
        s.three_of_a_kind  = 3 * (i+1);
        break;
      case 4:
        s.four_of_a_kind  = 4 * (i+1);
        break;
      case 5:
        s.five_of_a_kind  = 50;
        break;
      case 6:
        s.six_of_a_kind = 60;
        break;
      case 7:
        s.seven_of_a_kind = 70;
        break;
      case 8:
        s.eight_of_a_kind = 80;
        break;
      }
    }
  }
  return s;
}

// liste des fonctions utiles pour gérer les combinaisons 
int five_in (int* roll){
  for(int i = 0; i < 6;++i){
    if(roll[i] == 5)
      return 1;
  }
  return 0;
}

int three_in (int* roll){
  for(int i = 0; i < 6;++i){
    if(roll[i] == 3)
      return 1;
  }
  return 0;
}

int two_in(int* roll){
  for(int i = 0; i < 6;++i){
    if(roll[i] == 2)
      return 1;
  }
  return 0;
}

int four_twice(int* roll){
  int j = 0;
  for(int i = 0; i < 6;++i){
    if(roll[i] == 4)
      ++j;
    if(j == 2)
      return 1;
  }
  return 0;
}

int sum_dice(int* roll){
  int s = 0;
  for(int i = 0;i < 6;++i){
    s += roll[i] * (i+1);
  }
  return s;
}

scoreSheet_t combinaison(int* roll,scoreSheet_t s){
  if(five_in(roll) && three_in(roll))
    s.five_and_three = sum_dice(roll);

  if(four_twice(roll))
    s.four_and_four = sum_dice(roll);

  if(three_in(roll) && two_in(roll))
    s.full = 25;

  return s;
}

scoreSheet_t small_straight(int* roll, scoreSheet_t s){
  int j = 0;
  for(int i = 0;i < 6;++i){
    if(j == 4){
      s.small_straight = 30;
      return s;
    }
    if(roll[i] < roll[i+1])
      ++j;
    else
      j = 0;
  }
  return s;
}

scoreSheet_t big_straight(int* roll, scoreSheet_t s){
  int j = 0;
  for(int i = 0;i < 6;++i){
    if(j == 5){
      s.big_straight = 40;
      return s;
    }
    if(roll[i] < roll[i+1])
      ++j;
    else
      j = 0;
  }
  return s;
}

scoreSheet_t chance(int* roll,scoreSheet_t s){
  s.chance = sum_dice(roll);
  return s;
}

//Fonction evaluation du score
scoreSheet_t eval(int* roll){
  scoreSheet_t s = initialize_scoreSheet(s);
  s = occurences(roll,s);
  s = identical(roll,s);
  s = combinaison(roll,s);
  s = small_straight(roll,s);
  s = big_straight(roll,s);
  s = chance(roll,s);
  return s;
}

//fonction affichage de scoreSheet
void print_scoreSheet(scoreSheet_t s){
  printf("A -- ones                 :    %d\n",s.ones);
  printf("B -- twos                 :    %d\n",s.twos);
  printf("C -- threes               :    %d\n",s.threes);
  printf("D -- fours                :    %d\n",s.fours);
  printf("E -- fives                :    %d\n",s.fives);
  printf("F -- sixes                :    %d\n",s.sixes);
  printf("G -- three_of_a_kind      :    %d\n",s.three_of_a_kind);
  printf("H -- four_of_a_kind       :    %d\n",s.four_of_a_kind);
  printf("I -- five_of_a_kind       :    %d\n",s.five_of_a_kind);
  printf("J -- six_of_a_kind        :    %d\n",s.six_of_a_kind);
  printf("K -- seven_of_a_kind      :    %d\n",s.seven_of_a_kind);
  printf("L -- eight_of_a_kind      :    %d\n",s.eight_of_a_kind);
  printf("M -- five_and_three       :    %d\n",s.five_and_three);
  printf("N -- four_and_four        :    %d\n",s.four_and_four);
  printf("0 -- full                 :    %d\n",s.full);
  printf("P -- small_straight       :    %d\n",s.small_straight);
  printf("Q -- big_straight         :    %d\n",s.big_straight);
  printf("R -- chance               :    %d\n",s.chance);
}

scoreSheet_t which_scoreSheet(scoreSheet_t s){
  scoreSheet_t s1 = initialize_scoreSheet(s1);
  char decision = 0;
  printf("\nQuel score voulez-vous garder ?\n");
  scanf("%c",&decision);
  switch (decision){
  case 'A':
    s1.ones = s.ones;
    break;
  case 'B':
    s1.twos = s.twos;
    break;
  case 'C':
    s1.threes = s.threes;
    break;
  case 'D':
    s1.fours = s.fours;
    break;
  case 'E':
    s1.fives = s.fives;
    break;
  case 'F':
    s1.sixes = s.sixes;
    break;
  case 'G':
    s1.three_of_a_kind = s.three_of_a_kind;
    break;
  case 'H':
    s1.four_of_a_kind = s.four_of_a_kind;
    break;
  case 'I':
    s1.five_of_a_kind = s.five_of_a_kind;
    break;
  case 'J':
    s1.six_of_a_kind = s.six_of_a_kind;
    break;
  case 'K':
    s1.seven_of_a_kind = s.seven_of_a_kind;
    break;
  case 'L':
    s1.eight_of_a_kind = s.eight_of_a_kind;
    break;
  case 'M':
    s1.five_and_three = s.five_and_three;
    break;
  case 'N':
    s1.four_and_four = s.four_and_four;
    break;
  case 'O':
    s1.full = s.full;
    break;
  case 'P':
    s1.small_straight = s.small_straight;
    break;
  case 'Q':
    s1.big_straight = s.big_straight;
    break;
  case 'R':
    s1.chance = s.chance;
    break;
  }
  return s1;
}

scoreSheet_t initialize_scoreSheet(scoreSheet_t s){
  s.ones = 0;
  s.twos = 0;
  s.threes = 0;
  s.fours = 0;
  s.fives = 0;
  s.sixes = 0;
  s.three_of_a_kind = 0;
  s.four_of_a_kind = 0;
  s.five_of_a_kind = 0;
  s.six_of_a_kind = 0;
  s.seven_of_a_kind = 0;
  s.eight_of_a_kind = 0;
  s.five_and_three = 0;
  s.four_and_four = 0;
  s.full = 0;
  s.small_straight = 0;
  s.big_straight = 0;
  s.chance = 0;
  return s;
}
