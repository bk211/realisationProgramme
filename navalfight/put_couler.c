/**
 * \file      put_couler.c
 * \brief     Se charge d'appliquer quand un bateau est coulé.
 *
 */

#include"put_couler.h"

/**
 * \brief     Applique si coulé coté droit .
 * \details   Si le bateau est entierement coulé transforme '+' par 'X' .

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \param    conteur   Zone dans laquel on vérifie s'il y a un bateau.
 * \return   Renvoie 0 si le bateau n'est pas entierement coulé .
             Renvoie un entier supérieur à 0 sinon .
 */

int put_couler_droite(int x,int y, char ** grid, int conteur){
	int resultat = 0;
	conteur++;
	if (grid[x][y] == '+')
		grid[x][y] = 'X';
	if (conteur > 30)
		return 0;
	if (grid[x][y] == '.' || grid[x][y] == '*')
		return 0;
	if(x + 1 < Dim)
		resultat += put_couler_droite(x + 1, y, grid, conteur);
	if (y + 1 < Dim)
		resultat += put_couler_bas(x, y + 1, grid, conteur);
	if (y - 1 > -1)
		resultat += put_couler_haut(x, y - 1, grid, conteur);
	return (resultat);
}

/**
 * \brief     Applique si coulé coté gauche .
 * \details   Si le bateau est entierement coulé transforme '+' par 'X' .

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \param    conteur   Zone dans laquel on vérifie s'il y a un bateau.
 * \return   Renvoie 0 si le bateau n'est pas entierement coulé .
             Renvoie un entier supérieur à 0 sinon .
 */

int put_couler_gauche(int x,int y, char ** grid, int conteur){
	int resultat = 0;
	conteur++;
	if (grid[x][y] == '+')
		grid[x][y] = 'X';
	if (conteur > 30)
		return 0;
	if (grid[x][y] == '.' || grid[x][y] == '*')
		return 0;
	if (x - 1 > -1)
		resultat += put_couler_gauche(x - 1, y, grid, conteur);
	if (y + 1 < Dim)
		resultat += put_couler_bas(x, y + 1, grid, conteur);
	if (y - 1 > -1)
		resultat += put_couler_haut(x, y - 1, grid, conteur);
	return (resultat);
}


/**
 * \brief     Applique si coulé coté haut .
 * \details   Si le bateau est entierement coulé transforme '+' par 'X' .

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \param    conteur   Zone dans laquel on vérifie s'il y a un bateau.
 * \return   Renvoie 0 si le bateau n'est pas entierement coulé .
             Renvoie un entier supérieur à 0 sinon .
 */


int put_couler_haut(int x,int y, char ** grid, int conteur){
	int resultat = 0;
	conteur++;
	if (grid[x][y] == '+')
		grid[x][y] = 'X';
	if (conteur > 30)
		return 0;
	if (grid[x][y] == '.' || grid[x][y] == '*')
		return 0;
	if (y - 1 > -1)
		resultat += put_couler_haut(x, y - 1, grid, conteur);
	if (x + 1 < Dim)
		resultat += put_couler_droite(x + 1, y, grid, conteur);
	if (x - 1 > -1)
		resultat += put_couler_gauche(x - 1, y, grid, conteur);
	return(resultat);
}

/**
 * \brief     Applique si coulé coté bas .
 * \details   Si le bateau est entierement coulé transforme '+' par 'X' .

 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 * \param    conteur   Zone dans laquel on vérifie s'il y a un bateau.
 * \return   Renvoie 0 si le bateau n'est pas entierement coulé .
             Renvoie un entier supérieur à 0 sinon .
 */


int put_couler_bas(int x,int y, char ** grid, int conteur){
	int resultat = 0;
	conteur++;
	if (grid[x][y] == '+')
		grid[x][y] = 'X';
	if (conteur > 30)
		return 0;
	if (grid[x][y] == '.' || grid[x][y] == '*')
		return 0;
	if (y + 1 < Dim)
		resultat += put_couler_bas(x, y + 1, grid, conteur);
	if (x + 1 < Dim)
		resultat += put_couler_droite(x + 1, y, grid, conteur);
	if (x - 1 > -1)
		resultat += put_couler_gauche(x - 1, y, grid, conteur);
	return(resultat);
}


/**
 * \brief     Appel toute les fonctions put_couler .
 * \details   Toute les fonctions put_couler sont appelé pour transformer tout les '+' en 'X'
              pour signaler que ce bateau est coulé .
 * \param    x         Premiere coordonée
 * \param    y         Seconde coordonée.
 * \param    **grid    La grille de la bataille navale.
 
 * \return   Renvoie 0 si le bateau n'est pas entierement coulé .
             Renvoie un entier supérieur à 0 sinon .
 */


int put_couler(int x,int y,char ** grid){
	int resultat = 0;
	if (grid[x][y] == '+')
		grid[x][y] = 'X';
	if (x + 1 < Dim)
		resultat += put_couler_droite(x + 1, y, grid, 0);
	if (x - 1 > -1)
		resultat += put_couler_gauche(x - 1, y, grid, 0);
	if (y + 1 < Dim)
		resultat += put_couler_bas(x, y + 1, grid, 0);
	if (y - 1 > -1)
		resultat += put_couler_haut(x, y - 1, grid, 0);
	return (resultat);
}
