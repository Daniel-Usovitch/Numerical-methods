#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Bresidue(int m,int n,double **x,double *Br) { 
    

    for (int i = 0; i < (n); ++i)
    {   
        
        (*x)[i] = (*x)[i] + (Br)[i];

    }


    free(Br);


return 0;




	}