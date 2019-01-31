#include<stdio.h>

int testYahtzee(int tab[8],int tab3[5]) {
  int i;
  // verif Yahtzee
  if(tab[0] == tab[1] == tab[2] == tab[3] == tab[4] == tab[5] == tab[6])
    {
      return 50;
      tab3[0]+=1;
    }
}

int testPetiteSuite(int tab[8],int tab3[5]) {
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
						   {
						     return 30;
						     tab3[1]+=1;
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

int testGrandeSuite(int tab[8],int tab3[5]) {
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
						     return 40;
						     tab3[2]+=1;
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

int testBrelan(int tab[8],int tab3[5]) {
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
	    tab3[3]+=1;
	    return score;
	  }
      }
   
  }


int testFullv1(int tab[8],int tab3[5]){
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
		    tab3[4]+=1;
		    return 25;
		  }
	      }
	  }
      }
    
}

int testFullv2(int tab[8],int tab3[5]){
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
		    tab3[4]+=1;
		    return 25;
		  }
	      }
	  }
      }
    
}
  
int main() {
  int tab[8]={3,3,3,7,7,7,7};
  int tab3[5];
  int a=testFullv2(tab,tab3);
  printf("voici  %d \n",a);
}


