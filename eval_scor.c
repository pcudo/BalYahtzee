#include <stdlib.h>
#include <stdio.h>
#include "balyahtzee.h"

//calcule les cas d'occurences
scoreSheet occurences(int* roll,scoreSheet s){
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
scoreSheet identical(int* roll, scoreSheet s){
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

scoreSheet combinaison(int* roll,scoreSheet s){
  if(five_in(roll) && three_in(roll))
    s.five_and_three = sum_dice(roll);

  if(four_twice(roll))
    s.four_and_four = sum_dice(roll);

  if(three_in(roll) && two_in(roll))
    s.full = 25;

  return s;
}

scoreSheet small_straight(int* roll, scoreSheet s){
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

scoreSheet big_straight(int* roll, scoreSheet s){
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

scoreSheet chance(int* roll,scoreSheet s){
  s.chance = sum_dice(roll);
  return s;
}

//Fonction evaluation du score
scoreSheet eval(int* roll){
  scoreSheet s = occurences(roll,s);
  s = identical(roll,s);
  s = combinaison(roll,s);
  s = small_straight(roll,s);
  s = big_straight(roll,s);
  s = chance(roll,s);
  return s;
}

//fonction affichage de scoreSheet
void print_scoreSheet(scoreSheet s){
  printf("s.ones                 : %d\n",s.ones);
  printf("s.twos                 : %d\n",s.twos);
  printf("s.threes               : %d\n",s.threes);
  printf("s.fours                : %d\n",s.fours);
  printf("s.fives                : %d\n",s.fives);
  printf("s.sixes                : %d\n",s.sixes);
  printf("three_of_a_kind        : %d\n",s.three_of_a_kind);
  printf("four_of_a_kind         : %d\n",s.four_of_a_kind);
  printf("five_of_a_kind         : %d\n",s.five_of_a_kind);
  printf("six_of_a_kind          : %d\n",s.six_of_a_kind);
  printf("seven_of_a_kind        : %d\n",s.seven_of_a_kind);
  printf("eight_of_a_kind        : %d\n",s.eight_of_a_kind);
  printf("five_and_three         : %d\n",s.five_and_three);
  printf("four_and_four          : %d\n",s.four_and_four);
  printf("full                   : %d\n",s.full);
  printf("small_straight         : %d\n",s.small_straight);
  printf("big_straight           : %d\n",s.big_straight);
  printf("chance                 : %d\n",s.chance);
}

