#include <stdio.h>
#include <time.h>
typedef struct Player Player ;

struct Player {
  
  int dices[8] ={0,0,0,0,0,0,0,0} ;
  int dicesAllowed[8] ={1,1,1,1,1,1,1,1};
  int wannaRoll[6] ;
  int nbrRollRemain = 6;
  int id ;
  int map[12] ; //booleen de la grille
} ;