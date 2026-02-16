#include <stdio.h>
#include <stdlib.h>
#include "umfpk.h"
#include "time.h"
#include <math.h>
#include "multigrid.h"



int Conjugate_gradiant(int m,int iteration,int n,int mc,int depth,int level,int *ia,int *ja,double *a,double *b,double **u,int cycle)
{

   double *r,*d,*B_r,betam_d,betam,betam_n,*A_d,alpham_d,alpham_n,res,norm_r,alpham;
   

  

   r = calloc((n),sizeof(double));
   d = calloc((n),sizeof(double));
   


for (int i = 0; i < (n); ++i)
{
   (r)[i] = (b)[i]; 
}
    
   betam_d = 0;


   

for (int i = 0; i < iteration ; ++i)
{
    A_d = calloc((n), sizeof(double));
    B_r = calloc((n),sizeof(double));
 



  if (multigrid(m,1,n,mc,depth,level,ia,ja,a,r,&B_r,cycle)) 
    return 1;

 
   
   betam_n = 0;

   for (int i = 0; i < (n); ++i)
   {
      betam_n = betam_n + (r)[i]*(B_r)[i];

   }
   
   

   if (i == 0)
   {
      betam = 0;
   }

   else{

      betam = betam_n/betam_d;
   }

  

   betam_d = betam_n;

   for (int k = 0; k < (n); ++k)
   {
      (d)[k] = (B_r)[k] + betam*(d)[k];

   }



   free(B_r);



   for(int i = 0 ; i < (n);i++){
        res = 0;
        for(int j = (ia)[i] ; j < (ia)[i+1]; j++){
           res += ((a)[j])*((d)[(ja)[j]]); 
           } 
            
            (A_d)[i] = res;
           }  

   alpham_n = betam_n;
   alpham_d = 0;
   for (int i = 0; i < (n); ++i)
   {
      alpham_d = alpham_d + (d)[i]*(A_d)[i];

    }





   
      for (int h = 0; h < (n); ++h)
         {
            alpham = alpham_n/alpham_d;
         }
   
      
   

   for (int i = 0; i < (n); ++i)
   {
      (*u)[i] = (*u)[i] + alpham*(d)[i];
        
   }

   


   for (int i = 0; i < (n); ++i)
   {  
      if (alpham_d == 0)
      {
         (r)[i] = (r)[i];
         
      }
      else{

         (r)[i] = (r)[i] - alpham*(A_d)[i];
           

      }


      
   }

   free(A_d);
   
}



norm_r = 0;
for (int i = 0; i < (n); ++i)
{
   norm_r += (r)[i]*(r)[i];
}


printf("the norm of rersidual is egal %f\n", sqrt(norm_r) );
free(r);free(d);


  
return 0;

}