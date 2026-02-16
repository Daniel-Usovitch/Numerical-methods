#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Matrix_p(int m,int n,double **p,int *nc)

{

    int nnz1 , nnz2 , nnz3, nnz4,ix,iy,nnz5,elem,nnz;


    if (m % 2 != 0)
     {
         nnz1 = 0.5*(7*(m/11)-1); 
         nnz2 = 0.5*(10*(m/11)-1);  
         nnz3 = 0.5*(5*(m/11)-1); 
         nnz4 = 0.5*(3*(m/11));
         nnz5 = 0.5*(5*(m/11));
         nnz = 9*((nnz1*nnz2)+(nnz3*nnz4))-3*nnz4-3*nnz5-1;
     } 

     else 
     {
         nnz1 = 0.5*(7*(m/11)-1); 
         nnz2 = 0.5*(10*(m/11)-1);  
         nnz3 = 0.5*(5*(m/11)-1); 
         nnz4 = 0.5*(3*(m/11));
         nnz = 9*((nnz1*nnz2)+(nnz3*nnz4));
     } 

     *nc = ((nnz1*nnz2)+(nnz3*nnz4));
     
     
     *p = calloc((n),sizeof(double));


    elem = 0;

           for (iy = 1 ; iy < (m/11)*7-1   ; iy++) {
           for (ix = 1; ix <= m-(m/11)-1; ix++)  {
			    

            if (ix == 1 && iy == 1) // vert
            {
             
                (*p)[elem] = 0.25;
                 elem++;  
                 
            }

            else if (ix == m-(m/11)-1 && iy == 1) // mauve
            {
                
                (*p)[elem] = 0.25;
                elem++;
                
            }

            else if (ix % 2 == 0 && iy == 1) // orange
            {
                
                (*p)[elem] = 0.5;
                 elem++;
                
            }

            else if (ix % 2 != 0 && iy == 1 ) // bleu turquoise 
            {
                
                (*p)[elem] = 0.25;
                 elem++;
                 



            }

            else if (ix == 1 && iy % 2 == 0) // vert clair 
            {   
                
                 
                (*p)[elem] = 0.5;
                 elem++;

            }
            else if (ix == 1 && iy % 2 != 0) // noir 
            {   
                
                (*p)[elem] = 0.25;
                 elem++;
                
            }

            else if (ix == m-(m/11)-1 && iy % 2 != 0) // rose
            {
                (*p)[elem] = 0.25;
                 elem++;
            }


            else if (ix % 2 != 0 && iy % 2 != 0 ) // jaune 
            {
                (*p)[elem] = 0.25;
                 elem++;
                
                
            }

            else if (ix % 2 == 0 && iy % 2 != 0) // vert clair clare 
            {   
             
          
                (*p)[elem] = 0.5;
                 elem++;
                
            }
            else if (iy % 2 == 0 && ix == m-(m/11)-1)
            {
               
                (*p)[elem] = 0.5;
                 elem++;
               
            }

            else if (iy % 2 == 0 && ix % 2 != 0 )
            {
               
                (*p)[elem] = 0.5;
                 elem++;
                
            }
            else if (iy % 2 == 0 && ix % 2 == 0 )
            {
                
                (*p)[elem] = 1.0;
                 elem++;
                
            }

        
        }

          } 


     
          
          for (iy = 7*(m/11)-1 ; iy  <  7*(m/11); ++iy)
          { 
            for (ix = 1; ix <= m-(m/11)-1  ; ++ix)
            {

                

                
                if (ix == 1 && iy % 2 == 0)
            {
                
                (*p)[elem] = 0.5;
                 elem++;
              
            }

             else if (ix == 1 && iy % 2 != 0)
            {
               
                (*p)[elem] = 0.25;
                 elem++;
                nnz++;
                

            }             


             else if (ix >= 5*(m/11)-1 && iy % 2 == 0)
            {
                if (ix == m-(m/11)-1)
                {
                   
                    (*p)[elem] = 0.5;
                     elem++;
                    
                }

                else if (ix % 2 != 0 )
            {
                
                (*p)[elem] = 0.5;
                elem++;
               
            }

            else if (ix % 2 == 0) 
            {
                 
                (*p)[elem] = 1.0;
                 elem++;
                 
            }

            }




            
            else if (ix == 5*(m/11)-1 && iy % 2 != 0)
            {


                if ( ix % 2 != 0 )
            {
                
                (*p)[elem] = 0.25;
                 elem++;
                
            }
               else if ( ix % 2 == 0 )
               {
                 
                 (*p)[elem] = 0.5;
                 elem++;
                 
               }
            }



            else if (ix > 5*(m/11)-1 && iy % 2 != 0)
            {

                if (ix == m-(m/11)-1)
            {
                
                (*p)[elem] = 0.25;
                 elem++;
               
            }

                else if ( ix % 2 != 0 )
            {
                
                (*p)[elem] = 0.25;
                 elem++;
                
            }
               else if ( ix % 2 == 0 )
               {
                
                 (*p)[elem] = 0.5;
                 elem++; 
                 
               }
            }


            else if (ix % 2 != 0 && iy % 2 != 0 )
            {
                
                (*p)[elem] = 0.25;
                 elem++;
                
            }

            else if (ix % 2 == 0 && iy % 2 != 0)
            {
                
                (*p)[elem] = 0.5;
                 elem++; 
                
            }

            else if (iy % 2 == 0 && ix % 2 != 0 )
            {
            
                (*p)[elem] = 0.5;
                 elem++;
               
            }
            else if (iy % 2 == 0 && ix % 2 == 0 )
            {
                
                (*p)[elem] = 1.0;
                 elem++;
                
            }
             
            
         }
 

          }


          
            for (iy = 7*(m/11) ; iy <= m-(m/11)-1 ; iy++) {
              for (ix = 1; ix <= 5*(m/11)-1; ix++) {
			
	

             if (ix == 1 && iy == m-(m/11)-1 && iy % 2 != 0)
            {
                
                (*p)[elem] = 0.25;
                 elem++;
                

            }


            else if (ix == 5*(m/11)-1 && iy == m-(m/11)-1 && iy % 2 != 0 && m % 2 == 0)
            {
                
                (*p)[elem] = 0.25;
                 elem++;
            }



            else if (ix == 5*(m/11)-1 && iy == m-(m/11)-1 && iy % 2 != 0)
            {
               
                (*p)[elem] = 0.25;
                 elem++;
               

            }

            else if (ix % 2 == 0 && iy == m-(m/11)-1 && iy % 2 != 0)
            {
                
                (*p)[elem] = 0.5;
                 elem++; 
                

            }

            else if (ix % 2 != 0 && iy == m-(m/11)-1 && iy % 2 != 0)
            {
                
                (*p)[elem] = 0.25;
                 elem++;
                

                
            }


            else if (ix == 1 && iy % 2 == 0)
            {
                 
                (*p)[elem] = 0.5;
                 elem++;
                
            }

            else if (ix == 1 && iy % 2 != 0 && iy == 7*(m/11))
            {   
                
                (*p)[elem] = 0.25;
                 elem++; 
               

            }

            else if (ix == 1 && iy % 2 != 0 )
            {  
                
                (*p)[elem] = 0.25;
                 elem++;
                

            }

            else if (ix == 5*(m/11)-1 && iy % 2 == 0 && m % 2 != 0)
            {
                
                (*p)[elem] = 1.0;
                 elem++; 
                
            }

            else if (ix == 5*(m/11)-1 && iy % 2 == 0 )
            {
                
                (*p)[elem] = 0.5;
                 elem++;
                
            }



            else if (ix == 5*(m/11)-1 && iy % 2 != 0 && m % 2 == 0)
            {
                
                (*p)[elem] = 0.25;
                 elem++;
               
            }

            else if (ix == 5*(m/11)-1 && iy == 7*(m/11) && m % 2 != 0  )
            {
                
                (*p)[elem] = 0.5;
                 elem++;
                
            }

            else if (ix % 2 != 0 && iy % 2 != 0 && m % 2 != 0 )
            {
               
                (*p)[elem] = 0.25;
                 elem++;
                
            }

            else if (ix % 2 != 0 && iy % 2 != 0 && m % 2 != 0 )
            {
               
                (*p)[elem] = 0.25;
                 elem++;
                
            }


            else if (ix % 2 != 0 && iy % 2 != 0 )
            {   

                
                (*p)[elem] = 0.25;
                 elem++;
               
            }

            else if (ix % 2 == 0 && iy == 7*(m/11) && m % 2 != 0)
            {   
                
                (*p)[elem] = 0.5;
                 elem++;
                 
            }

            else if (ix % 2 == 0 && iy % 2 != 0)
            {   
               
                (*p)[elem] = 0.5;
                 elem++;
                 
            }
            
            else if (iy % 2 == 0 && ix % 2 != 0 )
            {
                
                (*p)[elem] = 0.5;
                 elem++;
                
            }

            else if (iy % 2 == 0 && ix % 2 == 0 )
            {
                
                (*p)[elem] = 1.0;
                 elem++;
               
            }


            }


        } 
    
     
  return 0;	
}
