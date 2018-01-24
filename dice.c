#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

char * alloc_de(){
	char * de = malloc (6 * sizeof(char));
	assert(de);
	return de;
}

/* rend un nombre aléatoire entre 0 et max */

long alea(int max){

	static int Nonce = 0; // = rand(); 
	srand(Nonce++);
	return rand() % max;
}

char * arrange (){
	char valeur;
	char crible[6]= {1,1,1,1,1,1};

	char * arrangement = alloc_de();
	for (int n=0;n<6;n++){
		do {
		   valeur = alea(6);
		} while (!crible[valeur]);
		crible[valeur] = 0;
		arrangement[n] = valeur;
	}
	return arrangement;
}

char * listeDoublon(int nb_de){ 
	char * partition_doublons = alloc_de();
	int nb_lance = 0;
	for (int indice = 0;indice<6;indice++){
		int tmp = alea(nb_de);
		nb_lance += tmp;
		if (nb_lance >= nb_de){
			partition_doublons[indice] = tmp - (nb_lance - nb_de);
			break;
		}
		partition_doublons[indice] = tmp;
	}
	return partition_doublons;
}

char * map(int nb_de){ 
	char * p = arrange();
	char * t = listeDoublon(nb_de);
	for (int i = 0;i<6;i++){
		p[i] = t[p[i]];
	}
	return p;
}

void affiche (char * s){
		for (int i=0;i<6;i++)
			printf("%d ",s[i]);
	printf("\n");
}

int main(){
	for (int i=0;i<20;i++)
		affiche (map(8));
	return 0;
}

/*
x1 x2 x3 x4 x5 x6
3   4 1  0  0  0

x1 3
x2 4
x3 1
x4 
x5
x6 

x1 6
x2 4
x3 5
x4 2 


{1 4 5 2 3 6}
4 6 2 



{3, 0,1,0,0,5}
*/
