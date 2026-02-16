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



/*Here, two-grid method is used with one iteration for gauss-seidel pre-smoothing and post-smoothing*/
int two_grid(int m,int iteration,int n,int mc,int *ia,int *ja,double *a,double *b,double *x1)
{

   
  int  nnzR,nc,*iac, *jac;
  double *Br,*R,*p,*PUC,*ac,*x2,*Residu;



for ( int i = 0; i < iteration  ; ++i)
{ 


//------------------------------------------------
   /*pre-smooting part*/
for (int i = 0; i < 1; ++i)
{
   if (er(m,n,ia, ja,a, b,x1,&Br)) 
    return 1;

  

  if (Bresidue(m,n,&x1,Br)) 
    return 1;


}
 
 /*here, it is a restriction part*/
//--------------------------------------------------------------

  if (residual(m,n,ia, ja,a, b,x1,&Residu)) 
    return 1;

  
  

 if (Matrix_p(m,n,&p,&nnzR)) 
    return 1;  



if (Restriction(m,n,p,&R,Residu,nnzR)) 
   return 1; 

free(Residu);

//----------------------------------------------------------------

/*Coarse grid part */
if (Ac(mc,&nc, &iac, &jac, &ac))
        return 1;




 x2 = calloc(nc,sizeof(double)); 



          
  if( solve_umfpack(nc,iac, jac, ac, R, x2)) 
     return 1;

  
//-----------------------------------------------
   
/*prolongation part*/   
   if (prolongation(m,n,&PUC,x2)) 
    return 1;

   free(x2);
    

   
   if (Coarse_grid_correction(n,&x1,PUC)) 
      return 1;
//--------------------------------------------------
   free(p);free(PUC);
    
/*post-smoothing part*/
 for (int i = 0; i < 1; ++i)
{
   if (er(m,n,ia,ja,a,b,x1,&Br)) 
    return 1;

  

  if (Bresidue(m,n,&x1,Br)) 
    return 1;

}




} 


  
return 0;

}