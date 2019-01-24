#include <stdio.h>

int main(){

  int tab1[8];

  for(int i=0;i<8;i++){
    tab1[i]=rand()%8;
    printf(" %d",tab1[i]);
    
  }
  
  return 0;
}
