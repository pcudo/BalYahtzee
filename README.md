# BalYahtzee

Voici le jeu à refaire : https://cardgames.io/yahtzee/

Déroulement d'une partie :
- Chaque joueur joue une manche à tour de rôle.
- Une partie se joue en 18 manches pour chaque joueur. Chaque joueur doit avoir un score renseigné en fonction des lancers de dés sur chaque ligne de la feuille de score.
- Une manche se joue en 6 lancers au maximum. Le joueur peut choisir de conserver de 1 à 7 dés entre chaque lancer.
- Le joueur n'a pas l'obligation de faire 6 lancers si le resultat lui convient.
- Le gagnant est le joueur qui a le plus haut score final.

Specifications :
- 2 joueurs humains.
- 8 dés.
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

Repartition des tâches :
- Loic -> Generation de lancer aléatoire.
- Adham -> Evaluation des scores en fonction de chaque lancers.
- Nisar -> Interface graphique (?) (Ajouter des représentations graphiques pour chaque dés). 
- Patrick -> Gestion de la partie et intégration.
