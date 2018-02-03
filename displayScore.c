#include "balyahtzee.h"

void displayScore(scoreSheet_t* score){
    int line ;
    for (line = 1 ;line <= 14 ; line ++){
        if (line == 1 || line == 7 || line == 8 || line == 14)
            printf("+-----------------------------------------------------------------------------------------+\n");
        else if (line == 3 || line == 5 || line == 10 || line == 12)
            printf("|-----------------------------------------------------------------------------------------|\n");   
        else if (line == 2)
            printf("|Ones     |Twos     |Threes   |Fours    |Fives    |Sixes    |Brelan   |Carré    |Yahtzee  |\n");
        else if (line == 9)
            printf("|Emeraude |Rubis    |Diamant  |CinqTrois|Half     |Full     |PtSuite  |GdSuite  |Chance   |\n");
        else if (line == 6)
            printf("|    a    |    b    |    c    |    d    |    e    |    f    |    g    |    h    |    i    |\n");
        else if (line == 13)
            printf("|    j    |    k    |    l    |    m    |    n    |    o    |    p    |    q    |    r    |\n");
        else if (line == 4){
            if (score->ones < 10)
                printf("|%d        |",score->ones);
            if (score->ones > 10)
                printf("%d       |",score->ones);              
            if (score->twos < 10)
                printf("%d        |",score->twos);
            if (score->twos > 10)
                printf("%d       |",score->twos);   
            if (score->threes < 10)
                printf("%d        |",score->threes);
            if (score->threes > 10)
                printf("%d       |",score->threes);          
            if (score->fours < 10)
                printf("%d        |",score->fours);
            if (score->fours > 10)
                printf("%d       |",score->fours);  
            if (score->fives < 10)
                printf("%d        |",score->fives);
            if (score->fives > 10)
                printf("%d       |",score->fives);  
            if (score->sixes < 10)
                printf("%d        |",score->sixes);
            if (score->sixes > 10)
                printf("%d       |",score->sixes);
            if (score->three_of_a_kind < 10)
                printf("%d        |",score->three_of_a_kind);
            if (score->three_of_a_kind > 10)
                printf("%d       |",score->three_of_a_kind);
            if (score->four_of_a_kind < 10)
                printf("%d        |",score->four_of_a_kind);
            if (score->four_of_a_kind > 10)
                printf("%d       |",score->four_of_a_kind);   
            if (score->five_of_a_kind < 10)
                printf("%d        |\n",score->five_of_a_kind);
            if (score->five_of_a_kind > 10)
                printf("%d       |\n",score->five_of_a_kind);
        }
        else if (line == 11){
            if (score->six_of_a_kind < 10)
                printf("|%d        |",score->six_of_a_kind);
            if (score->six_of_a_kind >= 10)
                printf("|%d       |",score->six_of_a_kind);              
            if (score->seven_of_a_kind < 10)
                printf("%d        |",score->seven_of_a_kind);
            if (score->seven_of_a_kind > 10)
                printf("%d       |",score->seven_of_a_kind);   
            if (score->eight_of_a_kind < 10)
                printf("%d        |",score->eight_of_a_kind );
            if (score->eight_of_a_kind > 10)
                printf("%d       |",score->eight_of_a_kind );          
            if (score->five_and_three < 10)
                printf("%d        |",score->five_and_three);
            if (score->five_and_three > 10)
                printf("%d       |",score->five_and_three);  
            if (score->four_and_four < 10)
                printf("%d        |",score->four_and_four);
            if (score->four_and_four > 10)
                printf("%d       |",score->four_and_four);  
            if (score->full < 10)
                printf("%d        |",score->full);
            if (score->full > 10)
                printf("%d       |",score->full);
            if (score->small_straight < 10)
                printf("%d        |",score->small_straight);
            if (score->small_straight > 10)
                printf("%d       |",score->small_straight);
            if (score->big_straight < 10)
                printf("%d        |",score->big_straight);
            if (score->big_straight > 10)
                printf("%d       |",score->big_straight);   
            if (score->chance < 10)
                printf("%d        |",score->chance);
            if (score->chance > 10)
                printf("%d       |\n",score->chance);
        }
    }
}

//Main test
/*
int main(){
    scoreSheet_t * t = malloc(sizeof(*t));
    t->ones = 1;
    t->twos = 2;
    t->threes =3;
    t->fours =4;
    t->fives =5;
    t->sixes =6;
    t->three_of_a_kind =7;
    t->four_of_a_kind =8;
    t->five_of_a_kind =9;
    t->six_of_a_kind =10;
    t->seven_of_a_kind =11;
    t->eight_of_a_kind =12;
    t->five_and_three  =13;
    t->four_and_four =14;
    t->full =15 ;
    t->small_straight =16;
    t->big_straight =17;
    t->chance =18;
    
    displayScore(t);
}
/*