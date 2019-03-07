/**
 * \file      create_grid.c
 * \brief     Crée la grille de la bataille navale.
 *
 */


#include "create_grid.h"

/**
 * \brief      Vérifie si on reste bien dans la grille.
 * \details    Vérifie que le nombre de colonne et ligne est bien inférieurs aux limites.
 * \param    indice_col     Le nombre de colonne.
 * \param    indice_line    Le nombre de ligne .
 * \return   Renvoie un entier 0 si tout ce passe bien, sinon 1.
 */

int ft_test_born(int indice_col,int indice_line){
	if (indice_col > Dim-1)  
		return 1;
	if (indice_col < 0)
		return 1;
	if (indice_line > Dim-1)
		return 1;
	if (indice_line < 0)
		return 1;
	return 0;
}

/**
 * \brief     Test s'il y a un bateau
 * \details   Verifie s'il y a bateau aux coordonées passé
 * \param     **grid      La grille de la bataille navale.
 * \param     indice_col    Première coordonée.
 * \param     indice_line   Seconde coordonée.
 * \return    Renvoie un entier 1 s'il y a un bateau, sinon 0.
 */


int ft_test_boat(char **grid, int indice_col, int indice_line){
	if (grid[indice_line][indice_col] == 'O')
		return 1;
	return 0;
}


/**
 * \brief     Place les obstacles
 * \details   Verifie s'il y a bateau aux coordonées aléatoirement tirés ou si l'on sort de la grille, si non on place un obstacle
 * \param     **grid      La grille de la bataille navale.
 * \param     nbr_col    Nombre de colonne dans la grille. (-1)
 * \param     nbr_line   Nombre de lignes dans la grille.  (-1)
 * \param     nbr_odds   Nombre d'obstacles à placer.
 */

void def_odds(char **grid, int nbr_col, int nbr_line, int nbr_odds){
  int col, line ;
  for(int i = 0 ; i < nbr_odds ; ++i){
    col = (rand() % 20);
    line = (rand() % 20);
    if(ft_test_boat(grid, col, line) == 0 && ft_test_born(nbr_col, nbr_line) == 0){
      grid[line][col] = '#' ;
    }
    else
      nbr_odds++ ;
  }   
}

/**
 * \brief     Place un bateau de dimension 2.
 * \details   Vérifie s'il y a des bateaux aux alentours des coordonées passées, si non
 *             un bateau est placé en verifiant que l'on ne sors pas de la grille.      
 * \param    **grid         Grille de la bataille navale .
 * \param    indice_col     Premiere coordonée.
 * \param    indice_line    Seconde coordonée.
 * \return   Renvoie un entier qui vaut 0 si le bateau a été placé, sinon 0.
 */

int ft_boat_1_2(char **grid, int indice_col, int indice_line){
	int conteur_col = indice_col;
	int conteur_line = indice_line;
	if (ft_test_boat(grid, conteur_col, conteur_line) != 0)
		return 1;
	if (ft_test_born(conteur_col, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line - 1) != 0)
			return 1;
	}
	if (indice_col < Dim-1){
		grid[indice_line][indice_col] = 'O';
		grid[indice_line][indice_col + 1] = 'O';
		return 0;
	}
	return 1;
}


/**
 * \brief    Place un bateau de dimension 3.
 * \details  Vérifie s'il y a des bateaux aux alentours des coordonées passées, si non
 *           un bateau est placé en verifiant que l'on ne sors pas de la grille.      
 * \param    **grid         Grille de la bataille navale .
 * \param    indice_col     Premiere coordonée.
 * \param    indice_line    Seconde coordonée.
 * \return   Renvoie un entier qui vaut 0 si le bateau a été placé, sinon 0.
 */

int ft_boat_1_3(char **grid, int indice_col, int indice_line){
	int conteur_col = indice_col;
	int conteur_line = indice_line;
	if (ft_test_born(conteur_col, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line) != 0)
			return 1;
	}
	if (indice_col < Dim-2){
		grid[indice_line][indice_col] = 'O';
		grid[indice_line][indice_col + 1] = 'O';
		grid[indice_line][indice_col + 2] = 'O';
		return 0;
	}
	return 1;
}


