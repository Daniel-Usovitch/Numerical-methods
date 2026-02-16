#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/* la fonction graphique va permettre de plot la repartition de chaleur dans la pièce */

int graphique(int m, int *n, double **x){ 
	     
	    int i,j, index; //indice i étant l'axe x et indice j étant l'axe y 
        double h; 
        h = (5.0)/(m-(m/11));
        FILE *fp = NULL ; 
        fp = fopen("data.dat" , "w") ;
        
		
		index = 0; 
		
		
		
		for(j = 0; j <= m-(m/11) ; j++){
			for(i = 0; i <= m-(m/11) ;i++){

				if(i >= 0 && j == 0 ) {
					fprintf(fp, "%f %f %f\n", i*h, j*h , sin(sqrt((i*h)*(i*h)+(j*h)*(j*h)))); /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
				}

				else if(i == 0 && j > 0) {
					fprintf(fp, "%f %f %f\n", i*h, j*h , sin(sqrt((i*h)*(i*h)+(j*h)*(j*h))) ); /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
					}

				else if(i == m-(m/11) && j <= (m/11)*7 ) {
					fprintf(fp, "%f %f %f\n", i*h, j*h ,  sin(sqrt((i*h)*(i*h)+(j*h)*(j*h)))); /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
					}

				else if(i >= 1 && i < m-(m/11) && j <= (m/11)*7-1 ) {
					fprintf(fp, "%f %f %f\n", i*h, j*h ,(*x)[index]); /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
					index++;}


				else if(i >= 1 && i < 5*(m/11) && j == (m/11)*7) {
					fprintf(fp, "%f %f %f\n", i*h, j*h ,(*x)[index]); /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
					index++;}

				else if(i >= 5*(m/11) && j == (m/11)*7) {
					fprintf(fp, "%f %f %f\n", i*h, j*h ,sin(sqrt((i*h)*(i*h)+(j*h)*(j*h))) ); /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
					}

				else if(i == 5*(m/11)  && j > (m/11)*7) {
					fprintf(fp, "%f %f %f\n", i*h, j*h , sin(sqrt((i*h)*(i*h)+(j*h)*(j*h)))); /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
					}

				else if(i >= 1 && i < 5*(m/11) && j > (m/11)*7 && j < m-(m/11)) {
					fprintf(fp, "%f %f %f\n", i*h, j*h ,(*x)[index]); /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
					index++;}

				else if(i >  5*(m/11) && j > (m/11)*7 ) {
					fprintf(fp, "%f %f %f\n", i*h, j*h , -1.00) ; /* Ici on place la fenetre à 0 degres celcius sinon on prends les valeurs de temperatures dans le vecteur solution qui a été resolu par le solveur*/
				}

				else if(i >= 0 && j == m-(m/11)){
					fprintf(fp, "%f %f %f\n", i*h, j*h , sin(sqrt((i*h)*(i*h)+(j*h)*(j*h))));
					index++;
					}	
				} 

				
			} 
		/* On place à zero degres celsius la partie de la pièce non utilisée lors de la résolution numèrique. En l'occurence dans notre configuration, la partie superieur à droite est mise à zero degrés celsius.  */
	     	
	fclose(fp); 
	
	return 0; 
}
