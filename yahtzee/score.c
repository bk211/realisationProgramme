/**
 * \file      score.c
 * \author    groupe3
 * \date      07 mars 2019
 * \brief     fichier qui comporte les verifications de combinaison
 *
 *                  
 */

#include "score.h"
#include <assert.h>
#include "color.c"
#define TAB_OCC 8
#define PTS 1
#define GDS 2

/**
 * \brief      Verifie si la figure Yahtzee est présente
 * \details    Si la premiere des est équivalente a la suivante,on verifie si la suivante est équivalente à la prochaine de celle ci, ainsi de suite
 *                  
 * \param    *tab               tableau content les des.
 * \return    Un entier, qui correspond au score.
 */

int testYahtzee(int *tab) {
  // verif Yahtzee
  if(tab[0] == tab[1] // on verifie que le premier dès correspond au dès suivant
     &&tab[1] == tab[2] // le deuxieme dès équivaut au troisieme ainsi de suite
     &&tab[2] == tab[3]
     &&tab[3] == tab[4]
     &&tab[4] == tab[5]
     &&tab[5] == tab[6]){
    printf("Il y a un Yahtzee de %d\n",tab[0]);
    return 50; // correspond au score du yahtzee
  }
  return 0;
}

/**
 * \brief      Verifie si la figure PetiteSuite ou GrandeSuite est présente
 * \details    On regard s'il y a la suite de dès allant de 1-7 ou 2-8 . 
 *                  
 * \param    *tab            tableau content les des.
 * \param    P_G             vaut 1 pour vérif PetiteSuite, vaut 2 pour vérif
GrandeSuite.
 * \return    Un entier, qui correspond au score.
 */
int testSuite(int *tab,int P_G){
   int i;
    // verif petite suite
   for(i=0;i<7;i++){   // on parcours le tableau de dès
     if(tab[i] == P_G)	  // on regard si dans le tableau on a '1' si P_G vaut 1 pour Petite suite ou '2' pour Grande suite
	{
	  P_G++; // Si P_G a été trouvé, on l'incrémente 
	  for(i=0;i<7;i++){
	    if(tab[i] == P_G) // Puis on vérifie si P_G une fois incrémenté est présent , ainsi de suite .
	      {
		P_G++;
		for(i=0;i<7;i++){
		  if(tab[i] == P_G)		       
		    {
		      P_G++;
		      for(i=0;i<7;i++){
			if(tab[i] == P_G)
			  {
			    P_G++;
			    for(i=0;i<7;i++){			   
			      if(tab[i] == P_G)
				{
				  P_G++;
				  for(i=0;i<7;i++){
				    if(tab[i] == P_G)
				      {
					P_G++;
					for(i=0;i<7;i++){
					  if(tab[i] == P_G)
					    {
					      if(P_G == 7){ // si P_G vaut 7 a la fin , c'est donc une ptite suite
						printf("Il y a une PetiteSuite\n");
						return 30;			     }
					      if(P_G == 8){ // sinon c'est une Grande suite
						printf("Il y a une Grande Suite\n");
						return 40;
					      }
					    }
					}
				      }
				  }
				}
			    }
			  }
		      }
		    }
		}
	      }
	  }
	}
    }
   return 0; // renvoie 0, si la combinaison n'est pas présente .
}

/**
 * \brief      Verifie si la figure Brelan ou Carré est présente
 * \details    On regard s'il y a un triplet de dès ou un quadruplet . 
 *                  
 * \param    *tab            tableau content les des.
 * \param    Trois_quatre    vaut 3 pour vérif Brelan, vaut 4 pour vérif
Carré
 * \return    Un entier, qui correspond au score.
 */

