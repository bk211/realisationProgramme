/**
 * \file      defaite.c
 * \brief     Vérifie si le joueur à perdu.
 *
 */

#include "defaite.h"
/**
 * \brief       Test s'il reste au moin un bateau non coulé
 * \details    Parcours la grille et vérifie s'il reste au moin un 'O' , c'est a dire au moin un bateau non coulé, sinon tout les bateaux sont coulés
 *                
 * \param    **grid         La grille est passé en paramètre .
 * \return    Renvoie un entier 1 si il reste au moin un bateau, 0 si tout les bateaux sont coulés.
 */

int ft_detect_defaite(char **grid){
  int conteur_col;
  int conteur_line;
  for (conteur_line = 0; conteur_line < 18; conteur_line++){
    for (conteur_col = 0; conteur_col < 18; conteur_col++)
      if (grid[conteur_line][conteur_col] == 'O')
	return (1);
  }
  return 0;
}
