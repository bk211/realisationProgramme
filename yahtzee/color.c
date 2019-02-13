/**
 * \file         color.c
 * \author    groupe3
 * \version   1.0
 * \date       10 fevrier 2019
 * \brief       Gére les couleur dans le jeu.
 *
 *                  
 */
#include <stdio.h>
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}
void green() {
  printf("\033[1;32m");
}

void resetColor () {
  printf("\033[0m");
}

