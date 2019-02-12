#include "score.h"
/**
 * \brief      Verifie si la figure Yahtzee est présente
 * \details    Si la premiere des est équivalente a la suivante,on verifie si la suivante est équivalente à la prochaine de celle ci, ainsi de suite
 *                  
 * \param    *tab               tableau content les des.
 * \param    *tab_score         tableau dans lequel on insere le score.
 * 
 */

int testYahtzee(int *tab) {
  // verif Yahtzee
  int choix;
  if(tab[0] == tab[1]
  	  &&tab[1] == tab[2]
      &&tab[2] == tab[3]
	  &&tab[3] == tab[4]
	  &&tab[4] == tab[5]
	  &&tab[5] == tab[6]){
	  	printf("Il y a un Yahtzee de %d\n",tab[0]);
		return 50;
  }
  return 0;
}

/**
 * \brief      Verifie si la figure PetiteSuite est présente
 * \details    S'il y a une des qui vaut 1, on regard s'il y a une des qui vaut 2, ainsi de suite jusqu'a 7,si 7 est présent, alors on a une PetiteSuite
 *                  
 * \param    *tab               tableau content les des.
 * \param    *tab_score         tableau dans lequel on insere le score.
 
 */
int testPetiteSuite(int *tab) {
    int i;
    int choix;
    // verif petite suite
  for(i=0;i<7;i++){
        if(tab[i] == 1)
	  {
	    for(i=0;i<7;i++){
	      if(tab[i] == 2)
		 {
		   for(i=0;i<7;i++){
		     if(tab[i] == 3)
		        {
			  for(i=0;i<7;i++){
			    if(tab[i] == 4)
			       {
				 for(i=0;i<7;i++){
				   if(tab[i] == 5)
				      {
					for(i=0;i<7;i++){
					  if(tab[i] == 6)
					     {
					       for(i=0;i<7;i++){
						 if(tab[i] == 7)
						   {
						     printf("Il y a une PetiteSuite\n");
						     return 30;			     
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
  return 0;
  }

/**
 * \brief      Verifie si la figure GrandeSuite est présente
 * \details    S'il y a une des qui vaut 2, on regard s'il y a une des qui vaut 3, ainsi de suite jusqu'a 7, si 7 est présent, alors il y a GrandeSuite
 *                  
 * \param    *tab               tableau content les des.
 * \param    *tab_score         tableau dans lequel on insere le score.
 
 */

int testGrandeSuite(int *tab) {
    int i;
    int choix;
    
  // verif grande suite
   for(i=0;i<7;i++){
        if(tab[i] == 2)
	  {
	    for(i=0;i<7;i++){
	      if(tab[i] == 3)
		 {
		   for(i=0;i<7;i++){
		     if(tab[i] == 4)
		        {
			  for(i=0;i<7;i++){
			    if(tab[i] == 5)
			       {
				 for(i=0;i<7;i++){
				   if(tab[i] == 6)
				      {
					for(i=0;i<7;i++){
					  if(tab[i] == 7)
					     {
					       for(i=0;i<7;i++){
						 if(tab[i] == 8)
						   {

						      printf("Il y a une GrandeSuite\n");
						
						     return 40;
							
						    
						      
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
   return 0;  
}

/**
 * \brief      Verifie si la figure Brelan est présente
 * \details    On parcours le tableau contenant les des, puis a chaque fois que des des réapparaisent, on fais +1 dans le tableau d'occurence. S'il y a une occurence de 3 dans le tableau d'occurence ET qu'il n'y a pas d'occurence de 4, alors on a un Brelan . 
 *                  
 * \param    *tab               tableau content les des.
 * \param    *tab_score         tableau dans lequel on insere le score.
 
 */

int testBrelan(int *tab) {
  int tab_occurence[8]={0,0,0,0,0,0,0,0};
  int i,j;
  int choix=0;
  int brelan1,brelan2=0;
  int score =sommeScore(tab);

  for(i=0;i<7;i++) { // parcours du tableau de des et les occurences sont enregistré dans le tab_occurence
    
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
    
  	for(i=0;i<8;i++) // parcours du tab_occurence
      {
		if(tab_occurence[i]==3)
	  	{
	    	brelan1=i+1; // permet de connaitre quel brelan on a ( 1 ou 2 ou 3 ...)
	    	for(j=i+1;j<8;j++)
	      	{
				if(tab_occurence[j] == 3 && j !=i)
		  		{
		    	brelan2=j+1;  // permet de connaitre quel brelan on a ( 1 ou 2 ou 3 ...)
		  		}
	      	}

	    	if(brelan2 =! 0) // s'il y a deux types de brelan, sinon le if est sauté
	     	{
				printf("Vous avez deux types de brelan \n");
				printf("Il y a un Brelan de %d et un Brelan de %d\n",brelan1,brelan2);
			}
	    	else{ // si le joueur a décidé de garder le brelan précédent , on oublie celui là
	     		printf("Il y a un Brelan de %d\n",brelan1);
	    	}
	    
		return score;
	  }
	    
	}
    
  return 0;
}


/**
 * \brief      Verifie si la figure Full type1 est présente (5des identique + 2des identiques)
 * \details    On parcours le tableau contenant les des, puis a chaque fois que des des réapparaisent, on fais +1 dans le tableau d'occurence. S'il y a une occurence de 5 dans le tableau d'occurence ET qu'il y a une occurence de 2, alors on a un Full type1 . 
 *                  
 * \param    *tab               tableau content les des.
 * \param    *tab_score         tableau dans lequel on insere le score.
 
 */

int testFullv1(int *tab){

  int tab_occurence[8]={0,0,0,0,0,0,0,0};
  int i,j;
  int choix;
  int full1,full2;
  for(i=0;i<7;i++) {
    
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
	    full1=i+1;
	    for(j=0;j<8;j++)
	      {
		if(tab_occurence[j]==2)
		  {
		    full2=j+1;
		    printf("Il y a un Full de %d et %d\n",full1,full2);
		    return 25;
		 
		   
		  }
	      }
	  }
      }
    
    return 0;
}


/**
 * \brief      Verifie si la figure Full type2 est présente (3des identique + 4des identiques)
 * \details    On parcours le tableau contenant les des, puis a chaque fois que des des réapparaisent, on fais +1 dans le tableau d'occurence. S'il y a une occurence de 3 dans le tableau d'occurence ET qu'il y a une occurence de 4, alors on a un Full type2 . 
 *                  
 * \param    *tab               tableau content les des.
 * \param    *tab_score         tableau dans lequel on insere le score.
 
 */

int testFullv2(int *tab){
  int tab_occurence[8]={0,0,0,0,0,0,0,0};
  int choix;
  int i,j;
  int full1,full2;
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
	    full1=i+1;
	    for(j=0;j<8;j++)
	      {
		if(tab_occurence[j]==4)
		  {
		    full2=j+1;
		    printf("Il y a un Full de %d et %d\n",full1,full2);
			 return 25;
	
		    
		  }
	      }
	  }
      }
    return 0;
}


/**
 * \brief      Appel a tout les fonctions de verification de figure
 * \details    Appel tout les fonctions de verification de figure et remplissage
 * \du tableau de score
 *                  
 * \param    *tab_score        tableau contenant les scores
 * \param    *tab_dee         tableau contenant les des
 
 */

void testCombinatoire(int *tab_score, int *tab_dee){
	/*test et remplit le tableau des score*/
	tab_score[8] = testBrelan(tab_dee);
	tab_score[9] = testPetiteSuite(tab_dee);
	tab_score[10] = testGrandeSuite(tab_dee);
	//tab_score[11] = testCarre(tab_dee);
	tab_score[12] = testFullv1(tab_dee);
	tab_score[13] = testFullv2(tab_dee);
	tab_score[14] = testYahtzee(tab_dee);
}




/**
 * \brief      Affiche les scores
 * \details    Appel la fonction TestCombinatoire qui s'occupe de remplir le tableau des score, puis affiche les scores
 *                  
 * \param    *tab_score        tableau contenant les scores
 * \param    *tab_dee              tableau contenant les des
 
 */

void displayScore(int* tab_score,int *tab_dee){
	testCombinatoire(tab_score,tab_dee);
	displayTabScore(tab_score);

}


/**
 * \brief      Fonction qui décide qui l'emporte
 * \details    Compare le score des deux joueurs et affiche le gagnant ou match nul
 *                  
 * \param    a        score du joueur 1
 * \param    b        score du joueur 2
 
 */

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


int sommeScore(int * tab){
	int somme = 0;
	for (int i = 0; i < 7; ++i)
	{
		somme += tab[i];
	}
	return somme;
}



void displayTabScore(int *tab){
	printf("========================================================\n" );
	printf("%-4s %-12s: %d\n"," 1 >>", "AS", tab[0]);
	printf("%-4s %-12s: %d\n"," 2 >>", "DEUX", tab[1]);
	printf("%-4s %-12s: %d\n"," 3 >>", "TROIS", tab[2]);
	printf("%-4s %-12s: %d\n"," 4 >>", "QUATRE", tab[3]);
	printf("%-4s %-12s: %d\n"," 5 >>", "CINQ", tab[4]);
	printf("%-4s %-12s: %d\n"," 6 >>", "SIX", tab[5]);
	printf("%-4s %-12s: %d\n"," 7 >>", "SEPT", tab[6]);
	printf("%-4s %-12s: %d\n"," 8 >>", "HUIT", tab[7]);
	printf("%-4s %-12s: %d\n"," 9 >>", "BRELAN", tab[8]);
	printf("%-4s %-12s: %d\n","10 >>", "SUITE(1-6)", tab[9]);
	printf("%-4s %-12s: %d\n","11 >>", "SUITE(2-7)", tab[10]);
	//printf("%-4s %-12s: %d\n","12 >>", "CARRE", tab[11]);
	printf("%-4s %-12s: %d\n","13 >>", "FULL(2+5)", tab[12]);
	printf("%-4s %-12s: %d\n","14 >>", "FULL(3+4)", tab[13]);
	printf("%-4s %-12s: %d\n","15 >>", "YAHTZEE", tab[14]);
	
	printf("========================================================\n" );

}

int saisitScore(int *tab,int *tabFinal){
	int answer;
	while(1){
		
		printf("Saisissez le numero de la case que vous voulez remplir  \n");
		scanf("%d",&answer);
		--answer;
		if(tabFinal[answer] >= 0){
			printf("La case est deja remplit, merci de choisir une autre\n");
		}
		else{
			tabFinal[answer] = tab[answer];
			return 1;
		}

	}
}



