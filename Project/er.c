#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "umfpk.h"


int er(int m,int n,int *ia, int *ja, double *a,double *b,double *x,double **Br) {


    int index;
    int p,o,ai;
    double *LAsolution,LAii,UAii,resultat,sol,*DUAresidu,*rk,residualb;
    rk = calloc((n),sizeof(double));
    int invh2 = (m-(m/11))*(m-(m/11))/(5*5);
    

    
    
    for (int i = 0; i < (n); ++i)
    {   residualb = 0.0;
        for (int j = (ia)[i]; j < (ia)[i+1]; ++j)
        {
            index = (ja)[j];
            residualb =  residualb +  (a)[j]*(x)[index];


        }

        (rk)[i] = (b)[i] - residualb ;
        
    }

   
   resultat = 0.0;

   LAsolution = calloc((n),sizeof(double));

    for( p= 0; p < (n) ; p++) {  

        for(o= (ia)[p] ; o < (ia)[p+1];o++){ 
           
           ai = (ja)[o]; 

            if(p == 0){
                LAii = (a)[p]; 
    
                (LAsolution)[p]= ((rk)[p])/(LAii); //ok

                
               
                            
            }



            else if (ai < p ){ 

                  resultat = resultat + (a)[o]*(LAsolution)[ai]; 
                  

                                          }
  

            else if (ai == p){

                LAii = (a)[o];  

                double elementofI = (rk)[p]; 

                sol = (elementofI-resultat)/(LAii);
                (LAsolution)[p] = sol;
                
                         
         }

         

         }



         resultat = 0.0;

         

         }
    
    free(rk);
    DUAresidu = calloc((n),sizeof(double));

    for (int i = 0; i < (n); ++i)
    {
        (DUAresidu)[i] = 4.0*invh2*(LAsolution)[i];
    }
        
    free(LAsolution);

    

    

        ai = 0;
        resultat = 0.0;
        *Br = calloc((n),sizeof(double));


        for(p = (n)-1 ; p >= 0 ; p--) {  

           for(o = (ia)[p+1] - 1 ; o >= (ia)[p];o--){ 
            
            ai = (ja)[o];
    
            if(ai == (n)-1 ){ 
                UAii = (a)[o];
                (*Br)[p]= ((DUAresidu)[p])/(UAii);
                //printf("%f\n", (*Br)[p] );
                
                            
            } 



            else if (ai > p){ 

                  resultat = resultat + (a)[o]*(*Br)[ai];
                  
                                          }
  

                else if (ai == p){

                UAii = (a)[o]; 

                double elementofI = (DUAresidu)[p]; 

                sol = (elementofI-resultat)/(UAii);
                (*Br)[p] = sol;

                

                  
          }         
         }


         resultat = 0.0;

         


          
       } 
       

    free(DUAresidu);


     return 0;

}







