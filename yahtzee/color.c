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

void green() {
  printf("\033[1;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void blue() {
  printf("\033[1;34m");
}

void magenta() {
  printf("\033[1;35m");
}

void cyan() {
  printf("\033[1;36m");
}




void resetColor () {
  printf("\033[0m");
}


int main(int argc, char const *argv[])
{
    red();
    printf("hello\n");
    green();
    printf("hello\n");
    yellow();
    printf("hello\n");
    blue();
    printf("hello\n");
    magenta();
    printf("hello\n");
    cyan();
    printf("hello\n");
    resetColor();
    printf("hello\n");
    return 0;
}