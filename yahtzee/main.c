#include <stdio.h>
#include <mecanismeJeu.h>

/*
#include <comparaison.h>*/


int main(int argc, char const *argv[])
{
	Player player1;
	Player player2;

	int nombreTour=1;

	//int nombreJoueur;
	//printf("Entrez le nombre de joueur\n");
	//scanf("%d",&nombreJoueur); 
// en option, pour le moment le developpement se limite a 2 joueur
//	printf("Entrez le nombre de tour\n");
//	scanf("%d",&nombreTour); 

	while (nombreTour > 0){

		completeTurn(player1);
		completeTurn(player2);
		comparerScore(joueur1,joueur2);
		//compare le score des 2, donne le gagnant du tour
		//>> incremente score gagant

	}

//	fin des tours 
	
	compareScoreTotale(joueur1,joueur2);
	//>> felicite le gagant en affichant le score des 2


	return 0;
}