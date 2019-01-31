#include <stdio.h>
#include <time.h>
typedef struct Player Player ;

struct Player {
  
  int *dices ;
  int wannaRoll[6] ;
  int nbrRollRemain ;
  int id ;
  int map[12] ; //booleen de la grille
} ;