/**
 * \brief     Place un bateau de dimension 4.
 * \details   Vérifie s'il y a des bateaux aux alentours des coordonées passées, si non
 *             un bateau est placé en verifiant que l'on ne sors pas de la grille.      
 * \param    **grid         Grille de la bataille navale .
 * \param    indice_col     Premiere coordonée.
 * \param    indice_line    Seconde coordonée.
 * \return   Renvoie un entier qui vaut 0 si le bateau a été placé, sinon 0.
 */

int ft_boat_1_4(char **grid, int indice_col, int indice_line){
	int conteur_col = indice_col;
	int conteur_line = indice_line;
	if (ft_test_boat(grid, conteur_col, conteur_line) != 0)
		return 1;
	if (ft_test_born(conteur_col + 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 4) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 4) != 0)
			return 1;
	}
	if (indice_line < Dim-3){
		grid[indice_line][indice_col] = 'O';
		grid[indice_line + 1][indice_col] = 'O';
		grid[indice_line + 2][indice_col] = 'O';
		grid[indice_line + 3][indice_col] = 'O';
		return 0;
	}
	return 1;
}


/**
 * \brief     Place un bateau de dimension 5.
 * \details   Vérifie s'il y a des bateaux aux alentours des coordonées passées, si non
 *             un bateau est placé en verifiant que l'on ne sors pas de la grille.      
 * \param    **grid         Grille de la bataille navale .
 * \param    indice_col     Premiere coordonée.
 * \param    indice_line    Seconde coordonée.
 * \return   Renvoie un entier qui vaut 0 si le bateau a été placé, sinon 0.
 */

int ft_boat_1_5(char **grid, int indice_col, int indice_line){
	int conteur_col = indice_col;
	int conteur_line = indice_line;
	if (ft_test_boat(grid, conteur_col, conteur_line) != 0)
		return 1;
	if (ft_test_born(conteur_col + 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 4) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 4) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 4) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 4) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 4) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 4) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 5) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 5) != 0)
			return 1;
	}
	if (indice_line < Dim-4){
		grid[indice_line][indice_col] = 'O';
		grid[indice_line + 1][indice_col] = 'O';
		grid[indice_line + 2][indice_col] = 'O';
		grid[indice_line + 3][indice_col] = 'O';
		grid[indice_line + 4][indice_col] = 'O';
		return 0;
	}
	return 1;
}


/**
 * \brief     Place un bateau de dimension 6.
 * \details   Vérifie s'il y a des bateaux aux alentours des coordonées passées, si non
 *             un bateau est placé en verifiant que l'on ne sors pas de la grille.      
 * \param    **grid         Grille de la bataille navale .
 * \param    indice_col     Premiere coordonée.
 * \param    indice_line    Seconde coordonée.
 * \return   Renvoie un entier qui vaut 0 si le bateau a été placé, sinon 0.
 */

int ft_boat_1_6(char **grid, int indice_col, int indice_line){
	int conteur_col = indice_col;
	int conteur_line = indice_line;
	if (ft_test_boat(grid, conteur_col, conteur_line) != 0)
		return 1;
	if (ft_test_born(conteur_col, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 1) != 0)
			return 1;
	}
if (ft_test_born(conteur_col - 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 4, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 4, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 4, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 4, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 4, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 4, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 5, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 5, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 5, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 5, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 5, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 5, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 6, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 6, conteur_line) != 0)
			return 1;
	}
	if (indice_col < Dim-5){
		grid[indice_line][indice_col] = 'O';
		grid[indice_line][indice_col + 1] = 'O';
		grid[indice_line][indice_col + 2] = 'O';
		grid[indice_line][indice_col + 3] = 'O';
		grid[indice_line][indice_col + 4] = 'O';
		grid[indice_line][indice_col + 5] = 'O';
		return 0;
	}
	return 1;
}

