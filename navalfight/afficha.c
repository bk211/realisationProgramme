/**
 * \file      afficha.c
 * \brief     Affiche la grille de la bataille navale.
 *
 */

#include"navalfight.h"

/**
 * \brief      Fonction qui affiche le tableau
 * \details    Affiche grille de la bataille navale
 * \param    char**         Grille de la bataille navale 
 */

void afficher(char** grille){
  int ligne, colonne;
  char lettre = 'A';
  system("clear");
  system("clear");
  for(colonne = 0 ; colonne <= 19 ; ++colonne)
    if(colonne < 10)
      printf("  %d  ",colonne);
    else
      printf(" %d  ",colonne);
  printf("\n");
  for(ligne = 0 ; ligne < Dim ; ++ligne){
    printf("--------------------------------------------------------------------------------------------------\n");
   
    for(colonne = 0 ; colonne < Dim; ++colonne)
      printf("| %c  ",grille [ligne][colonne]);
    printf("\033[0m");
    
    
    printf("|  %c   ", lettre);
    lettre++; 
    
    printf("\n");
  }
  printf("---------------------------------------------------------------------------------------------------\n");
}
