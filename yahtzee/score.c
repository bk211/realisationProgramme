#include "score.h"

void testYahtzee(int *tab,int *tab_score) {
  // verif Yahtzee
  if(tab[0] == tab[1]) {
    if(tab[1] == tab[2]) {
      if(tab[2] == tab[3]) {
	if(tab[3] == tab[4]) {
	  if(tab[4] == tab[5]) {
	    if(tab[5] == tab[6]) {
		tab_score[0]+= 50;
	      }
	      }
	  }
	}
      }
    }
}

void testPetiteSuite(int *tab,int *tab_score) {
    int i;
    // verif petite suite
  for(i=0;i<8;i++){
        if(tab[i] == 1)
	  {
	    for(i=0;i<8;i++){
	      if(tab[i] == 2)
		 {
		   for(i=0;i<8;i++){
		     if(tab[i] == 3)
		        {
			  for(i=0;i<8;i++){
			    if(tab[i] == 4)
			       {
				 for(i=0;i<8;i++){
				   if(tab[i] == 5)
				      {
					for(i=0;i<8;i++){
					  if(tab[i] == 6)
					     {
					       for(i=0;i<8;i++){
						 if(tab[i] == 7)
						   {						     			     	   tab_score[1]+=30;
						   }
					       }
					     }
					}
				      }
				 }
			       }
			  }
			}
		   }
		 }
	    }
	  }
  }
  }

void testGrandeSuite(int *tab,int *tab_score) {
    int i;
    
  // verif grande suite
   for(i=0;i<8;i++){
        if(tab[i] == 2)
	  {
	    for(i=0;i<8;i++){
	      if(tab[i] == 3)
		 {
		   for(i=0;i<8;i++){
		     if(tab[i] == 4)
		        {
			  for(i=0;i<8;i++){
			    if(tab[i] == 5)
			       {
				 for(i=0;i<8;i++){
				   if(tab[i] == 6)
				      {
					for(i=0;i<8;i++){
					  if(tab[i] == 7)
					     {
					       for(i=0;i<8;i++){
						 if(tab[i] == 8)
						   {
						     tab_score[2]+=40;
						   }
					       }
					     }
					}
				      }
				 }
			       }
			  }
			}
		   }
		 }
	    }
	  }
   }
   }

void testBrelan(int *tab,int *tab_score) {
  int tab_occurence[8]={0,0,0,0,0,0,0};
    int i,score =0;

  for(i=0;i<8;i++){ // somme de tout les dés
    score+=(tab[i]);
  }

  for(i=0;i<8;i++) {
    
    if(tab[i] == 1){
      tab_occurence[0]+=1;
    }
    else if(tab[i] == 2)
      {
	tab_occurence[1]+=1;
      }
    else if(tab[i] == 3)
      {
	tab_occurence[2]+=1;
      }
    else if(tab[i] == 4)
      {
	tab_occurence[3]+=1;
      }
    else if(tab[i] == 5)
      {
	tab_occurence[4]+=1;
      }
    else if(tab[i] == 6)
      {
	tab_occurence[5]+=1;
      }
    else if(tab[i] == 7)
      {
	tab_occurence[6]+=1;
      }
    else if(tab[i] == 8)
      {
	tab_occurence[7]+=1;
      }
  }
    
    for(i=0;i<8;i++)
      {
	if(tab_occurence[i]==3)
	  {
	    for(i=0;i<8;i++)
	      {
		if(tab_occurence[i] == 4)
		  {
		    return;
		  }
	      }
	    tab_score[3]+=score;
	  }
      }
}


void testFullv1(int *tab,int* tab_score){

  int tab_occurence[8]={0,0,0,0,0,0,0,0};
  int i,j;
  for(i=0;i<8;i++) {
    
    if(tab[i] == 1){
      tab_occurence[0]+=1;
    }
    else if(tab[i] == 2)
      {
	tab_occurence[1]+=1;
      }
    else if(tab[i] == 3)
      {
	tab_occurence[2]+=1;
      }
    else if(tab[i] == 4)
      {
	tab_occurence[3]+=1;
      }
    else if(tab[i] == 5)
      {
	tab_occurence[4]+=1;
      }
    else if(tab[i] == 6)
      {
	tab_occurence[5]+=1;
      }
    else if(tab[i] == 7)
      {
	tab_occurence[6]+=1;
      }
    else if(tab[i] == 8)
      {
	tab_occurence[7]+=1;
      }
  }
    
    for(i=0;i<8;i++)
      {
	if(tab_occurence[i]==5)
	  {
	    for(j=0;j<8;j++)
	      {
		if(tab_occurence[j]==2)
		  {
		    tab_score[4]+=25;		    
		  }
	      }
	  }
      }
    
}


void testFullv2(int *tab,int* tab_score){
  int tab_occurence[8]={0,0,0,0,0,0,0,0};

  int i,j;
  for(i=0;i<8;i++) {
    
    if(tab[i] == 1){
      tab_occurence[0]+=1;
    }
    else if(tab[i] == 2)
      {
	tab_occurence[1]+=1;
      }
    else if(tab[i] == 3)
      {
	tab_occurence[2]+=1;
      }
    else if(tab[i] == 4)
      {
	tab_occurence[3]+=1;
      }
    else if(tab[i] == 5)
      {
	tab_occurence[4]+=1;
      }
    else if(tab[i] == 6)
      {
	tab_occurence[5]+=1;
      }
    else if(tab[i] == 7)
      {
	tab_occurence[6]+=1;
      }
    else if(tab[i] == 8)
      {
	tab_occurence[7]+=1;
      }
  }
    
    for(i=0;i<8;i++)
      {
	if(tab_occurence[i]==3)
	  {
	    for(j=0;j<8;j++)
	      {
		if(tab_occurence[j]==4)
		  {

		    tab_score[4]+=25;		    

		  }
	      }
	  }
      }
    
}

void testCombinatoire(int *tab_score, int *tab_dee){
	/*test et remplit le tableau des score*/
	testYahtzee(tab_dee,tab_score);
	testPetiteSuite(tab_dee,tab_score);
	testGrandeSuite(tab_dee,tab_score);
	testBrelan(tab_dee,tab_score);
	testFullv1(tab_dee,tab_score);
	testFullv2(tab_dee,tab_score);
}




void displayScore(int* tab_score,int *tab){
	int i,score=0,somme=0;



	testCombinatoire(tab_score,tab);

	printf("voici le score pour Yatzee : %d\n",tab_score[0]);
	       
	printf("voici le score pour Petite Suite : %d\n",tab_score[1]);
           
	printf("voici le score pour Grande Suite : %d\n",tab_score[2]);
             
	printf("voici le score pour Brelan : %d\n",tab_score[3]);
             
	printf("voici le score pour Full : %d\n",tab_score[4]);
	
	for(i=0;i<8;i++){ // somme de tout les dés
	  score+=(tab[i]);
	}

	printf("voici le score des dés :%d\n",score);
	
	for(i=0;i<5;i++)
	  {
	    somme+=(tab_score[i]);
	  }
	somme+=score;

	printf("voici le score total : %d\n",somme);

	tab_score[6] = somme;
    }


void compareScore(int a, int b){
	if(a > b){
		printf("Bravo! le joueur 1 remporte la partie\n");
	}
	else if (b > a){
		printf("Bravo! le joueur 2 remporte la partie\n");
	}
	else{
		printf("Match nul\n");	
	}	
}