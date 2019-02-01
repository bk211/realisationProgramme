#include<stdio.h>
#include<stdlib.h>

/*

Pour la suite je n'ai pas réfléchis comment l'intégrer, mieux vaut le tester à part peut être


*/

int max(int *t, int l, int ign){ //ign est l'index de *t à ignorer si besoin ;

  int tmp = 0 ;
  int sub = 0 ;
  for(int i = 0 ; i < l ; ++i){
    if(i == ign) ++i ; 
    if(*(t+i) > tmp){ tmp = *(t+i) ; sub = i ; }  
  }
  
  return sub ;
}

void alternativeFunction(int *tab, int *score){
  char fig[7] = { 'o', 'S', 'P', 'B', 'C', 'Q', 'F' } ; //'o' = rien, S = simple, P = pair, B = brelan,... F = Full
  unsigned int scoring[7] = {0, 10, 20, 30, 40, 50, 60} ;
  unsigned int occurence[6] ;

   for(int i = 0 ; i < 7 ; ++i){
    occurence[i] = 0 ;
    for(int j = 0 ; j < 7 ; ++j){
      if(*(tab+j) == i) occurence[i]++ ;  
    }
   }
   /* for(int i = 0 ; i < 6 ; ++i){
      printf("i = %d :: %d occurence(s) de %d -> il y a %c de %d\n", i, occurence[i], i, fig[occurence[i]], tab[i]); */ //DEBEUG 
  unsigned int sub = max(occurence, 7, 8) ;
  unsigned int sub_nd = max(occurence, 7, sub) ;
  printf("sub :: %d ; sub_nd :: %d\n", sub, sub_nd) ;
  if(occurence[sub] > 1 && occurence[sub_nd] > 1){  //gestion du Full
    sub = 6 ;
    *score += scoring[sub] ;
    printf("%c ! Nouveau score : %d\n", fig[sub], *score) ;
  }
  else {
    *score += scoring[occurence[sub]] ;
    //printf("scoring[oc[sub]] :: %d ; oc[sub] :: %d\n", scoring[occurence[sub]], occurence[sub]) ; //DEBEUG
    printf("%c ! Score : %d\n", fig[occurence[sub]], *score) ; 
  }
}

int main (void){

  unsigned int tab[6] = { 1, 2, 2, 2, 2, 1 } ; //valeurs des dès au début du test
  int sc = 100 ; //score au début du test
  int *score ; 
  score = &sc ;
  
  alternativeFunction(tab, score) ;
  return(0) ;
}


