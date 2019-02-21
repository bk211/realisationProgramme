/**
 * \file      boucle.c
 * \brief     Correspond à là boucle principale du jeu.
 *
 */


#include "navalfight.h"

/**
 * \brief      Saisis les noms des joueurs
 * \details   Crée un tableau via malloc pour y saisir le nom des joueurs .
 *              
 * \return    Renvoie un char * , qui contient le nom du joueur .
 */

char * nomjoueur(){
  char *chaine, *temporaire;
  chaine = malloc(20* sizeof(char));
  temporaire = chaine;
  
  printf("Choisissez le nom du joueur :\n");
  do{
    *temporaire = getchar();
  } while(*temporaire++ != '\n');
  
  printf("Vous avez choisi %s\n", chaine);
  return chaine;
}

/**
 * \brief      Fonction qui vide un buffer
 * \details    Vide le buffer qui comporte la ligne et colonne joué pour les réutiliser
               au prochain tour de boucle.
 */
void viderbuffer(void){  
  int c = 0;
  while(c != '\n' && c != EOF){
    c = getchar();
  }
}


/**
 * \brief       Termine la partie.
 * \details    Affiche Gagné et termine le programme .
 *                  des coordonnées des points. (cf #Point)
 *
 */

void findepartie(void) {
  printf("Gagne !\n");
  exit(0);
}

/**
 * \brief      Vérifie si les bateaux sont touchés.
 * \details   Si un bateau est touché remplace le '0' par '+' et affiche Gagné sinon Raté et affiche la position par '*'.
 *            Puis appel les fonction couler et put_couler pour vérifier si le bateau est coulé.
 *            Verifie ensuite si la partie est gagné .
 * \param    **grid         La grille.
 * \param    ligne          Le nombre de ligne de la grille .
 * \param    colonne        Le nombre de colonne de la grille .
 */

void insert(char **grid, int ligne  , int colonne){
  int victoire;
  if (grid[ligne][colonne]== 'O'){
    grid[ligne][colonne]= '+';
    printf("\nTouché !\n");
    sleep(1);
    if (couler(ligne, colonne, grid) == 0) {
	  if (put_couler(ligne, colonne, grid) == 0)
		printf("\nBateau coulé !\n");
      sleep(1);
      victoire = ft_detect_defaite(grid);
    }
  }
  if(grid[ligne][colonne]== '.'){
    grid[ligne][colonne]='*';
	printf("\nRaté !\n");
    sleep(1);
  }
  if (victoire == 0) {
    findepartie();
  }
}


/**
 * \brief     Vérifie les positions attaqué
 * \details   Vérifie si les positions attaqué avec la fonction insert, selon les cas 'Raté', 'Touché' ou déjà attaqué.
 * \param    **grid         La grille.
 * \param    ligne          Le nombre de ligne de la grille .
 * \param    colonne        Le nombre de colonne de la grille .
 * \return   Renvoie un entier, 0 si Touché un bateau ou Raté, sinon 1 .
 */

int verifie (char **grid, int ligne  , int colonne){
  if(grid[ligne][colonne]== '.'){
    insert(grid, ligne, colonne);
    return 0;
  }
  if(grid[ligne][colonne]== 'O'){ 
    insert(grid, ligne, colonne);
    return 0;        
  }
  if(grid[ligne][colonne]== '*' || grid[ligne][colonne]== '+'|| grid[ligne][colonne]== 'X'){
    sleep(1);
    printf("\nImpossible de jouer, case déjà attaquée !\n");
    
    return 1;
  }
  return 1;
}

/**
 * \brief      Phase d'attaque
 * \details    Demande d'entré la ligne et colonne a laquelle le joueur souhaite attaquer.
 *             Puis appel la fonction verifie, qui s'occupe de voir s'il a touché un bateau.
 * \param    **grid  Correspond à la grille.
 * \return    Renvoie un entier qui vaut 0 si le joueur à touché un bateau ou raté, sinon 1.
 */

int attaquer(char **grid) {
  char ligne;
  int colonne;
  int conditionligne = 1;
  int conditioncolonne = 1;
  int i, j;    
  int casevalide;
  while (conditionligne == 1) {
    printf("Choississez la ligne (lettre minuscule):\n");
    scanf("%c", &ligne);
    if (ligne >= 97 && ligne <= 116) {
      ligne -= 97;
      conditionligne = 0;
    } else {
      printf("Veuillez saisir une lettre minuscule compris entre a et t\n");
    }
    viderbuffer();
  }
  conditionligne = 1;
  while (conditioncolonne == 1) {
    printf("Choississez la colonne (nombre):\n");
    scanf("%d", &colonne);
    if (colonne >= 0 && colonne <= 19) {
      conditioncolonne = 0;
    } else {
      printf("Veuillez saisir un nombre compris entre 0 et 19\n");
    }
    viderbuffer();
  }
  conditioncolonne = 1;
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
      if (i == ligne && j == colonne) {
        casevalide = verifie(grid, ligne, colonne);
	if (casevalide == 0) {
	  return 0;
	} else {
	  return 1;
	}
      }
    }
  }
  return 1;
}

/**
 * \brief      Boucle principal du jeu.
 * \details   C'est la boucle principal du jeu, qui s'occupe d'appeler les différents fonctions .
 * \param    **grid1        Grille du joueur 1.
 * \param    **grid2        Grille du joueur 2.
 */


void boucle(char **grid1, char **grid2, char ** grid3) {
  int compteurprincipale = 0, compteurjoueurun = 0, compteurjoueurdeux = 0, compteurjoueurtrois = 0;
  char *joueur1 = nomjoueur();
  char *joueur2 = nomjoueur();
  char *joueur3 = nomjoueur();
  
  while(compteurprincipale == 0) {  
    printf("\n------------------------------------------------------------------------------------------\n\n\n");
    
    while(compteurjoueurun == 0) {  
      printf("Grille de %s\nSélectionnez la ligne et la colonne à attaquer :\n", joueur1);
      afficher(grid1);
      if (attaquer(grid2) == 0) {
	compteurjoueurun = 1;
      } else {
	printf("Veuillez ressaisir les coordonnées. \n");
      }
      
    }
    compteurjoueurun = 0;
    
    printf("\n------------------------------------------------------------------------------------------\n\n\n");
    while(compteurjoueurdeux == 0) {  
      printf("Grille de %s\nSélectionnez la ligne et la colonne à attaquer :\n", joueur2);
      afficher(grid2);
      if (attaquer(grid3) == 0) {
	compteurjoueurdeux = 1;
      } else {
	printf("Veuillez ressaisir les coordonnées. \n");
      }
    }
    compteurjoueurdeux = 0;

    printf("\n------------------------------------------------------------------------------------------\n\n\n");
    while(compteurjoueurtrois == 0) {  
      printf("Grille de %s\nSélectionnez la ligne et la colonne à attaquer :\n", joueur2);
      afficher(grid3);
      if (attaquer(grid1) == 0) {
	compteurjoueurtrois = 1;
      } else {
	printf("Veuillez ressaisir les coordonnées. \n");
      }
    }
    compteurjoueurtrois = 0;


  }
  return;
}