int test3_4(int *tab,int Trois_quatre) { // fonction brelan ou carré
  int tab_occurence[TAB_OCC]={0,0,0,0,0,0,0,0};
  int i;
    for (i = 0; i < 7; ++i)
    {
      ++tab_occurence[tab[i]-1]; // remplissage de la tab d'occurence si des dès sont présent en plusieurs fois .
    }

    for (i = 0; i < TAB_OCC; ++i) // parcours du tab d'occurence
      {
	if(Trois_quatre == 3 ){ // si le parametre Trois_quatre vaut 3 = verifBrelan
	  if (tab_occurence[i] == Trois_quatre)
	    {
	      printf("Il y a un Brelan de %d \n",i+1);
	      return sommeScore(tab);
	    }
	}
	if(Trois_quatre == 4){ // sinon s'il vaut 4 = VerifCarré
	  if (tab_occurence[i] == Trois_quatre)
	    {
	      printf("Il y a un Carre de %d \n",i+1);
	      return sommeScore(tab);
	    }
	}
      }
    
    return 0;
}   


/**
 * \brief      Verifie si la figure Full est présente 
 * \details    On parcours le tableau d'occurence à la recherche de case contenant soit 5 et 2 ou 4 et 3 .
 *                  
 * \param    *tab            tableau content les des.
 * \param    *fullv1         Vaut 5 pour full type1, ou 4 pour full type2
 * \param    *fullv2         Vaut 2 pour full type1, ou 3 pour full type2
 * \return    Un entier, qui correspond au score.
 */

int testFull(int *tab,int fullv1,int fullv2){ // fullv1 = premiere partie du full et fullv2 seconde partie du full

  int tab_occurence[TAB_OCC]={0,0,0,0,0,0,0,0};
  int i,j;
  int full1,full2;
  
  for (i = 0; i < 7; ++i) 
    {
      ++tab_occurence[tab[i]-1]; // Remplissage du tab d'occurence, si des dès sont présent plusieurs .
    }
    
    for(i=0;i<8;i++)
      {
	if(tab_occurence[i]==fullv1) // on regard si dans le tab d'occurence, il y a un élément qui vaut fullv1 ( qui vaut 5 ou 2 )
	  {
	    full1=i+1; //+1 pour passer de l'indice de la case à sa valeur
	    for(j=0;j<8;j++)
	      {
		if(tab_occurence[j]==fullv2) // et s'il y a un élément qui vaut fullv2 ( qui vaut 2 ou 3 )
		  {
		    full2=j+1; //+1 pour passer de l'indice de la case à sa valeur
		    printf("Il y a un Full de %d et %d\n",full1,full2);
		    return 25;  // le score
		 
		   
		  }
	      }
	  }
      }
    
    return 0;
}



/**
 * \brief      Appel a tout les fonctions de verification de figure
 * \details    Appel tout les fonctions de verification de figure et remplissage
 * \du tableau de score
 *                  
 * \param    *tab_score        tableau contenant les scores
 * \param    *tab_dee         tableau contenant les des
 */

void testCombinatoire(int *tab_score, int *tab_dee){
	/*test et remplit le tableau des score*/
	int i;
	for (i = 0; i < 7; ++i)
    {
    	tab_score[tab_dee[i]-1] += tab_dee[i] ;
    }
	// appel de tout les fonctions de test combinaison et enregistre score dans tab_score
	tab_score[8] = test3_4(tab_dee,3);
	tab_score[9] = testSuite(tab_dee,PTS);
	tab_score[10] = testSuite(tab_dee,GDS);
	tab_score[11] = test3_4(tab_dee,4);
	tab_score[12] = testFull(tab_dee,5,2);
	tab_score[13] = testFull(tab_dee,4,3);
	tab_score[14] = testYahtzee(tab_dee);
}




/**
 * \brief      Affiche les scores
 * \details    Appel la fonction TestCombinatoire qui s'occupe de remplir le tableau des score, puis affiche les scores
 *                  
 * \param    *tab_score        tableau contenant les scores
 * \param    *tab_dee              tableau contenant les des
 
 */

void displayScore(int* tab_score,int *tab_dee,int * tabFinal){
	testCombinatoire(tab_score,tab_dee);
	
	displayTabScore(tab_score, tabFinal);

	//affiche le score

}


/**
 * \brief      Fonction qui décide qui l'emporte
 * \details    Compare le score des deux joueurs et affiche le gagnant ou match nul
 *                  
 * \param    a        score du joueur 1
 * \param    b        score du joueur 2
 
 */

