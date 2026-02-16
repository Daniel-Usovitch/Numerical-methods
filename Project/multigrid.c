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
#include "w_cycle.h"



int multigrid(int m,int iteration,int n,int mc,int depth,int level,int *ia,int *ja,double *a,double *b,double **x1,int cycle)
{

   
  int  nnzR,nc,**stock_ja,**stock_ia;
  double *Br,*p,*PUC,*Residu,**stock_a,**stock_b,**stock_x1;



for ( int i = 0; i < iteration ; ++i)
{ 

stock_a = (double**)calloc((depth+2),sizeof(double*));
stock_b = (double**)calloc((depth+2),sizeof(double*)); 
stock_ja = (int**)calloc((depth+2),sizeof(int*));
stock_ia = (int**)calloc((depth+2),sizeof(int*));
stock_x1 = (double**)calloc((depth+2),sizeof(double*));
(stock_x1)[level] = *x1;
(stock_b)[level] = b;
(stock_a)[level] = a; 
(stock_ja)[level] =  ja;
(stock_ia)[level] =  ia;



/*pre-smoothing part*/
//------------------------------------------------------------
for (int i = 0; i < 1; ++i)
{  
   /*the er function will calculate directly Br from xk+1 = xk + Br */ 
   if (er(m,n,(stock_ia)[level],(stock_ja)[level], (stock_a)[level], (stock_b)[level],(stock_x1)[level],&Br)) 
    return 1;

  
  /*here we will calculate the new x1 <--> xk+1 */
  if (Bresidue(m,n,&((stock_x1)[level]),Br)) 
    return 1;

}
 
 
/*residual will be calculate the last residual from the pre-smoothing*/

if (residual(m,n,(stock_ia)[level], (stock_ja)[level], (stock_a)[level], (stock_b)[level],(stock_x1)[level],&Residu)) 
    return 1;
//--------------------------------------------------------------------
  
  /*Restriction part */



/*we will collect the element from the matrix_p (each prolongation point in the grid) for solving restriction*/
if (Matrix_p(m,n,&p,&nnzR)) 
    return 1;  
/*here we solve the restriction directly(not necessary to calculate the prolongation transpose)*/
if (Restriction(m,n,p,&(stock_b)[level+1],Residu,nnzR)) 
   return 1; 




/*here, we reduce the grid*/
if (Ac(mc,&nc, &((stock_ia)[level+1]), &((stock_ja)[level+1]), &((stock_a)[level+1])))
        return 1;




/*the solution vector for the new grid*/
(stock_x1)[level+1] = calloc(nc,sizeof(double));
     


if (level == depth - 1)
{  

  if( solve_umfpack(nc,(stock_ia)[level+1], (stock_ja)[level+1], (stock_a)[level+1], (stock_b)[level+1], (stock_x1)[level+1])) 
     return 1;

}
else 
 {
  
  if (cycle == 0)
    {
        if (v_cycle(mc,iteration,nc,mc/2,depth,level+1,stock_ia,stock_ja,stock_a,stock_b,stock_x1)) 
        return 1;
    }  

  if (cycle == 1)
  {
      if (w_cycle(mc,iteration,nc,mc/2,depth,level+1,stock_ia,stock_ja,stock_a,stock_b,stock_x1)) 
        return 1;


     if (w_cycle(mc,iteration,nc,mc/2,depth,level+1,stock_ia,stock_ja,stock_a,stock_b,stock_x1)) 
        return 1;
  }
    
    free((stock_ja)[level+1]);free((stock_ia)[level+1]);
    

  }
//---------------------------------------------------------------------------------------
/*prolongation part*/

  /*we solve PUC = Px1c*/
if (prolongation(m,n,&PUC,(stock_x1)[level+1])) 
    return 1;


    
   
/*new solution vector with error term from PUC*/
if (Coarse_grid_correction(n,&((stock_x1)[level]),PUC)) 
      return 1;
  

   free(PUC);free(Residu);free(p);


//-------------------------------------------------------------------------------------------
/*Post-smoothing part*/
 for (int i = 0; i < 1; ++i)
{
   if (er(m,n,(stock_ia)[level], (stock_ja)[level], (stock_a)[level], (stock_b)[level],(stock_x1)[level],&Br)) 
    return 1;

  

  if (Bresidue(m,n,&((stock_x1)[level]),Br)) 
    return 1;

}

//-----------------------------------------------------------------------------------------------------------


*x1 = (stock_x1)[level];
free((stock_x1));free(stock_b);free(stock_ia);free(stock_ja);free(stock_a);

 } 







  
return 0;

}
