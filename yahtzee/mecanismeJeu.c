#include<stdio.h>
#include<stdlib.h>
#include<math.h>   //inutile en l'état
#include<stdarg.h> //inutile en l'état
#include "mecanismeJeu.h"

//TODO rendre robuste face aux saisies utilisateur

/*
typedef struct Player Player ;

struct Player {
  
  int *dices ;
  int wannaRoll[6] ;
  int nbrRollRemain ;
  int id ;
  int map[12] ; //booleen de la grille
} ;
// deplace vers mecanismeJeu.h
*/


int tirage(int max){
    /*tire au sort un nombre compris entre 0 inclus max; 
    srand((unsigned)time(NULL));*/
    rand();
    return (double)(rand()/(double)(RAND_MAX) * (max))+1;
}

void rollDices(Player *p){
  srand((unsigned)time(NULL));//set Seed pour le tirage
  for(int i = 0 ; i < 8; ++i){
    // int sub = va_arg(va, int) ;
    if (p->dicesAllowed[i]){
      p->dices[p->wannaRoll[i]] = tirage(8) ;
    }
  }
}

void beginTurn(Player *p){

  for(int i = 0 ; i < 6 ; ++i){
    p->dices[i] = 0 ;
    p->dicesAllowed[i]=1;
  }
  p->nbrRollRemain = 6 ; 
}


int boucle_de_saisie(int a, int b){
    //retourne l'entier i ssi il est compris dans intervalle [a,b]
    int i;
    do{
        fflush(stdin);
        //necessaire pour eviter un bug de boucle infinie si utilisateur saisie un type non int comme une charactere par exemple
        //meme si un char est un int...(scanf)
        printf("merci de saisir un nombre compris entre %d et %d\n", a, b);
        scanf("%d",&i);
    }while( i <a || i>b ||sizeof(i) != sizeof(int) );
    return i;
}

void displayDices(Player *p){
  for(int i = 0 ; i < 6 ; ++i){
    printf("%d ", p->dices[i]) ;
    printf("... ");
    sleep(1);
  }
  printf("\n") ;
}

void askDices(Player *p){
  for (int i = 0; i < 8; ++i)
  {
    if(p-> dicesAllowed[i]){
      printf("voulez vous gardez le de %d ?\n",i );
      p-> dicesAllowed[i]=boucle_de_saisie(0,1);
    } 
  }

}


void completeTurn(Player *p){
  int v = 1 ;
  beginTurn(p) ;
  while(p->nbrRollRemain != 0){
    if(p->nbrRollRemain !=6){
      printf("Actual outcome :\n") ;
      displayDices(p) ;
      printf("Retoss some dice ? ") ;
    }
    //scanf("%d", &v) ;
    v = boucle_de_saisie(0,1) ;
    if(v == 0) { // cas fin de lance
      p->nbrRollRemain = 0 ; 
      displayScore(p);
      } 

    else{ //cas relance de
      printf("Which one ? ") ;
      askDices(p);
      p->nbrRollRemain -= 1 ;
      rollDices(p) ;
      printf("You've toss %d dice(s) again :\nOUTCOME\n", i) ;
      displayDices(p) ;
      displayScore(p);
      printf("Remaining try : %d\n", p->nbrRollRemain) ; 
    }
  }
  printf("Next turn\n") ;
}


int main (void){
  //printf("NOTE : répondre par 1 ou 0 aux questions et pour selection des dès leurs indexs [1-7]\n\n"); 
  Player *p ;
  Player firstPlayer ;
  p = &firstPlayer ;
  //p->dices = malloc(sizeof(int) * 7) ;
  if(p->dices == NULL) printf("p == Null !\n") ; 
  completeTurn(p) ;
  
  return(0) ;
}
