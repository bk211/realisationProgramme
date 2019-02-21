/**
 * \file      test_couler.h
 * \brief     Le header comportant les includes et prototype des fonctions
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define Dim 20
int couler_droite(int x,int y, char ** grid, int conteur);
int couler_gauche(int x,int y, char ** grid, int conteur);
int couler_haut(int x,int y, char ** grid, int conteur);
int couler_bas(int x,int y, char ** grid, int conteur);
int couler(int x,int y,char ** grid);

