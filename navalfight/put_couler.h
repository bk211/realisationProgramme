/**
 * \file      put_couler.h
 * \brief     Le header comportant les includes et prototype des fonctions
 *
 */


#define Dim 20
int put_couler_droite(int x,int y, char ** grid, int conteur);
int put_couler_gauche(int x,int y, char ** grid, int conteur);
int put_couler_haut(int x,int y, char ** grid, int conteur);
int put_couler_bas(int x,int y, char ** grid, int conteur);
int put_couler(int x,int y,char ** grid);
