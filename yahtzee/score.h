#include <stdio.h>
#include <stdlib.h>

int testYahtzee(int *tab) ;
int testSuite(int *tab,int P_G);
int test3_4(int *tab,int Trois_quatre) ;
int testFull(int *tab,int fullv1,int fullv2);
void testCombinatoire(int *tab_score, int *tab_dee);
void displayScore(int* tab_score,int *tab_dee,int * tabFinal);
void compareScore(int a, int b);
int sommeScore(int * tab);
int saisitScore(int *tab,int *tabFinal);
void displayTabScore(int *tab_score, int* tabFinal);	
int boucle_de_saisie( int * p, int low, int high );

