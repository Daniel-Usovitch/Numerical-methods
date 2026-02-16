#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int residu(int m, int *n, int **ia, int **ja, double **a, double **b,double **Residu,double *Resultat){ 
	
	  
	  
	  int u ,r;
	  double index , index2;
	   
	   /*Ici on va effectuer un produit vectoriel A et X à partir du format csr */
	   		  
		  index = 0 ;		  
	      for(u = 0; u < (*n) ; u++){
			  index += ((*Residu)[u])*((*Residu)[u]) ;}
			  //printf("la norme de Ax-b (pour m = %d) = %e\n", m,sqrt(index));
			  
			  index2 = 0;
		/* ci-dessous , on va effectuer la norme de B*/	  
		 for(r = 0; r < (*n) ; r++){
			  index2 += ((*b)[r])*((*b)[r]) ;}
			  //printf("la norme de b (pour m = %d) = %e\n", m,sqrt(index2));
			        
          *Resultat = sqrt(index)/sqrt(index2) ; 
          
          printf("residu (pour m = %d) = %E\n", m,*Resultat); /* Ici on obtient notre résidu*/
          

	
	
	return 0; 
}
