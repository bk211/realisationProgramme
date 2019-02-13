#include <stdio.h>
#include <stdlib.h>

int testYahtzee(int *tab) ;
int testPetiteSuite(int *tab) ;
int testGrandeSuite(int *tab) ;
int testBrelan(int *tab) ;
int testCarre(int *tab);
int testFullv1(int *tab);
int testFullv2(int *tab);
void testCombinatoire(int *tab_score, int *tab_dee);
void displayScore(int* tab_score,int *tab_dee,int * tabFinal);
void compareScore(int a, int b);
int sommeScore(int * tab);
int saisitScore(int *tab,int *tabFinal);
void displayTabScore(int *tab_score, int* tabFinal);	
int boucle_de_saisie( int * p, int low, int high );

