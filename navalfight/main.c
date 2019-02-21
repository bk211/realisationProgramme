/**
 * \file      main.c
 * \brief     Le main du programme.
 *
 */

#include "navalfight.h"
/**
 * \brief      Le main du programme
 * \details    Créer les grilles et appel la boucle princpale
 *              
 * \return   Renvoie 0, si tout ce passe bien.
 */

int main() {
	srand(time(NULL));
	char ** grid1 = cree_tableau();
	char ** grid2 = cree_tableau();
	char ** grid3 = cree_tableau();
	boucle(grid1, grid2);
	return 0;
}
