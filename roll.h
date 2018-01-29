#ifndef ROLL_H
#define ROLL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Si l'argument est un chaîne vide, génère un lancé aléatoire de 8 dés.
 *                                   par exemple {0 1 4 0 2 1}.
 *                                                     (c'est à dire 0 fois la face 1, 
 *                                                                   1 fois la face 2, 
 *                                                                   4 fois la face 3,  
 *                                                                   0 fois la face 4, 
 *                                                                   2 fois la face 5, 
 *                                                                   1 fois la face 6 )
 *
 * Maintenant, supposons avoir déjà lancé les 8 dés et avoir obtenu {0 1 4 0 2 1} 
 * On affiche avec printRoll quelque chose comme $$$ 2 3 3 3 3 5 5 6 $$$
 * Dans ce cas là, le joueur peut vouloir relancer (par exemple) les dés 2,5,5 et 6.
 *
 * Nous appelons donc :    getRoll("2556")    qui va nous générer
 *           {1 0 4 3 0 0}    -> $$$ 1 3 3 3 3 4 4 4 $$$
 * ou bien   {0 0 4 0 0 4}    -> $$$ 3 3 3 3 6 6 6 6 $$$
 * ou bien   {1 0 6 1 0 0}    -> $$$ 1 3 3 3 3 3 3 4 $$$
 * ou bien   {0 0 8 0 0 0}    -> $$$ 3 3 3 3 3 3 3 3 $$$
 * etc.
 */

int * getRoll(char * list_of_dice_to_roll_again);



int * occToDice(int duplicates [6]);

#endif /* ROLL_H */
