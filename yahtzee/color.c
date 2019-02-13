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


//sample of usage
/*

int main () {
  red();
  printf("Hello ");
  yellow();
  printf("world\n");
  green();
  printf("my dear\n");
  resetColor();
  return 0;
}
*/