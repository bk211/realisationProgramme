/**
 * \file      mecanismeJeu.h
 * \author    groupe3
 * \date      07 mars 2019
 * \brief     Le header du fichier mecanismeJeu.c 
 *
 *                  
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "score.h"
#define MAX_COMBINATOIRE 20


typedef struct Player Player ;
struct Player {
  int *dices;
  int *dicesAllowed;
  int nbrRollRemain;
  int scoreFinal;
  int *tabScore;
  int *tabScoreFinal;
};

int tirage(int max);
void rollDices(Player *p);
void refreshDices(Player *p);
void displayDices(Player *p);
void askDices(Player *p);
void completeTurn(Player *p);
void freePlayer(Player *p);
void initPlayer(Player *p);
