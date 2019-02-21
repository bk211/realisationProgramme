/**
 * \file      create_grid.h
 * \brief     Le header comportant les includes et prototype des fonctions
 *
 */
#define Dim 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define Dim 20
int ft_test_born(int indice_col,int indice_line);
int ft_test_boat(char **grid, int indice_col, int indice_line);
int ft_boat_1_2(char **grid, int indice_col, int indice_line);
int ft_boat_1_3(char **grid, int indice_col, int indice_line);
int ft_boat_1_4(char **grid, int indice_col, int indice_line);
int ft_boat_1_5(char **grid, int indice_col, int indice_line);
int ft_boat_1_6(char **grid, int indice_col, int indice_line);
int ft_boat_2_2(char **grid, int indice_col, int indice_line);
int ft_boat_2_4(char **grid, int indice_col, int indice_line);
int ft_boat_1_4_1_3(char **grid, int indice_col, int indice_line);
char **ft_fill_grid(char **grid);
char **cree_tableau(void);
