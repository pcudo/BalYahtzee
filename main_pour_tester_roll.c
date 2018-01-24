#ifndef MAIN_POUR_TESTER_ROLL_C
#define MAIN_POUR_TESTER_ROLL_C

/* gcc roll.h roll.c main_pour_tester_roll.c -Wall */

#include "roll.h"

int main(){
	srand(time(NULL));	
	
	for (int i = 0;i<10;i++)
		printRoll (getRoll(8));

	StatRoll(10000);

	return 0;
}

#endif /* MAIN_POUR_TESTER_ROLL_C */