void compareScore(int a, int b){
	if(a > b){
		printf("Bravo! le joueur 1 remporte la partie\n");
	}
	else if (b > a){
		printf("Bravo! le joueur 2 remporte la partie\n");
	}
	else{
		printf("Match nul\n");	
	}	
}

/**
 * \brief      Fonction qui fais la somme
 * \details    Fais la somme de tout les dès.
 *                  
 * \param   *tab      tableau des dès
 * \return    Un entier, qui correspond au score.
 */

int sommeScore(int * tab){
	int somme = 0;
	for (int i = 0; i < 7; ++i)
	{
	  somme += tab[i]; // fais la somme de toute les cases
	}
	return somme;
}

/**
 * \brief      Fonction qui affiche les scores.
 * \details    Affiche les scores des joueurs.
 *                  
 * \param   *tab_score      tableau des score
 * \param   *tabFinal       le tableau final
 */

void displayTabScore(int *tab_score, int* tabFinal){
	printf("========================================================\n" );
	(tabFinal[0] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 1 >>", "AS", tab_score[0]);
	(tabFinal[1] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 2 >>", "DEUX", tab_score[1]);
	(tabFinal[2] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 3 >>", "TROIS", tab_score[2]);
	(tabFinal[3] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 4 >>", "QUATRE", tab_score[3]);
	(tabFinal[4] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 5 >>", "CINQ", tab_score[4]);
	(tabFinal[5] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 6 >>", "SIX", tab_score[5]);
	(tabFinal[6] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 7 >>", "SEPT", tab_score[6]);
	(tabFinal[7] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 8 >>", "HUIT", tab_score[7]);
	(tabFinal[8] == -1)? green(): red();
	printf("%-4s %-12s: %d\n"," 9 >>", "BRELAN", tab_score[8]);
	(tabFinal[9] == -1)? green(): red();
	printf("%-4s %-12s: %d\n","10 >>", "SUITE(1-6)", tab_score[9]);
	(tabFinal[10] == -1)? green(): red();
	printf("%-4s %-12s: %d\n","11 >>", "SUITE(2-7)", tab_score[10]);
	(tabFinal[11] == -1)? green(): red();
	printf("%-4s %-12s: %d\n","12 >>", "CARRE", tab_score[11]);
	(tabFinal[12] == -1)? green(): red();
	printf("%-4s %-12s: %d\n","13 >>", "FULL(2+5)", tab_score[12]);
	(tabFinal[13] == -1)? green(): red();
	printf("%-4s %-12s: %d\n","14 >>", "FULL(3+4)", tab_score[13]);
	(tabFinal[14] == -1)? green(): red();
	printf("%-4s %-12s: %d\n","15 >>", "YAHTZEE", tab_score[14]);
	
	resetColor();
	printf("========================================================\n" );


}

/**
 * \brief      Fonction qui fais la saisit du score
 * \details    L'utilisateur saisit son score dans tabFinal
 *                  
 * \param   *tab           tableau des dès
* \param    *tabFinal      tableau final contenant les scores
 */


int saisitScore(int *tab,int *tabFinal){
	int answer=0;
	while(1){
		printf("Saisissez le numero de la case que vous voulez remplir  \n");
		boucle_de_saisie(&answer,1,15);
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



/**
 * \brief      controle de saisie de clavier.
 * \details    l'entier p est affecte de la valeur saisit s'il est compris dans intervalle [a,b] et la fct retourne 1
 * \param    a    la valeur 0 
 * \param    a    la valeur 1
 * \return    Un int.
 */

int boucle_de_saisie( int * p, int low, int high ) {
    while(1) {
        const int BUFSIZE = 256;
        char buf[BUFSIZE];
        printf("merci de saisir un nombre compris entre %d et %d\n", low, high);

        if ( fgets( buf, BUFSIZE, stdin ) == NULL ) {
            return 0;      // almost certainly EOF
        }
        if ( sscanf( buf, "%d", p ) != 1 ) {
            printf( "Merci de saisir un entier\n" );
        }
        else if ( * p < low || * p > high )  {
        	printf("valeur saisie hors borne\n");
        }
        else {
            break;
        }
    }
    return 1;
}
