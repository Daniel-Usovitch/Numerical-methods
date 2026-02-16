#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Prob(int m,int *n, int **ia, int **ja, double **a, double **b)

{
	
	/* meme principe que le fichier prob.c mais juste ici c'est un cas generale */
    int  nnz, ix, iy, ix2, iy2,ind;
    double invh2, h = (5.0)/(m-(m/11));

    if(m <= 1) {
        printf("\n ERREUR : m = %d n'est pas une valeur valide\n\n",m);
        return 1;
    }
    invh2 = (m-(m/11))*(m-(m/11))/(5*5); /* h^-2 pour L=5 */
    *n  = ((10*(m/11)-1)*(7*(m/11)-1)+((3*(m/11))*(5*(m/11)-1))); /* nombre d'inconnues et aussi nombre d'équations */
    nnz = 5*(*n) - (10*(m/11)-1) - 2*(7*(m/11)-1)-(5*(m/11))-2*(3*(m/11))-(5*(m/11)-1)+1;  /* nombre d'éléments non nuls */
    
     printf("%d\n", nnz );
    
      
      
    *ia  = malloc((*n+1)* sizeof(int));
    *ja  = malloc((nnz) * sizeof(int));
    *a   = malloc((nnz) * sizeof(double));
    *b   = malloc((*n)*sizeof(double));



   
    

    /* allocation réussite? */

    if (*ia == NULL || *ja == NULL || *a == NULL || *b == NULL) {
        printf("\n ERREUR : pas assez de mémoire pour générer le système\n\n");
        return 1;
    }

    /* partie principale : remplissage de la matrice */

    nnz = 0; 
    ind = 0; 


        
    
       for (iy = 1 ; iy <= (m/11)*7-1   ; iy++) {
           for (ix = 1; ix <= m-(m/11)-1; ix++)  {

            ix2 = ix*ix;
            iy2 = iy*iy;
			
            
            /* marquer le début de la ligne suivante dans le tableau 'ia' */
            (*ia)[ind] = nnz;
           
            
            /* calculer le membre de droite */
            if (ix == 1 && iy == 1) {
            (*b)[ind] = 2*invh2*sin(h); }
            

            else if( ix == m-(m/11)-1 &&  iy == 1){
                    (*b)[ind] = invh2*sin(sqrt((h*ix+h)*(h*ix+h)+h)) + invh2*sin(sqrt((ix*h)*(ix*h)+(iy*h-h)*(iy*h-h))); 
                    
                    } 

            else if( ix == m-(m/11)-1 && iy == (m/11)*7-1 ){
                    (*b)[ind] = invh2*sin(sqrt((h*ix+h)*(h*ix+h)+iy2*h*h)) + invh2*sin(sqrt((ix*h)*(ix*h)+(iy*h+h)*(iy*h+h)));
                    
                    } 
   
            
   
            /* remplissage de la ligne : voisin sud */ 
             
             if( ix > 1 && ix < 10*(m/11)-1  && iy == 1){
                (*b)[ind] = invh2*sin(ix*h); 
                
				    }
                                       
             else if( ix >= 1 && ix <= 10*(m/11)-1 && iy > 1){
				    (*a)[nnz] = -invh2;
                    (*ja)[nnz] = ind - (10*(m/11)-1);
                    nnz++;}

            /* remplissage de la ligne : voisin ouest */ 
            
                if(ix == 1 && iy > 1){
			    (*b)[ind] = invh2*sin(h*iy); 
                
                }
                
                else if (ix > 1) {    
                (*a)[nnz] = -invh2; 
                (*ja)[nnz] = ind - 1;
                
                nnz++; 
                } 
             
            /* remplissage de la ligne : élément diagonal */ 
            (*a)[nnz] = 4.0*invh2;
            (*ja)[nnz] = ind;
            nnz++;
            

            /* remplissage de la ligne : voisin est */ 
             if(ix == m-(m/11)-1 && iy > 1 && iy < (m/11)*7-1){
                (*b)[ind] = invh2*sin(sqrt((h*iy)*(h*iy)+(h*ix+h)*(h*ix+h)));
                
				 }
             else if (ix >= 1 && ix < m-(m/11)-1 && iy >= 1 && iy <= (m/11)*7-1 )  { 
                (*a)[nnz] = -invh2;
                (*ja)[nnz] = ind + 1;
                
                nnz++;
            } 

            /* remplissage de la ligne : voisin nord */ 
            if( ix  >= 5*(m/11) && ix < 10*(m/11)-1 && iy == (m/11)*7-1 ) { 
				(*b)[ind] = invh2*sin(h*sqrt(ix2+(iy+1)*(iy+1)));
	             } 
	        else if (ix >= 1 && ix < 5*(m/11)  && iy == (m/11)*7-1 ){
					 (*a)[nnz] = -invh2;
				     (*ja)[nnz] = ind + (10*(m/11)-1);
				     
				     nnz++ ; } 

            else if (ix >= 1 && iy >= 1 ){
                     (*a)[nnz] = -invh2;
                     (*ja)[nnz] = ind + (10*(m/11)-1);
                     
                     nnz++ ; }


            

              


            
        
        ind++;}



        
        
           
             
        
          } 


          
          
           for (iy = 7*(m/11) ; iy <= m-(m/11)-1 ; iy++) {
              for (ix = 1; ix <= 5*(m/11)-1; ix++) {
			
			
			ix2 = ix*ix;
            iy2 = iy*iy;
			
            /* numéro de l'équation */
            
            (*ia)[ind] = nnz;
           
            /* calculer le membre de droite */
            

            if (iy == m-(m/11)-1 && ix == 1) { 

                (*b)[ind] = invh2*sin(sqrt((ix*h)*(ix*h)+(iy*h+h)*(iy*h+h))) + invh2*sin(sqrt((ix*h-h)*(ix*h-h)+(iy*h)*(iy*h))); } 
                
            
            if (iy == m-(m/11)-1 && ix == 5*(m/11)-1) { 

                (*b)[ind] = invh2*sin(sqrt((ix*h)*(ix*h)+(iy*h+h)*(iy*h+h))) + invh2*sin(sqrt((ix*h+h)*(ix*h+h)+(iy*h)*(iy*h))); } 
                
            
             
            /* remplissage de la ligne : voisin sud */ 
            
            if (iy == 7*(m/11)) {              
                (*a)[nnz] = -invh2;
                (*ja)[nnz] = ind - (10*(m/11)-1) ;
                
                nnz++;
                
                
            } 

            else if (iy > 7*(m/11) ) { 
                (*a)[nnz] = -invh2; 
                (*ja)[nnz] = ind - (5*(m/11)-1);
                
                nnz++;
            } 
            

            /* remplissage de la ligne : voisin ouest */ 
            
            if (ix == 1 && iy < m-(m/11)-1) {    
                (*b)[ind] = invh2*sin(sqrt((ix*h-h)*(ix*h-h)+(iy*h)*(iy*h)));
                
            }  
            

            else if (ix > 1) { 
                (*a)[nnz] = -invh2; 
                (*ja)[nnz] = ind - 1;
              
                nnz++;
                
            } 

            /* remplissage de la ligne : élément diagonal */ 
            (*a)[nnz] = 4.0*invh2;
            (*ja)[nnz] = ind;
            
            nnz++;

            /* remplissage de la ligne : voisin est */ 
            if (ix == 5*(m/11)-1 && iy < m-(m/11)-1 ) { 
                (*b)[ind] = invh2*sin(sqrt((ix*h+h)*(ix*h+h)+(iy*h)*(iy*h))); 
                
               
            } 

            else if(ix >=1 && ix < 5*(m/11)-1) {
				(*a)[nnz] = -invh2;
                (*ja)[nnz] = ind + 1;
               
                nnz++;  
                }

            /* remplissage de la ligne : voisin nord */
              if (iy < m-(m/11)-1 && ix >= 1){          
                (*a)[nnz] = -invh2; 
                (*ja)[nnz] = ind + (5*(m/11)-1) ;
                nnz++; 
                }

            else if (iy == m-(m/11)-1 && ix > 1 && ix < 5*(m/11)-1){



            (*b)[ind] = invh2*sin(sqrt((ix*h)*(ix*h)+(iy*h+h)*(iy*h+h)));
                
              
            }


            ind++;
            
            

            }



            
        }

     


    
    
    
    /* dernier élément du tableau 'ia' */
    (*ia)[ind] = nnz;
    
    
     
  return 0;	
}