/**
 * \brief     Place un bateau de dimension 4.
 * \details   Vérifie s'il y a des bateaux aux alentours des coordonées passées, si non
 *             un bateau est placé en verifiant que l'on ne sors pas de la grille.      
 * \param    **grid         Grille de la bataille navale .
 * \param    indice_col     Premiere coordonée.
 * \param    indice_line    Seconde coordonée.
 * \return   Renvoie un entier qui vaut 0 si le bateau a été placé, sinon 0.
 */

int ft_boat_2_2(char **grid, int indice_col, int indice_line){
	int conteur_col = indice_col;
	int conteur_line = indice_line;
	if (ft_test_boat(grid,  conteur_col, conteur_line) != 0)
		return 1;
	if (ft_test_born(conteur_col - 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 2) != 0)
			return 1;
	}
	if (indice_col < Dim-6 && indice_line < Dim-6){
		grid[indice_line][indice_col] = 'O';
		grid[indice_line + 1][indice_col] = 'O';
		grid[indice_line][indice_col + 1] = 'O';
		grid[indice_line + 1][indice_col + 1] = 'O';
		return 0;
	}
	return 1;
}

/**
 * \brief     Place un bateau de dimension 8.
 * \details   Vérifie s'il y a des bateaux aux alentours des coordonées passées, si non
 *             un bateau est placé en verifiant que l'on ne sors pas de la grille.      
 * \param    **grid         Grille de la bataille navale .
 * \param    indice_col     Premiere coordonée.
 * \param    indice_line    Seconde coordonée.
 * \return   Renvoie un entier qui vaut 0 si le bateau a été placé, sinon 0.
 */

int ft_boat_2_4(char **grid, int indice_col, int indice_line){
	int conteur_col = indice_col;
	int conteur_line = indice_line;
	if (ft_test_boat(grid,  conteur_col, conteur_line) != 0)
		return 1;
	if (ft_test_born(conteur_col - 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 4, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 4, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line + 4) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line + 4) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 4, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 4, conteur_line + 1) != 0)
			return 1;
	}
	if (indice_col < Dim-4 && indice_line < Dim-2){
		grid[indice_line][indice_col] = 'O';
		grid[indice_line + 1][indice_col] = 'O';
		grid[indice_line][indice_col + 1] = 'O';
		grid[indice_line][indice_col + 2] = 'O';
		grid[indice_line][indice_col + 3] = 'O';
		grid[indice_line + 1][indice_col + 1] = 'O';
		grid[indice_line + 1][indice_col + 2] = 'O';
		grid[indice_line + 1][indice_col + 3] = 'O';
		return 0;
	}
	return 1;
}

/**
 * \brief     Place un bateau de dimension 6.
 * \details   Vérifie s'il y a des bateaux aux alentours des coordonées passées, si non
 *             un bateau est placé en verifiant que l'on ne sors pas de la grille.      
 * \param    **grid         Grille de la bataille navale .
 * \param    indice_col     Premiere coordonée.
 * \param    indice_line    Seconde coordonée.
 * \return   Renvoie un entier qui vaut 0 si le bateau a été placé, sinon 0.
 */
int ft_boat_1_4_1_3(char **grid, int indice_col, int indice_line){
	int conteur_col = indice_col;
	int conteur_line = indice_line;
	if (ft_test_boat(grid, conteur_col, conteur_line) != 0)
		return 1;
	if (ft_test_born(conteur_col + 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line - 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line - 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 1) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 1) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col - 1, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col - 1, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col, conteur_line + 4) == 0){
		if (ft_test_boat(grid, conteur_col, conteur_line + 4) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 1, conteur_line + 4) == 0){
		if (ft_test_boat(grid, conteur_col + 1, conteur_line + 4) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line + 2) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line + 2) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 3, conteur_line + 3) == 0){
		if (ft_test_boat(grid, conteur_col + 3, conteur_line + 3) != 0)
			return 1;
	}
	if (ft_test_born(conteur_col + 2, conteur_line + 4) == 0){
		if (ft_test_boat(grid, conteur_col + 2, conteur_line + 4) != 0)
			return 1;
	}
	if (indice_line < Dim-1 && indice_col < Dim-3){
		grid[indice_line][indice_col] = 'O';
		grid[indice_line + 1][indice_col] = 'O';
		grid[indice_line + 2][indice_col] = 'O';
		grid[indice_line + 3][indice_col] = 'O';
		grid[indice_line + 3][indice_col + 1] = 'O';
		grid[indice_line + 3][indice_col + 2] = 'O';
		return 0;
	}
	return 1;
}

