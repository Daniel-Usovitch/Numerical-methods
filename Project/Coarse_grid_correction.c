#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Coarse_grid_correction(int n, double **x1,double *PUC)

{

	for (int i = 0; i < (n); ++i)
	{
		     
			(*x1)[i] = (*x1)[i] + (PUC)[i] ;
			

	}






 return 0;

}
