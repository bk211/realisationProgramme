#include"score.h"
#include<stdio.h>
#include<assert.h>
#include"score.c"



int TESTsaisitScore(int *tab,int *tabFinal){
  int answer=0;
  while(1){
    printf("Saisissez le numero de la case que vous voulez remplir  \n");
    //boucle_de_saisie(&answer,1,15); // ligne originale
    answer = 1;//modifier ici 
    /*
    le test saisit double est valide car s'il la case est deja remplit, on revient au debut de la boucle
      while, la saisit est redemande a utilisateur
    */
    
    --answer;
    if(tabFinal[answer] >= 0){
      printf("La case est deja remplit, merci de choisir une autre\n");
    }
    else{
      tabFinal[answer] = tab[answer];
      return 1;
    }

  }
}

int main() {
  int test_yaht[8]={1,1,1,1,1,1,1};
  int test_PS[8]={7,3,2,6,5,4,1};
  int test_GS[8]={8,5,7,3,2,4,6};
  int test_brelan[8]={4,6,4,8,4,3,7};
  int test_carre[8]={5,6,5,7,5,5,1};
  int test_fullv1[8]={8,8,8,3,8,3,8};
  int test_fullv2[8]={3,2,3,3,2,3,2};

  int test_yaht_false[8]={1,5,1,1,1,1,1};
  int test_PS_false[8]={7,3,2,8,5,4,1};
  int test_GS_false[8]={8,5,1,3,2,4,6};
  int test_brelan_false[8]={4,6,3,8,4,3,7};
  int test_carre_false[8]={5,6,5,7,7,5,1};
  int test_fullv1_false[8]={8,8,7,3,8,3,8};
  int test_fullv2_false[8]={3,2,3,5,2,3,2};

  int tab_partie[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int tab_partie_final[]= {-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  assert(TESTsaisitScore(tab_partie, tab_partie_final));
  // les assert pour cas OK
  assert(testYahtzee(test_yaht) == 50);

  assert(testSuite(test_PS,1) == 30);

  assert(testSuite(test_GS,2) == 40);

  assert(test3_4(test_brelan,3) == 36);

  assert(test3_4(test_carre,4) == 34);

  assert(testFull(test_fullv1,5,2) == 25);

  assert(testFull(test_fullv2,4,3) == 25);

  // les assert pour cas NON OK
  assert(testYahtzee(test_yaht_false) == 0);

  assert(testSuite(test_PS_false,1) == 0);

  assert(testSuite(test_GS_false,2) == 0);

  assert(test3_4(test_brelan_false,3) == 0);

  assert(test3_4(test_carre_false,4) == 0);

  assert(testFull(test_fullv1_false,5,2) == 0);

  assert(testFull(test_fullv2_false,4,3) == 0);
  
  
}
