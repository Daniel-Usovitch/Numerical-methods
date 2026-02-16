#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int residual(int m,int n, int *ia,int *ja,double *a,double *b,double *x,double **Residu) { 



      double res; 

	  *Residu = malloc((n)*sizeof(double));

	  for(int i = 0 ; i < (n);i++){
		  res = 0.0;
		  for(int j = (ia)[i] ; j < (ia)[i+1]; j++){
			  res += ((a)[j])*((x)[(ja)[j]]); 
			  
			  } 
			   (*Residu)[i] = (b)[i] - res; 
			   
			  }  



return 0;

}
