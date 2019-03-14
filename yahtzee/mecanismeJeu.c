/**
 * \file         mecanismeJeu.c
 * \author    groupe3
 * \version   1.0
 * \date       07 fevrier 2019
 * \brief       Gére le mecanisme de jeu.
 *
 *                  
 */
#include "mecanismeJeu.h"
#include <assert.h>
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
  for(int i = 0 ; i < 7; ++i){
    if (p->dicesAllowed[i]){
      p->dices[i] = tirage(8) ;
      //printf(">>>de %d tire%d\n",i,p->dices[i] );
    }
  }
  p->nbrRollRemain-=1;
}
/**
 *\fn void refreshDices(Player *p)
 * \brief      initialise les dées 
 * \details    initialize toute les dées a 0.
 * \param    p       le joueur.
 */
void refreshDices(Player *p){

  for(int i = 0 ; i < 7 ; ++i){
    p->dices[i] = 0 ;
    p->dicesAllowed[i]=1;
  } 
}

/**
 *\fn void displayDices(Player *p)
 * \brief      affichage des dées.
 * \details   afficher tout les dées.
 * \param    p le joueur.
 */
void displayDices(Player *p){
  for(int i = 0 ; i < 7 ; ++i){
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
  for (int i = 0; i <7; ++i)
  {displayDices(p);
    if(p-> dicesAllowed[i]==1){
      
      printf("voulez vous relancer le de %d ?\n",p->dices[i] );
      boucle_de_saisie(&(p->dicesAllowed[i]),0,1);
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
  refreshDices(p) ;
  int answer=1;
  do{
    printf("Lance de dees :\n") ;
    rollDices(p) ;   
    displayDices(p) ;
    printf("Essaies restante : %d\n", p->nbrRollRemain) ; 
    printf("Score temporaire :\n");
    displayScore(p->tabScore, p->dices,p->tabScoreFinal);

    if(p->nbrRollRemain>0){

        printf("Voulez vous relancer des dees ? ") ;
        boucle_de_saisie(&answer,0,1) ;
        if(!answer){
            p->nbrRollRemain =0;
        }
        else{
            askDices(p);
        }
    }
  }while(p->nbrRollRemain >= 0);

  	saisitScore(p->tabScore,p->tabScoreFinal);
	for (int i = 0; i < 20; ++i)
	{
		printf("%d\n", p->tabScoreFinal[i] );
	}

  displayTabScore(p->tabScore,p->tabScoreFinal);//affiche son score final
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
  		free(p->tabScoreFinal);
}

/**
 *\fn void initPlayer(Player *p)
 * \brief      alloue la memoire.
 * \details    alloue la memoire pour le joueur p .
 * \param    p le joueur.
 */
void initPlayer(Player *p){

  p = malloc(sizeof (Player*));
  p->dices = malloc(sizeof(int)*7);
  p->dicesAllowed = malloc(sizeof(int)*7);
  p->nbrRollRemain = 6 ;
  p->tabScore = malloc(sizeof(int*)* MAX_COMBINATOIRE);
  p->tabScoreFinal = malloc(sizeof(int*)* MAX_COMBINATOIRE);
  assert(p->dices);
  assert(p->dicesAllowed);
  assert(p->tabScore);
  assert(p->tabScoreFinal);
      
  for (int i = 0; i < MAX_COMBINATOIRE; ++i)
  {
      p->tabScore[i]= 0;
      p->tabScoreFinal[i]=-1;
  }
  
}

