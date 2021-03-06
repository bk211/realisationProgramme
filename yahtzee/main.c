/**
 * \file       main.c
 * \author    groupe3
 * \version   1.0
 * \date       07 fevrier 2019
 * \brief       Boucle main qui lance le jeu
 *
 *                  
 */
#include "mecanismeJeu.h"
#include <assert.h>
#define MAX_PLAYER 2

int main()
{
	
	Player *player1;
	player1 = malloc(sizeof (Player));
	player1->dices = malloc(sizeof(int)*7);
	player1->dicesAllowed = malloc(sizeof(int)*7);
	player1->nbrRollRemain = 6 ;
	player1->tabScore = malloc(sizeof(int)* MAX_COMBINATOIRE);
	player1->tabScoreFinal = malloc(sizeof(int)* MAX_COMBINATOIRE);
  	assert(player1->dices);
  	assert(player1->dicesAllowed);
  	assert(player1->tabScore);
  	assert(player1->tabScoreFinal);

	Player *player2;
	player2 = malloc(sizeof (Player));
	player2->dices = malloc(sizeof(int)*7);
	player2->dicesAllowed = malloc(sizeof(int)*7);
	player2->nbrRollRemain = 6 ;
	player2->tabScore = malloc(sizeof(int*)* MAX_COMBINATOIRE);
	player2->tabScoreFinal = malloc(sizeof(int*)* MAX_COMBINATOIRE);
  	assert(player2->dices);
  	assert(player2->dicesAllowed);
  	assert(player2->tabScore);
  	assert(player2->tabScoreFinal);
  		
  	for (int i = 0; i < MAX_COMBINATOIRE; ++i)
  	{
  		player1->tabScore[i]= 0;
   		player1->tabScoreFinal[i]=-1;
  		player2->tabScore[i]= 0;
   		player2->tabScoreFinal[i]=-1;
	}
	
	int nombreTour=12;



	while (nombreTour > 0){
		printf("=============== C'est au Joueur %d de jouer ===============!\n", 1);
		completeTurn(player1);
		printf("\n\n");
		printf("=============== C'est au Joueur %d de jouer ===============!\n", 2);
		
		completeTurn(player2);
		
		--nombreTour;
	}
	compareScore(player1->scoreFinal,player2->scoreFinal);

//	fin des tours 
	//>> felicite le gagant en affichant son score;
	
	freePlayer(player1);
	freePlayer(player2);

	return 0;
}
