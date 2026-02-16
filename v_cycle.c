#include <stdio.h>
#include <stdlib.h>
#include "umfpk.h"
#include "time.h"
#include <math.h>
#include "Bresidue.h"
#include "er.h"
#include "residual.h"
#include "Matrix_p.h"
#include "Restriction.h"
#include "Ac.h"
#include "Coarse_grid_correction.h"
#include "prolongation.h"
#include "v_cycle.h"




/*the v-cycle from the multigrid*/

int v_cycle(int m,int iteration,int n,int mc,int depth,int level,int **stock_ia,int **stock_ja,double **stock_a,double **stock_b,double **stock_x1)
{

   
  double *Br,*p,*PUC,*Residu;
  int nc,nnzR;

  


//-------------------------------------------------------------------
/*pre-smoothing part*/
  for (int i = 0; i < 1; ++i)
{
   if (er(m,n,(stock_ia)[level], (stock_ja)[level], (stock_a)[level], (stock_b)[level],(stock_x1)[level],&Br)) 
    return 1;

  

  if (Bresidue(m,n,&((stock_x1)[level]),Br)) 
    return 1;

}




  if (residual(m,n,(stock_ia)[level], (stock_ja)[level], (stock_a)[level], (stock_b)[level],(stock_x1)[level],&Residu)) 
    return 1;

//---------------------------------------------------------------------------
/*Restriction part*/
 if (Matrix_p(m,n,&p,&nnzR)) 
    return 1;  

if (Restriction(m,n,p,&(stock_b)[level+1],Residu,nnzR)) 
   return 1; 



if (Ac(mc,&nc, &((stock_ia)[level+1]), &((stock_ja)[level+1]), &((stock_a)[level+1])))
        return 1;



(stock_x1)[level+1] = calloc(nc,sizeof(double));



if (level == depth - 1)
{  

  //coarse grid
   
  if( solve_umfpack(nc,(stock_ia)[level+1], (stock_ja)[level+1], (stock_a)[level+1], (stock_b)[level+1], (stock_x1)[level+1])) 
     return 1;

}
else 
 {
    
  if (v_cycle(mc,iteration,nc,mc/2,depth,level+1,stock_ia,stock_ja,stock_a,stock_b,stock_x1)) 
        return 1; 

    
    free(p);free(Residu);free((stock_ja)[level+1]);free((stock_ia)[level+1]);
    

  }

//--------------------------------------------------------------------------------------------
   /*prolongation*/
   if (prolongation(m,n,&PUC,(stock_x1)[level+1])) 
    return 1;

  

  
   if (Coarse_grid_correction(n,&((stock_x1)[level]),PUC)) 
      return 1;


  
//---------------------------------------------------------------------------------------------

  /*post-smoothing part*/
 for (int i = 0; i < 1; ++i)
{


   if (er(m,n,(stock_ia)[level], (stock_ja)[level], (stock_a)[level], (stock_b)[level],(stock_x1)[level],&Br)) 
    return 1;

  

  if (Bresidue(m,n,&((stock_x1)[level]),Br)) 
    return 1;


}


    



return 0;

}