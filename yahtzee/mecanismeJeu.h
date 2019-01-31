#include <stdio.h>
#include <time.h>
#include <unistd.h>
typedef struct Player Player ;
struct Player {
  int dices[8];
  int dicesAllowed[8];
  int wannaRoll[6] ;
  int nbrRollRemain;
  int id ;
  int map[12] ; //booleen de la grille
  int score;
} ;