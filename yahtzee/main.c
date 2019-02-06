#include <stdio.h>
#include "mecanismeJeu.h"
#include "score.h"

int main(int argc, char const *argv[])
{
	Player player1;
	Player player2;
	initPlayer(&player1);
  	initPlayer(&player2);
  
	int nombreTour=1;

	//int nombreJoueur;
	//printf("Entrez le nombre de joueur\n");
	//scanf("%d",&nombreJoueur); 
// en option, pour le moment le developpement se limite a 2 joueur
//	printf("Entrez le nombre de tour\n");
//	scanf("%d",&nombreTour); 

	while (nombreTour > 0){
		printf("=============== C'est au Joueur 1 de jouer ===============!\n");
		completeTurn(&player1);
		printf("=============== C'est au Joueur 2 de jouer ===============!\n");
		completeTurn(&player2);

//		comparerScore(joueur1,joueur2);
		//compare le score des 2, donne le gagnant du tour
		//>> incremente score gagant
		--nombreTour;
	}

//	fin des tours 
	//>> felicite le gagant en affichant le score des 2
	compareScore(player1.tabScore[6],player2.tabScore[6]);
	freePlayer(&player1);
	//freePlayer(&player2);
	printf("here\n");
	return 0;
}