#include <stdio.h>

void coup(int n){
  return rand() % n;
}

void remplirtab(int nbr){
  int i;
  for (i=0;i<nbr;i++){
    tab[i]=coup(8);
  }
}


int main(){

  
  return 0;
}
