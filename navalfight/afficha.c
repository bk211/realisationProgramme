#include"navalfight.h"
void afficher(char** grille){
  int ligne, colonne;
  char lettre = 'A';
  
  for(colonne = 0 ; colonne <= 16 ; ++colonne)
    if(colonne < 10)
      printf("  %d  ",colonne);
    else
      printf(" %d  ",colonne);
  printf("\n");
  for(ligne = 0 ; ligne < 17 ; ++ligne){
    printf("-------------------------------------------------------------------------------------\n");
   
    for(colonne = 0 ; colonne < 17 ; ++colonne)
      printf("| %c  ",grille [ligne][colonne]);
    printf("\033[0m");
    
    
    printf("|  %c   ", lettre);
    lettre++; 
    
    printf("\n");
  }
  printf("-------------------------------------------------------------------------------------\n");
}
