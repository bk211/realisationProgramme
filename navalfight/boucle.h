/**
 * \file      boucle.h
 * \brief     Le header comportant les includes et prototype des fonctions
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define Dim 20
char * nomjoueur(void);
void viderbuffer(void);
void findepartie(void);
void insert(char **grid, int ligne  , int colonne);
int verifie (char **grid, int ligne  , int colonne);
int attaquer(char **grid);
void boucle(char **grid, char**);
