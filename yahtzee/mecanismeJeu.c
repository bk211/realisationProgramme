/**
 * \file         mecanismedJeu.c
 * \author    groupe3
 * \version   1.0
 * \date       07 fevrier 2019
 * \brief       Gére le mecanisme de jeu.
 *
 *                  
 */
#include<stdio.h>
#include<stdlib.h>
#include "mecanismeJeu.h"
#include "score.h"
/**
 *\fn int tirage(int max)
 * \brief      donne la valeur de dée
 * \details                
 * \param    max         le maximum
 * \return    Un int représentant la valeur de dée.
 */
int tirage(int max){
    /*tire au sort un nombre compris entre 0 inclus max; 
    srand((unsigned)time(NULL));*/
    rand();
    return (double)(rand()/(double)(RAND_MAX) * (max))+1;
}
/**
 *\fn void rollDices(Player *p)
 * \brief       la coup de jeu
 * \details      fait le coup de 7 deés
 *      
 * \param    p        le joueur
 **/
void rollDices(Player *p){
  srand((unsigned)time(NULL));//set Seed pour le tirage
  for(int i = 0 ; i < 8; ++i){
    if (p->dicesAllowed[i]){
      p->dices[i] = tirage(8) ;
      //printf(">>>de %d tire%d\n",i,p->dices[i] );
    }
  }
}
/**
 *\fn void refreshDices(Player *p)
 * \brief      initialise les dées 
 * \details    initialize toute les dées a 0.
 * \param    p       le joueur.
 */
void refreshDices(Player *p){

  for(int i = 0 ; i < 8 ; ++i){
    p->dices[i] = 0 ;
    p->dicesAllowed[i]=1;
  } 
}

/**
 *\fn int boucle_de_saisie(int a, int b)
 * \brief      controle de saisie de clavier.
 * \details    retourne l'entier i ssi il est compris dans intervalle [a,b].
 * \param    a    la valeur 0 
 * \param    a    la valeur 1
 * \return    Un int.
 */
int boucle_de_saisie(int a, int b){
    //
    int i;
    do{
        fflush(stdin);
        
        printf("merci de saisir un nombre compris entre %d et %d\n", a, b);
        scanf("%d",&i);
    }while( i <a || i>b ||sizeof(i) != sizeof(int) );
    return i;
}

/**
 *\fn void displayDices(Player *p)
 * \brief      affichage des dées.
 * \details   afficher tout les dées.
 * \param    p le joueur.
 */
void displayDices(Player *p){
  for(int i = 0 ; i < 8 ; ++i){
    printf("%d ", p->dices[i]) ;
  }
  
  printf("\n") ;
}

/**
 *\fn void askDices(Player *p)
 * \brief      relance les dées 
 * \details    demande au joueur s'il veurt relancer le dée.
 * \param    p le joueur.
 */
void askDices(Player *p){
  for (int i = 0; i <8; ++i)
  {displayDices(p);
    if(p-> dicesAllowed[i]==1){
      
      printf("voulez vous relancer le de %d ?\n",p->dices[i] );
      p-> dicesAllowed[i]= boucle_de_saisie(0,1);
    } 
  }

}

/**
 *\fn void completeTurn(Player *p)
 * \brief      lance une partie de jeu.
 * \details    fait une partie de jeu .
 * \param    p le joueur.
 */
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

    if(v == 0) { // cas fin de lance
      p->nbrRollRemain = 0 ; 
      displayScore(p->tabScore,p->dices);
      } 
    

    else{ //cas relance de
      if(p->nbrRollRemain !=6)printf("lequelles one ? ") ;
      askDices(p);
      p->nbrRollRemain -= 1 ;
      rollDices(p) ;
      
      printf("Vous avez relancer des dees :\n") ;
      displayScore(p->tabScore,p->dices);
      printf("Essaies restante : %d\n", p->nbrRollRemain) ; 
    }
  }
  printf("Tour du prochain joueur\n") ;
}

/**
 *\fn void freePlayer(Player *p)
 * \brief      libére la memoire.
 * \details    libere la memoire allouer pour les joueurs .
 * \param    p le joueur.
 */
void freePlayer(Player *p){
  free(p->dices);
  free(p->dicesAllowed);
  free(p->tabScore);
}
/**
 *\fn void initPlayer(Player *p)
 * \brief      initialise les joueurs .
 * \details    initialise la memoire allouer pour les joueurs .
 * \param    p le joueur.
 */
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

