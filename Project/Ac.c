#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Ac(int mc,int *nc, int **iac, int **jac, double **ac)

{
    
    int m = mc;
	
	/* meme principe que le fichier prob.c mais juste ici c'est un cas generale */
    

    int  nnz, ix, iy,ind;
    double invh2;

    if(m <= 11) {
        printf("\n ERREUR : m = %d n'est pas une valeur valide\n\n",m);
        return 1;
    }
    invh2 = (m-(m/11))*(m-(m/11))/(5*5); /* h^-2 pour L=5 */
    *nc  = ((10*(m/11)-1)*(7*(m/11)-1)+((3*(m/11))*(5*(m/11)-1))); /* nombre d'inconnues et aussi nombre d'équations */
    nnz = 5*(*nc)-2*(3*(m/11)-1)-2*(5*(m/11)-1)-2*(8*(m/11)-1)-10;  /* nombre d'éléments non nuls */
    

      
    
   

    *jac  = malloc(nnz*sizeof(int));

    *iac  = malloc((*nc+1)*sizeof(int));

    *ac   = malloc(nnz*sizeof(double));

   



   
    

    /* allocation réussite? */

    if (*iac == NULL || *jac == NULL || *ac == NULL) {
        printf("\n ERREUR : pas assez de mémoire pour générer le système\n\n");
        return 1;
    }

    /* partie principale : remplissage de la matrice */

    nnz = 0; 
    ind = 0; 
    ix = 0;
    iy = 0;

 
   
    

        
    
       for (iy = 1 ; iy <= (m/11)*7-1   ; iy++) {
           for (ix = 1; ix <= m-(m/11)-1; ix++)  {
			
          
            
            /* marquer le début de la ligne suivante dans le tableau 'ia' */
            (*iac)[ind] = nnz;
           
            
            /* calculer le membre de droite */
            if (ix == 1 && iy == 1) {
             //(*bc)[ind] = 0.0; 
                }
            

            else if( ix == m-(m/11)-1 &&  iy == 1){
                    //(*bc)[ind] = 0.0; 
                    
                    } 

            else if( ix == m-(m/11)-1 && iy == (m/11)*7-1 ){
                    //(*bc)[ind] = 0.0;
                    
                    } 
   
            
   
            /* remplissage de la ligne : voisin sud */ 
             
             if( ix > 1 && ix < 10*(m/11)-1  && iy == 1){
                //(*bc)[ind] = invh2*sin(ix*h); 
                
				    }
                                       
             else if( ix >= 1 && ix <= 10*(m/11)-1 && iy > 1){
				    (*ac)[nnz] = -invh2;
                    (*jac)[nnz] = ind - (10*(m/11)-1);
                    nnz++;}

            /* remplissage de la ligne : voisin ouest */ 
            
                if(ix == 1 && iy > 1){
			    //(*bc)[ind] = invh2*sin(h*iy); 
                
                }
                
                else if (ix > 1) {    
                (*ac)[nnz] = -invh2; 
                (*jac)[nnz] = ind - 1;
                
                nnz++; 
                } 
             
            /* remplissage de la ligne : élément diagonal */ 
            (*ac)[nnz] = 4.0*invh2;
            (*jac)[nnz] = ind;
            nnz++;
            

            /* remplissage de la ligne : voisin est */ 
             if(ix == m-(m/11)-1 && iy > 1 && iy < (m/11)*7-1){
                //(*bc)[ind] = invh2*sin(sqrt((h*iy)*(h*iy)+(h*ix+h)*(h*ix+h)));
                
				 }
             else if (ix >= 1 && ix < m-(m/11)-1 && iy >= 1 && iy <= (m/11)*7-1 )  { 
                (*ac)[nnz] = -invh2;
                (*jac)[nnz] = ind + 1;
                
                nnz++;
            } 

            /* remplissage de la ligne : voisin nord */ 
            if( ix  >= 5*(m/11) && ix < 10*(m/11)-1 && iy == (m/11)*7-1 ) { 
				//(*bc)[ind] = invh2*sin(h*sqrt(ix2+(iy+1)*(iy+1)));
	             } 
	        else if (ix >= 1 && ix < 5*(m/11)  && iy == (m/11)*7-1 ){
					 (*ac)[nnz] = -invh2;
				     (*jac)[nnz] = ind + (10*(m/11)-1);
				     
				     nnz++ ; } 

            else if (ix >= 1 && iy >= 1 ){
                     (*ac)[nnz] = -invh2;
                     (*jac)[nnz] = ind + (10*(m/11)-1);
                     
                     nnz++ ; }


            

              


            
        
        ind++;}



        
        
           
             
        
          } 


          
          
           for (iy = 7*(m/11) ; iy <= m-(m/11)-1 ; iy++) {
              for (ix = 1; ix <= 5*(m/11)-1; ix++) {
			

			
            /* numéro de l'équation */
            
            (*iac)[ind] = nnz;
           
            /* calculer le membre de droite */
            

            if (iy == m-(m/11)-1 && ix == 1) { 

                //(*bc)[ind] = invh2*sin(sqrt((ix*h)*(ix*h)+(iy*h+h)*(iy*h+h))) + invh2*sin(sqrt((ix*h-h)*(ix*h-h)+(iy*h)*(iy*h))); 
                } 
                
            
            if (iy == m-(m/11)-1 && ix == 5*(m/11)-1) { 

                //(*bc)[ind] = invh2*sin(sqrt((ix*h)*(ix*h)+(iy*h+h)*(iy*h+h))) + invh2*sin(sqrt((ix*h+h)*(ix*h+h)+(iy*h)*(iy*h))); 
                } 
                
            
             
            /* remplissage de la ligne : voisin sud */ 
            
            if (iy == 7*(m/11)) {              
                (*ac)[nnz] = -invh2;
                (*jac)[nnz] = ind - (10*(m/11)-1) ;
                
                nnz++;
                
                
            } 

            else if (iy > 7*(m/11) ) { 
                (*ac)[nnz] = -invh2; 
                (*jac)[nnz] = ind - (5*(m/11)-1);
                
                nnz++;
            } 
            

            /* remplissage de la ligne : voisin ouest */ 
            
            if (ix == 1 && iy < m-(m/11)-1) {    
                //(*bc)[ind] = invh2*sin(sqrt((ix*h-h)*(ix*h-h)+(iy*h)*(iy*h)));
                
            }  
            

            else if (ix > 1) { 
                (*ac)[nnz] = -invh2; 
                (*jac)[nnz] = ind - 1;
              
                nnz++;
                
            } 

            /* remplissage de la ligne : élément diagonal */ 
            (*ac)[nnz] = 4.0*invh2;
            (*jac)[nnz] = ind;
            
            nnz++;

            /* remplissage de la ligne : voisin est */ 
            if (ix == 5*(m/11)-1 && iy < m-(m/11)-1 ) { 
                //(*bc)[ind] = invh2*sin(sqrt((ix*h+h)*(ix*h+h)+(iy*h)*(iy*h))); 
                
               
            } 

            else if(ix >=1 && ix < 5*(m/11)-1) {
				(*ac)[nnz] = -invh2;
                (*jac)[nnz] = ind + 1;
               
                nnz++;  
                }

            /* remplissage de la ligne : voisin nord */
              if (iy < m-(m/11)-1 && ix >= 1){          
                (*ac)[nnz] = -invh2; 
                (*jac)[nnz] = ind + (5*(m/11)-1) ;
                nnz++; 
                }

            else if (iy == m-(m/11)-1 && ix > 1 && ix < 5*(m/11)-1){



            //(*bc)[ind] = invh2*sin(sqrt((ix*h)*(ix*h)+(iy*h+h)*(iy*h+h)));
                
              
            }


            ind++;
            
            

            }



            
        }

     


    
    
    
    /* dernier élément du tableau 'ia' */
    (*iac)[ind] = nnz;

    
    
     
  return 0;	
}
