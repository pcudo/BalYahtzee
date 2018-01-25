#include <stdlib.h>
#include <stdio.h>
#include "balyahtzee.h"
#include "eval_scor.h"


int main(){
  int t[8] = {3,0,0,0,2,3}; // rool de test
  scoreSheet s = initialize_scoreSheet(s); // initialisation
  s = eval(t);   // eval
  print_scoreSheet(s);      // affiche les score
}

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
  scoreSheet s = initialize_scoreSheet(s);
  s = occurences(roll,s);
  s = identical(roll,s);
  s = combinaison(roll,s);
  s = small_straight(roll,s);
  s = big_straight(roll,s);
  s = chance(roll,s);
  return s;
}

//fonction affichage de scoreSheet
void print_scoreSheet(scoreSheet s){
  printf("ones                 :    %d\n\n",s.ones);
  printf("twos                 :    %d\n\n",s.twos);
  printf("threes               :    %d\n\n",s.threes);
  printf("fours                :    %d\n\n",s.fours);
  printf("fives                :    %d\n\n",s.fives);
  printf("sixes                :    %d\n\n",s.sixes);
  printf("three_of_a_kind      :    %d\n\n",s.three_of_a_kind);
  printf("four_of_a_kind       :    %d\n\n",s.four_of_a_kind);
  printf("five_of_a_kind       :    %d\n\n",s.five_of_a_kind);
  printf("six_of_a_kind        :    %d\n\n",s.six_of_a_kind);
  printf("seven_of_a_kind      :    %d\n\n",s.seven_of_a_kind);
  printf("eight_of_a_kind      :    %d\n\n",s.eight_of_a_kind);
  printf("five_and_three       :    %d\n\n",s.five_and_three);
  printf("four_and_four        :    %d\n\n",s.four_and_four);
  printf("full                 :    %d\n\n",s.full);
  printf("small_straight       :    %d\n\n",s.small_straight);
  printf("big_straight         :    %d\n\n",s.big_straight);
  printf("chance               :    %d\n",s.chance);
}

scoreSheet initialize_scoreSheet(scoreSheet s){
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
