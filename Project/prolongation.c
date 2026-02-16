#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int prolongation(int m,int n,double **PUC,double *x)

{

    int nnz, nnz2 , nnz3,ix,iy,ind,index,t;

    double res;

    
    nnz2 = 0.5*(10*(m/11)-1);  
    nnz3 = 0.5*(5*(m/11)-1); 
   

    
     
    *PUC = calloc((n),sizeof(double));



    nnz = 0; 
    ind = 0; 
    index = 0;
    t = 0;
    res = 0.0;




           for (iy = 1 ; iy < (m/11)*7-1   ; iy++) {
             for (ix = 1; ix <= m-(m/11)-1; ix++)  {
			    

            if (ix == 1 && iy == 1) // vert
            {
                res = 0.25*(x)[index]; 
                nnz++; 
            }

            else if (ix == m-(m/11)-1 && iy == 1) // mauve
            {
                res = 0.25*(x)[index];
                nnz++; 
            }

            else if (ix % 2 == 0 && iy == 1) // orange
            {
                res = 0.5*(x)[index];
                 
            }

            else if (ix % 2 != 0 && iy == 1 ) // bleu turquoise 
            {
                 res += 0.25*(x)[index];
                 //printf("%d and %d\n", nnz , index );
                 
                 index++;
                 res += 0.25*(x)[index];
                



            }

            else if (ix == 1 && iy % 2 == 0) // vert clair 
            {   
                
                res = 0.5*(x)[index];
                 
            }
            else if (ix == 1 && iy % 2 != 0) // noir 
            {   
                
                res += 0.25*(x)[index];
                
                res += 0.25*(x)[index + nnz2];
                t = index + nnz2;
                

            }

            else if (ix == m-(m/11)-1 && iy % 2 != 0) // rose
            {
                res += 0.25*(x)[index];
                 
                res += 0.25*(x)[index+nnz2];
               
            }


            else if (ix % 2 != 0 && iy % 2 != 0 ) // jaune 
            {
                res += 0.25*(x)[index];
                index++;
                
                res += 0.25*(x)[index];
                 
                 res += 0.25*(x)[index + nnz2 - 1];
                 
                res += 0.25*(x)[index + nnz2];
                 
            }

            else if (ix % 2 == 0 && iy % 2 != 0) // vert clair clare 
            {   
             
                res += 0.5*(x)[index];
                
                res += 0.5*(x)[index + nnz2];
                
            }
            else if (iy % 2 == 0 && ix == m-(m/11)-1)
            {
                res = 0.5*(x)[index];
                
            }

            else if (iy % 2 == 0 && ix % 2 != 0 )
            {
                res += 0.5*(x)[index];
                index++;
                
                res += 0.5*(x)[index];
               
            }
            else if (iy % 2 == 0 && ix % 2 == 0 )
            {
                res = 1.0*(x)[index];
                
            }
        
        (*PUC)[ind] = res;
        ind++;
        res = 0.0;
         }

        index = t;

          } 


     



          

          for (iy = 7*(m/11)-1 ; iy  <  7*(m/11); ++iy)
          { 
            for (ix = 1; ix <= m-(m/11)-1  ; ++ix)
            {
                
                if (ix == 1 && iy % 2 == 0)
            {
                res = 0.5*(x)[index];
               
            }

             else if (ix == 1 && iy % 2 != 0)
            {
                res += 0.25*(x)[index];
             
                res += 0.25*(x)[index + nnz2];
                t = index + nnz2;
                

            }             


             else if (ix >= 5*(m/11)-1 && iy % 2 == 0)
            {
                if (ix == m-(m/11)-1)
                {
                     res = 0.5*(x)[index];
                     
                }

                else if (ix % 2 != 0 )
            {
                 res += 0.5*(x)[index]; 
                index++;
             
                 res += 0.5*(x)[index];
                 
            }

            else if (ix % 2 == 0) 
            {
                 res = 1.0*(x)[index];
                
            }

            }
            
            else if (ix == 5*(m/11)-1 && iy % 2 != 0)
            {


                if ( ix % 2 != 0 )
            {
                 res += 0.25*(x)[index];
                index++; 
                
                 res += 0.25*(x)[index];
                
                 res += 0.25*(x)[index - 1 + nnz2];
                
            }
               else if ( ix % 2 == 0 )
               {
                  res += 0.5*(x)[index];
               
                  res += 0.5*(x)[index + nnz2];
                 
               }
            }



            else if (ix > 5*(m/11)-1 && iy % 2 != 0)
            {

                if (ix == m-(m/11)-1)
            {
                 res = 0.25*(x)[index];
            }

                else if ( ix % 2 != 0 )
            {
                res += 0.25*(x)[index];
                index++;
                res += 0.25*(x)[index];
            }
               else if ( ix % 2 == 0 )
               {
                 res = 0.5*(x)[index];
                 nnz++;
               }
            }


            else if (ix % 2 != 0 && iy % 2 != 0 )
            {
                res += 0.25*(x)[index];
                index++;
                 nnz++;
                res += 0.25*(x)[index];
                 nnz++;
                 res += 0.25*(x)[index + nnz2 - 1];
                 nnz++;
                res += 0.25*(x)[index + nnz2];
                 nnz++;
            }

            else if (ix % 2 == 0 && iy % 2 != 0)
            {
                res += 0.5*(x)[index]; 
                 nnz++;
                res += 0.5*(x)[index + nnz2];
                 nnz++;
            }

            else if (iy % 2 == 0 && ix % 2 != 0 )
            {
                res += 0.5*(x)[index];
                index++;
                nnz++;
                res += 0.5*(x)[index];
                nnz++;
            }
            else if (iy % 2 == 0 && ix % 2 == 0 )
            {
                res = 1.0*(x)[index];
                nnz++;
            }
             

             (*PUC)[ind] = res;
             ind++;
             res =0.0;
         }

             

             index = t;

             
              

          }


          
            for (iy = 7*(m/11) ; iy <= m-(m/11)-1 ; iy++) {
              for (ix = 1; ix <= 5*(m/11)-1; ix++) {
			
			
            /* numéro de l'équation*/ 
            
        



             if (ix == 1 && iy == m-(m/11)-1 && iy % 2 != 0)
            {
                res =  0.25*(x)[index];
                nnz++;

            }


            else if (ix == 5*(m/11)-1 && iy == m-(m/11)-1 && iy % 2 != 0 && m % 2 == 0)
            {
                res =  0.25*(x)[index];
                nnz++;

            }



            else if (ix == 5*(m/11)-1 && iy == m-(m/11)-1 && iy % 2 != 0)
            {
                res =  0.5*(x)[index];
                nnz++;

            }

            else if (ix % 2 == 0 && iy == m-(m/11)-1 && iy % 2 != 0)
            {
                res =  0.5*(x)[index];
                nnz++;

            }

            else if (ix % 2 != 0 && iy == m-(m/11)-1 && iy % 2 != 0)
            {
                res +=  0.25*(x)[index];
                index++;
                nnz++;
                res += 0.25*(x)[index];
                nnz++;

                
            }


            else if (ix == 1 && iy % 2 == 0)
            {
                res = 0.5*(x)[index]; 
                nnz++; 
            }

            else if (ix == 1 && iy % 2 != 0 && iy == 7*(m/11))
            {   
                res += 0.25*(x)[index]; 
                nnz++;
                res += 0.25*(x)[index + nnz2];
                nnz++;
                t = index + nnz2;
                //printf("%d\n", nnz );

            }

            else if (ix == 1 && iy % 2 != 0 )
            {  
                res += 0.25*(x)[index]; 
                nnz++;
                res += 0.25*(x)[index + nnz3]; 
                nnz++;
                t = index + nnz3;
                //printf("%d\n", nnz );

            }

            else if (ix == 5*(m/11)-1 && iy % 2 == 0 && m % 2 != 0)
            {
                res = 1.0*(x)[index];  
                nnz++; 
            }

            else if (ix == 5*(m/11)-1 && iy % 2 == 0 )
            {
                res = 0.5*(x)[index];  
                nnz++; 
            }



            else if (ix == 5*(m/11)-1 && iy % 2 != 0 && m % 2 == 0)
            {
                res += 0.25*(x)[index]; 
                nnz++; 
                res += 0.25*(x)[index + nnz3]; 
                nnz++;
            }

            else if (ix == 5*(m/11)-1 && iy == 7*(m/11) && m % 2 != 0  )
            {
                res += 0.5*(x)[index];
                nnz++; 
                res += 0.5*(x)[index + nnz2];
                nnz++;
            }

            else if (ix % 2 != 0 && iy % 2 != 0 && m % 2 != 0 )
            {
                res += 0.25*(x)[index];
                index++;
                 nnz++;
                res += 0.25*(x)[index];
                 nnz++;
                 res += 0.25*(x)[index + nnz3 - 1];
                 nnz++;
                res += 0.25*(x)[index + nnz3];
                 nnz++;
            }

            else if (ix % 2 != 0 && iy % 2 != 0 && m % 2 != 0 )
            {
                res += 0.25*(x)[index];
                index++;
                 nnz++;
                res += 0.25*(x)[index];
                 nnz++;
                 res += 0.25*(x)[index + nnz2 - 1];
                 nnz++;
                res += 0.25*(x)[index + nnz2];
                 nnz++;
            }


            else if (ix % 2 != 0 && iy % 2 != 0 )
            {   

                res += 0.25*(x)[index];
                index++;
                 nnz++;
                res += 0.25*(x)[index];
                 nnz++;
                 res += 0.25*(x)[index + nnz3 - 1];
                 nnz++;
                res += 0.25*(x)[index + nnz3];
                 nnz++;
            }

            else if (ix % 2 == 0 && iy == 7*(m/11) && m % 2 != 0)
            {   
                //printf("%d\n", nnz );
                res += 0.5*(x)[index];
                 nnz++;
                 res += 0.5*(x)[index + nnz2];
                 nnz++;
            }

            else if (ix % 2 == 0 && iy % 2 != 0)
            {   
                //printf("%d\n", nnz );
                res += 0.5*(x)[index];
                 nnz++;
               res += 0.5*(x)[index + nnz3];
                 nnz++;
            }
            
            else if (iy % 2 == 0 && ix % 2 != 0 )
            {
                res += 0.5*(x)[index];
                index++;
                nnz++;
                res += 0.5*(x)[index];
                nnz++;
            }

            else if (iy % 2 == 0 && ix % 2 == 0 )
            {
                res += 1.0*(x)[index];
                nnz++;
            }
            

            (*PUC)[ind] = res;
             ind++;
             res =0.0;            

            }


            index = t;            
        } 

    
    
  return 0;	
}
