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
#include "create_grid.h"
#include "defaite.h"
#include "put_couler.h"
#include "test_couler.h"
#include "afficha.h"

char * nomjoueur(void);
void viderbuffer(void);
void findepartie(void);
void insert(char **grid, int ligne  , int colonne);
int verifie (char **grid, int ligne  , int colonne);
int attaquer(char **grid);
void boucle(char **grid1 , char** grid2, char ** grid3);
