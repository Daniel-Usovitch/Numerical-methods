#include <stdio.h>
#include <stdlib.h>
#include "umfpk.h"
#include "time.h"
#include <math.h>
#include "Prob.h"
#include "graphique.h"
#include "residu.h"
#include "residual.h"
#include "multigrid.h"
#include "two_grid.h"
#include "Conjugate_gradiant.h"

int main(int argc, char *argv[])
{


/*it is here where the heart of this program. 
the goal of this project is to solve the linear system AX = b with different methods: 
two grid, multigrid and the gradiant conjugate with multigrid as preconditionner. 
Naturally, we could claim that the preconditionner B is egal to A. Hence, it is easy to solve Bx = r with multigrid method. 
*/


  int m,mc,method,cycle,iteration,plotting;
  int n,*ia, *ja,level; 
  double *a, *b,*Residu,*x1,Resultat;
  /*parameter for different method*/
  //-----------------------

  int depth = 6; /*here, you can select the depth but be carefully about the choice of m.*/
  m = 11*pow(2,depth+1);
  mc = m/2; /*it is the new m for the coarse grid correction*/
  method = 0; /*here, you can select methods. 0 for two grid method, 1 for the multigrid method and 2 for the conjugate gradient*/
  level = 0; /*it is the level for the multigrid method*/
  iteration = 6; /*it is the number of iteration for the main cycle for each methods*/
  cycle = 1; /*you can select the cycle : 0 for v_cycle and 1 for W_cycle*/

  //------------------------

  /*to activate graph or plotting*/
  int graph = 0; /* if you want to view the graph, select 1.*/
  plotting = 0; /*to select the create a file.csv(1) or not(0)*/
  double tc1, tc2, tw1, tw2; 
 
if (plotting == 0)
{
  


  if (Prob(m,&n, &ia, &ja, &a, &b)) 
        return 1;
  printf("\nPROBLEM: ");
  printf("m = %5d   n = %8d  nnz = %9d\n", m, n, ia[n] );
 

  tc1 = mytimer_cpu(); tw1 = mytimer_wall();

  x1 = calloc(n,sizeof(double));  
 //----------------------------------------------------------------- 


if (method == 0)
{

 /*the function two-grid contains variables as iteration (nb of iteration for the main cycle), mc (m/2 for coarse grid correction)*/
 if (two_grid(m,iteration,n,mc,ia,ja,a,b,x1)) 
    return 1;

}


//--------------------------------------------------------------------

if (method == 1)
{

    /*same as the two_grid function expect that there are 2 more variables as level(level for recursively),depth(where m is minimum) and cycle(select either v-cycle or w-cycle) */
if (multigrid(m,iteration,n,mc,depth,level,ia,ja,a,b,&x1,cycle)) 
    return 1;

}


//----------------------------------------------------------------
if (method == 2)
{
    /*same as multigrid function*/
if (Conjugate_gradiant(m,iteration,n,mc,depth,level,ia,ja,a,b,&x1,cycle)) 
    return 1;
}

//----------------------------------------------------------------- 

/*the function calculate b-AX*/
if (residual(m,n,ia,ja,a,b,x1,&Residu)) 
    return 1;



/*the function gives the residual norm*/      
if (residu(m, &n, &ia, &ja, &a, &b,&Residu,&Resultat)) 
        return 1;

    tc2 = mytimer_cpu(); tw2 = mytimer_wall(); /* mis à jour le 13/10/22 */
    printf("\nTemps de solution (CPU): %5.1f sec",tc2-tc1); /* mis à jour le 13/10/22 */
    printf("\nTemps de solution (horloge): %5.1f sec \n",tw2-tw1); /* mis à jour le 13/10/22 */

if (graph == 1)
{
    if(graphique(m,&n,&x1)) 
      return 1;
}



                       

  free(ia);free(ja);free(a);free(b);free(x1);free(Residu);

}




/*here, the file.csv is created for storing the data*/
//__________________________________________________________________________________________________________________________


if (plotting == 1)
{
    
FILE *fpt;

fpt = fopen("CGWCYCLE.csv", "w+");


  for (int i = 1; i < iteration + 1; ++i)
  {


    

    if (Prob(m,&n, &ia, &ja, &a, &b)) 
        return 1;
  printf("\nPROBLEM: ");
  printf("m = %5d   n = %8d  nnz = %9d\n", m, n, ia[n] );
 

  tc1 = mytimer_cpu(); tw1 = mytimer_wall();   
  x1 = calloc(n, sizeof(double));  
 //----------------------------------------------------------------- 


if (method == 0)
{

 /*the function two-grid contains variables as iteration (nb of iteration for the main cycle), mc (m/2 for coarse grid correction)*/
 if (two_grid(m,i,n,mc,ia,ja,a,b,x1)) 
    return 1;


}


//--------------------------------------------------------------------

if (method == 1)
{

    /*same as the two_grid function expect that there are 2 more variables as level(level for recursively),depth(where m is minimum) and cycle(select either v-cycle or w-cycle) */
if (multigrid(m,i,n,mc,depth,level,ia,ja,a,b,&x1,cycle)) 
    return 1;
}




//----------------------------------------------------------------
if (method == 2)
{
    /*same as multigrid function*/
if (Conjugate_gradiant(m,i,n,mc,depth,level,ia,ja,a,b,&x1,cycle)) 
    return 1;
}

//----------------------------------------------------------------- 

/*the function calculate b-AX*/
if (residual(m,n,ia,ja,a,b,x1,&Residu)) 
    return 1;



/*the function gives the residual norm*/      
if (residu(m, &n, &ia, &ja, &a, &b,&Residu,&Resultat)) 
        return 1;

fprintf(fpt,"%d, %E\n", i, Resultat);

    tc2 = mytimer_cpu(); tw2 = mytimer_wall(); /* mis à jour le 13/10/22 */
    printf("\nTemps de solution (CPU): %5.1f sec",tc2-tc1); /* mis à jour le 13/10/22 */
    printf("\nTemps de solution (horloge): %5.1f sec \n",tw2-tw1); /* mis à jour le 13/10/22 */

if (graph == 1)
{
    if(graphique(m,&n,&x1)) 
      return 1;
}



                       

  free(ia);free(ja);free(a);free(b);free(x1);free(Residu);
  }

fclose(fpt);
}





}

