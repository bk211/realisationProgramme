#include <stdio.h>
#include <time.h>
#include <unistd.h>
typedef struct Player Player ;
struct Player {
  int *dices;
  int *dicesAllowed;
  int nbrRollRemain;
  int id ;
  int score;
  int *tabScore;

} ;

void initPlayer(Player *p);
void completeTurn(Player *p);
void freePlayer(Player *p);
