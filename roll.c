#ifndef ROLL_C
#define ROLL_C

#include "roll.h"

char * ptrCharAlloc(int nb){
	char * ptr;
	ptr = malloc (nb * sizeof(char));
	assert(ptr);
	return ptr;
}

char * diceAlloc(){
	return ptrCharAlloc(6);
}


long randValue(int max){
	return rand() % max;
}

char * randomPermutation (char * patern,int nb){
	int indice_courant;
	int new_val;
	char flags [6];
	char * perm = ptrCharAlloc(nb);

	for (indice_courant = 0; indice_courant < nb; indice_courant++) 
		flags[indice_courant] = 1;

	for (indice_courant = 0; indice_courant < 6 ;indice_courant++){
		do new_val = randValue(6);
		while (!flags[new_val]);
		flags[new_val] = 0;
		perm[indice_courant] = patern[new_val];
	}
	return perm;
}


char * diceArrange (){
	static char patern [6] = {0,1,2,3,4,5};
	return randomPermutation(patern,6);
}


char * listDuplicates(int nb_dice){ 
	char * partition_duplicates; 
	int dice_accum, nb_dup,val;

	partition_duplicates = diceAlloc();
	dice_accum = 0;
	for (val = 0 ; val < 6 ; val++){
		nb_dup = randValue(nb_dice);
		dice_accum += nb_dup;
		if (dice_accum >= nb_dice){
			partition_duplicates[val] = nb_dup - (dice_accum - nb_dice);
			return partition_duplicates;
		}
		partition_duplicates[val] = nb_dup;
	}
	return listDuplicates(nb_dice);
}

char * getRoll(int nb_dice){ 
	char *perm, *duplicates;
	int val;

	perm = diceArrange();
	duplicates = listDuplicates(nb_dice);
	
	for (val = 0;val<6;val++)
		perm[val] = duplicates[(int)perm[val]];

	free(duplicates);
	return perm;
}

/* ------------------------------------------------ */
void printRoll (char * s){
	int dice_number;
	for (dice_number = 0 ; dice_number < 6 ; dice_number++)
		printf("%d ",s[dice_number]);
	printf("\n");
}

void StatRoll (int precision){
	int sum,tour,val;
	int test [6] = {0};
	char * list_dice;
	srand(time(NULL));

	sum = 0;
	for (tour = 0;tour < precision; tour++){
		list_dice = getRoll(8);
		for (val = 0; val <6;val++){
			test[val] += list_dice[val];
			sum += list_dice[val];
		}
	}

	printf("\nrépartition des dés pour %d lancés : \n",precision);

	for (val=0;val<6;val++)
		printf("\tface %d : %.2f %% \n",val+1,test[val]/(float)precision * 100);
	printf("\n\ttotal : %.2f dés \n\n",sum/(float)precision);
}

#endif /* ROLL_C */
