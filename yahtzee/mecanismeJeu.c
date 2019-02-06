#include<stdio.h>
#include<stdlib.h>
#include "mecanismeJeu.h"
#include "score.h"

int tirage(int max){
    /*tire au sort un nombre compris entre 0 inclus max; 
    srand((unsigned)time(NULL));*/
    rand();
    return (double)(rand()/(double)(RAND_MAX) * (max))+1;
}

void rollDices(Player *p){
  srand((unsigned)time(NULL));//set Seed pour le tirage
  for(int i = 0 ; i < 8; ++i){
    if (p->dicesAllowed[i]){
      p->dices[i] = tirage(8) ;
      //printf(">>>de %d tire%d\n",i,p->dices[i] );
    }
  }
}

void refreshDices(Player *p){

  for(int i = 0 ; i < 8 ; ++i){
    p->dices[i] = 0 ;
    p->dicesAllowed[i]=1;
  } 
}


int boucle_de_saisie(int a, int b){
    //retourne l'entier i ssi il est compris dans intervalle [a,b]
    int i;
    do{
        fflush(stdin);
        
        printf("merci de saisir un nombre compris entre %d et %d\n", a, b);
        scanf("%d",&i);
    }while( i <a || i>b ||sizeof(i) != sizeof(int) );
    return i;
}

void displayDices(Player *p){
  for(int i = 0 ; i < 8 ; ++i){
    printf("%d ", p->dices[i]) ;
  }
  
  printf("\n") ;
}

void askDices(Player *p){
  for (int i = 0; i <8; ++i)
  {displayDices(p);
    if(p-> dicesAllowed[i]==1){
      
      printf("voulez vous relancer le de %d ?\n",i+1 );
      p-> dicesAllowed[i]= boucle_de_saisie(0,1);
    } 
  }

}


void completeTurn(Player *p){
  int v = 1 ;
  refreshDices(p) ;
  rollDices(p) ;   

  p->nbrRollRemain -= 1 ;
  while(p->nbrRollRemain != 0){
    printf("Lance de dees :\n") ;
    displayDices(p) ;
    printf("Voulez vous relancer des dees ? ") ;
    v = boucle_de_saisie(0,1) ;
    displayDices(p);
    if(v == 0) { // cas fin de lance
      p->nbrRollRemain = 0 ; 
      displayScore(p->tabScore,p->dices);
      } 
    

    else{ //cas relance de
      if(p->nbrRollRemain !=6)printf("lequelles one ? ") ;
      askDices(p);
      p->nbrRollRemain -= 1 ;
      rollDices(p) ;
      displayDices(p);
      printf("Vous avez relancer des dees :\n") ;
      displayScore(p->tabScore,p->dices);
      printf("Essaies restante : %d\n", p->nbrRollRemain) ; 
    }
  }
  printf("Tour du prochain joueur\n") ;
}

void freePlayer(Player *p){
  free(p->dices);
  free(p->dicesAllowed);
  free(p->tabScore);
}
void initPlayer(Player *p){
  //askName();
 
 
  p->dices = malloc(sizeof(int)*8);
  p->dicesAllowed = malloc(sizeof(int)*8);
  p->nbrRollRemain = 6 ;
  p->score = 0;
  p->tabScore = malloc(sizeof(int)*6);
  for (int i = 0; i < 6; ++i)
  {
  	p->tabScore[i]= 0;
  }
}

