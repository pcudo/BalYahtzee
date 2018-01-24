# BalYahtzee

Voici le jeu à refaire : https://cardgames.io/yahtzee/

Déroulement d'une partie :
- Chaque joueur joue une manche à tour de rôle.

Specifications :
- 2 joueurs humains
- 8 dés
- 6 lancés de dés par manche
- Liste des combinaisons à gerer (combinaison : score):
  - Nombre d'occurences de 1 : 1 * nbDe1
  - Nombre d'occurences de 2 : 2 * nbDe2
  - Nombre d'occurences de 3 : 3 * nbDe3
  - Nombre d'occurences de 4 : 4 * nbDe4
  - Nombre d'occurences de 5 : 5 * nbDe5
  - Nombre d'occurences de 6 : 6 * nbDe6
  - 3 dés identiques (Brelan) : Somme de tout les dés
  - 4 dés identiques (Carré) : Somme de tout les dés
  - 5 dés identiques (Yahtzee) : 50 points
  - 6 dés identiques (Emeraude) : 60 points
  - 7 dés identiques (Rubis) : 70 points
  - 8 dés identiques (Diamant) : 80 points
  - Combinaison de 5 dés identiques + 3 dés identiques : Somme de tout les dés
  - Combinaison de 4 dés identiques + 4 dés identiques : Somme de tout les dés
  - Combinaison de 3 dés identiques + 2 dés identiques (Full) : 25 points
  - Petite suite (1-2-3-4 ou 2-3-4-5 ou 3-4-5-6) : 30 points
  - Grande suite (1-2-3-4-5 ou 2-3-4-5-6) : 40 points
  - Rien de spécial (Chance) : Somme de tout les dés
