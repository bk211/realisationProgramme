#include <stdio.h>
#include <time.h>
#include <unistd.h>


typedef struct Player Player ;
struct Player {
  int *dices;
  int *dicesAllowed;
  int nbrRollRemain;
  int scoreFinal;
  int *tabScore;
  int * tabScoreFinal;
};

void initPlayer(Player *p);
void completeTurn(Player *p);
void freePlayer(Player *p);
