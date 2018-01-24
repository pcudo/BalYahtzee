#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

char * allocation(int nb){
  char * t = malloc (nb * sizeof(char));
  assert(t);
  return t;
}

char * alloc_de(){
  return allocation(6);
}

/* rend un nombre aléatoire entre 0 et max */
long alea(int max){
  return rand() % max;
}

/* prend un tableau "patern" de longeur "nb" 
   et rend une copie de "patern" permuté aléatoirement */
char * permutationAleatoire (char * patern,int nb){
  char val;
  char * flags = allocation(nb);
  char * perm = allocation(nb);

  for (int i = 0;i < nb;i++) 
    flags[i] = 1;

  for (int n=0;n<6;n++){

    do val = alea(6);
    while (!flags[val]);

    flags[val] = 0;
    perm[n] = patern[val];
  }
  free(flags);
  return perm;
}


char * dice_arrange (){
  static char s [6] = {0,1,2,3,4,5};
  return permutationAleatoire(s,6);
}


char * list_duplicates(int nb_dice){ 
  char * partition_duplicates = alloc_de();
  int dice_accum = 0;
  int how_many;
  for (int val = 0;val<6;val++){
    how_many = alea(nb_dice);
    dice_accum += how_many;
    if (dice_accum >= nb_dice){
      partition_duplicates[val] = how_many - (dice_accum - nb_dice);
      return partition_duplicates;
    }
    partition_duplicates[val] = how_many;
  }
  return list_duplicates(nb_dice);
}

char * map(int nb_dice){ 
  char * perm = dice_arrange();
  char * duplicates = list_duplicates(nb_dice);
  for (int val = 0;val<6;val++)
    perm[val] = duplicates[perm[val]];
  return perm;
}

void affiche (char * s){
  for (int i=0;i<6;i++)
    printf("%d ",s[i]);
  printf("\n");
}

void test (int n){
  char * p;
  int test [6] = {0,0,0,0,0,0};
  int sum = 0;
  for (int i=0;i<n;i++){
    p = map(8);
    for (int j = 0; j < 6;j++){
      test[j] += p[j];
      sum += p[j];
    }
  }
  for (int i=0;i<6;i++)
    printf("%d ",test[i]);
  printf("\n");
  printf("sum : %d \n",sum);
}

int main(){
  srand(time(NULL));

  for (int i = 0;i<10;i++)
    affiche (map(8));

  test(100);

  return 0;
}