/**
 * \brief     Fonction qui remplie la grille.
 * \details   Choisis des coordonnées aléatoires et appel les fonctions qui place bateaux avec
              ces coordonées .      
 * \param    **grid         Grille de la bataille navale .
 * \return   Renvoie un char ** qui correspond à la grille remplie . 
 */


char **ft_fill_grid(char **grid){
	int indice_col = (rand() % 20);
	int indice_line = (rand() % 20);
	while (ft_boat_1_2(grid, indice_col, indice_line) != 0){
		indice_col = (rand() % 20);
		indice_line = (rand() % 20);
	}
	indice_col = (rand() % 20);
	indice_line = (rand() % 20);
	while (ft_boat_1_3(grid, indice_col, indice_line) !=0){
		indice_col = (rand() % 20);
		indice_line = (rand() % 20);
	}
	indice_col = (rand() % 20);
	indice_line = (rand() % 20);
	while (ft_boat_1_4(grid, indice_col, indice_line) != 0){
		indice_col = (rand() % 20);
		indice_line = (rand() % 20);
	}
	indice_col = (rand() % 20);
	indice_line = (rand() % 20);
	while (ft_boat_1_5(grid, indice_col, indice_line) != 0){
		indice_col = (rand() % 20);
		indice_line = (rand() % 20);
	}
	indice_col = (rand() % 20);
	indice_line = (rand() % 20);
	while (ft_boat_1_6(grid, indice_col, indice_line) != 0){
		indice_col = (rand() % 20);
		indice_line = (rand() % 20);
	}
	indice_col = (rand() % 20);
	indice_line = (rand() % 20);
	while (ft_boat_2_2(grid, indice_col, indice_line) != 0){
		indice_col = (rand() % 20);
		indice_line = (rand() % 20);
	}
	indice_col = (rand() % 20);
	indice_line = (rand() % 20);
	while (ft_boat_2_4(grid, indice_col, indice_line) != 0){
		indice_col = (rand() % 20);
		indice_line = (rand() % 20);
	}
	indice_col = (rand() % 20);
	indice_line = (rand() % 20);
	while (ft_boat_1_4_1_3(grid, indice_col, indice_line) != 0){
		indice_col = (rand() % 20);
		indice_line = (rand() % 20);
	}
	def_odds(grid, 18, 18, 5) ;
	return grid;
}


/**
 * \brief     Fonction qui crée la grille.
 * \details   Crée la grille, puis applique ft_fill_grid sur la grille pour la remplir .      
 * \return    Renvoie un char **  qui correspond à la grille.
 */

char **cree_tableau(void){
	char **grid;
	int conteur_col;
	int conteur_line;
	grid = (char **)malloc(sizeof(char *) * 21);
	for (conteur_col = 0; conteur_col < 21; conteur_col++)
		grid[conteur_col] = (char *)malloc(sizeof(char) * 21);
	for (conteur_line = 0; conteur_line < Dim; conteur_line++){
		for (conteur_col = 0; conteur_col < Dim; conteur_col++)
			grid[conteur_line][conteur_col] = '.';
		grid[conteur_line][conteur_col] = '\0';
	}
	grid[conteur_line][0] = '\0';
	grid = ft_fill_grid(grid);
	return grid;
}
