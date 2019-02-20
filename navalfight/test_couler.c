/**
 * \file      test_couler.c
 * \brief     Verifie si les bateaux sont coulés.
 *
 */

#include"navalfight.h"

/**
 * \brief     Verifie s'il y a un bateau coulé coté droit
 * \details   Si la position x,y est touché, verifie si sa droite,bas,haut sont coulé aussi.

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \param    conteur   Zone dans laquel on vérifie s'il y a un bateau.
 * \return   Renvoie un entier qui vaut 1 s'il y a un bateau en position x,y.
             Renvoie 0 si la grille est vide ou deja attaqué .
	     Renvoie un entier supérieur à 1 si plus de 2 zone touché.
 */

int couler_droite(int x,int y, char ** grid, int conteur){
	int resultat = 0;
	conteur++;
	if (conteur > 10)
		return 0;
	if (grid[x][y] == 'O')
		return 1;
	if (grid[x][y] == '.' || grid[x][y] == '*')
		return 0;
	if(x + 1 < 20)
		resultat += couler_droite(x + 1, y, grid, conteur);
	if (y + 1 < 20)
		resultat += couler_bas(x, y + 1, grid, conteur);
	if (y - 1 > -1)
		resultat += couler_haut(x, y - 1, grid, conteur);
	return (resultat);
}


/**
 * \brief     Verifie s'il y a un bateau coulé coté gauche .
 * \details   Si la position x,y est touché, verifie si sa gauche,bas,haut sont coulé aussi.

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \param    conteur   Zone dans laquel on vérifie s'il y a un bateau.
 * \return   Renvoie un entier qui vaut 1 s'il y a un bateau en position x,y.
             Renvoie 0 si la grille est vide ou deja attaqué .
	     Renvoie un entier supérieur à 1 si plus de 2 zone touché.
 */

int couler_gauche(int x,int y, char ** grid, int conteur){
	int resultat = 0;
	conteur++;
	if (conteur > 10)
		return 0;
	if (grid[x][y] == 'O')
		return 1;
	if (grid[x][y] == '.' || grid[x][y] == '*')
		return 0;
	if (x - 1 > -1)
		resultat += couler_gauche(x - 1, y, grid, conteur);
	if (y + 1 < 20)
		resultat += couler_bas(x, y + 1, grid, conteur);
	if (y - 1 > -1)
		resultat += couler_haut(x, y - 1, grid, conteur);
	return (resultat);
}


/**
 * \brief     Verifie s'il y a un bateau coulé coté haut .
 * \details   Si la position x,y est touché, verifie si sa gauche,droite,haut sont coulé aussi.

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \param    conteur   Zone dans laquel on vérifie s'il y a un bateau.
 * \return   Renvoie un entier qui vaut 1 s'il y a un bateau en position x,y.
             Renvoie 0 si la grille est vide ou deja attaqué .
	     Renvoie un entier supérieur à 1 si plus de 2 zone touché.
 */

int couler_haut(int x,int y, char ** grid, int conteur){
	int resultat = 0;
	conteur++;
	if (conteur > 10)
		return 0;
	if (grid[x][y] == 'O')
		return 1;
	if (grid[x][y] == '.' || grid[x][y] == '*')
		return 0;
	if (y - 1 > -1)
		resultat += couler_haut(x, y - 1, grid, conteur);
	if (x + 1 < 20)
		resultat += couler_droite(x + 1, y, grid, conteur);
	if (x - 1 > -1)
		resultat += couler_gauche(x - 1, y, grid, conteur);
	return(resultat);
}

/**
 * \brief     Verifie s'il y a un bateau coulé coté bas .
 * \details   Si la position x,y est touché, verifie si sa gauche,droite,bas sont coulé aussi.

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \param    conteur   Zone dans laquel on vérifie s'il y a un bateau.
 * \return   Renvoie un entier qui vaut 1 s'il y a un bateau en position x,y.
             Renvoie 0 si la grille est vide ou deja attaqué .
	     Renvoie un entier supérieur à 1 si plus de 2 zone touché.
 */

int couler_bas(int x,int y, char ** grid, int conteur){
	int resultat = 0;
	conteur++;
	if (conteur > 10)
		return 0;
	if (grid[x][y] == 'O')
		return 1;
	if (grid[x][y] == '.' || grid[x][y] == '*')
		return 0;
	if (y + 1 < 20)
		resultat += couler_bas(x, y + 1, grid, conteur);
	if (x + 1 < 20)
		resultat += couler_droite(x + 1, y, grid, conteur);
	if (x - 1 > -1)
		resultat += couler_gauche(x - 1, y, grid, conteur);
	return(resultat);
}


/**
 * \brief     Appel de toute les fonctions coulées .
 * \details   Appel toute les fonctions coulées pour vérifier s'il y a un bateau entierement coulé .

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \return   Renvoie un entier supérieur à 0 si le bateau est coulé .
 */

int couler(int x,int y,char ** grid){
	int resultat = 0;
	if (x + 1 < 20)
		resultat += couler_droite(x + 1, y, grid, 0);
	if (x - 1 > -1)
		resultat += couler_gauche(x - 1, y, grid, 0);
	if (y + 1 < 20)
		resultat += couler_bas(x, y + 1, grid, 0);
	if (y - 1 > -1)
		resultat += couler_haut(x, y - 1, grid, 0);
	return (resultat);
}
