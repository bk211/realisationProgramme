#include<stdio.h>

int testYahtzee(int tab[8]) {
  int i;
  int tab3[5];
  // verif Yahtzee
  if(tab[0] == tab[1] == tab[2] == tab[3] == tab[4] == tab[5] == tab[6])
    {
      return 50;
      tab3[3]=+1;
    }
}

  int testPetiteSuite(int tab[8]) {
    int i;
    int tab3[5];
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

   int testGrandeSuite(int tab[8]) {
    int i;
    int tab3[5];
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

int testBrelan(int tab[8]) {
  int tab2[8]={0,0,0,0,0,0,0,0};
  int tab3[5]={0,0,0,0,0};
  int i;
  for(i=0;i<8;i++) {
    
    if(tab[i] == 1){
      tab2[0]+=1;
    }
    else if(tab[i] == 2)
      {
	tab2[1]+=1;
      }
    else if(tab[i] == 3)
      {
	tab2[2]+=1;
      }
    else if(tab[i] == 4)
      {
	tab2[3]+=1;
      }
    else if(tab[i] == 5)
      {
	tab2[4]+=1;
      }
    else if(tab[i] == 6)
      {
	tab2[5]+=1;
      }
    else if(tab[i] == 7)
      {
	tab2[6]+=1;
      }
    else if(tab[i] == 8)
      {
	tab2[7]+=1;
      }
  }
    
    for(i=0;i<8;i++)
      {
	if(tab2[i]==3)
	  {
	    tab3[0]+=1;
	  }
      }
    for(i=0;i <5;i++)
      {
	printf("%d\n",tab3[i]);
      }

  
}

int main() {
  int tab[8]={1,2,3,4,7,7,7,5};
  testBrelan(tab);
}



