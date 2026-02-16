#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Restriction(int m,int n,double *p,double **R,double *Residu,int nnz)

{ 
  int ind,ix,iy;
  double SO,S,SE,O,M,E,NO,N,NE;


*R = calloc(nnz,sizeof(double));
     
     ind = 0;
     nnz = 0;


   for (iy = 1 ; iy <= (m/11)*7-1   ; iy++) {
           for (ix = 1; ix <= m-(m/11)-1; ix++)  {

            if (ix >= 1 && ix < 5*(m/11)-1  && iy == (m/11)*7-1 && (p)[ind] == 1.0){
             SO = 0.25*(p)[ind - (10*(m/11))]*(Residu)[ind - (10*(m/11))];
              S  = 0.25*(p)[ind - (10*(m/11) - 1 )]*(Residu)[ind - (10*(m/11) - 1)];
              SE = 0.25*(p)[ind - (10*(m/11) - 2 )]*(Residu)[ind - (10*(m/11) - 2)];
              O  = 0.25*(p)[ind - 1]*(Residu)[ind - 1];
              M = 0.25*(p)[ind ]*(Residu)[ind ];
              E = 0.25*(p)[ind + 1 ]*(Residu)[ind +1 ];
              NO = 0.25*(p)[ind + (10*(m/11)- 2)]*(Residu)[ind + (10*(m/11) - 2)];
              N = 0.25*(p)[ind + (10*(m/11) - 1)]*(Residu)[ind + (10*(m/11) - 1)];
              NE = 0.25*(p)[ind + (10*(m/11))]*(Residu)[ind + (10*(m/11))];
              (*R)[nnz] = SO + S + SE + O + M + E + NO + N + NE; 
              nnz++; } 

            else if (ix == 5*(m/11)-1  && iy == (m/11)*7-1 && (p)[ind] == 1.0)
            {
              SO = 0.25*(p)[ind - (10*(m/11))]*(Residu)[ind - (10*(m/11))];
              S  = 0.25*(p)[ind - (10*(m/11) - 1 )]*(Residu)[ind - (10*(m/11) - 1)];
              SE = 0.25*(p)[ind - (10*(m/11) - 2 )]*(Residu)[ind - (10*(m/11) - 2)];
              O  = 0.25*(p)[ind - 1]*(Residu)[ind - 1];
              M = 0.25*(p)[ind ]*(Residu)[ind ];
              E = 0.25*(p)[ind + 1 ]*(Residu)[ind +1 ];
              NO = 0.25*(p)[ind + (10*(m/11)- 2)]*(Residu)[ind + (10*(m/11)- 2)];
              N = 0.25*(p)[ind + (10*(m/11) - 1)]*(Residu)[ind + (10*(m/11) - 1)];
              (*R)[nnz] = SO + S + SE + O + M + E + NO + N ; 
              nnz++;
            }

            else if (ix >= 5*(m/11) && iy == (m/11)*7-1 && (p)[ind] == 1.0){
              SO = 0.25*(p)[ind - (10*(m/11))]*(Residu)[ind - (10*(m/11))];
              S  = 0.25*(p)[ind - (10*(m/11) - 1 )]*(Residu)[ind - (10*(m/11) - 1)];
              SE = 0.25*(p)[ind - (10*(m/11) - 2 )]*(Residu)[ind - (10*(m/11) - 2)];
              O  = 0.25*(p)[ind - 1]*(Residu)[ind - 1];
              M = 0.25*(p)[ind ]*(Residu)[ind ];
              E = 0.25*(p)[ind + 1 ]*(Residu)[ind +1];
              (*R)[nnz] = SO + S + SE + O + M + E ; 
              nnz++; } 


            else if ((p)[ind] == 1.0)
            {
              SO = 0.25*(p)[ind - (10*(m/11))]*(Residu)[ind - (10*(m/11))];
              S  = 0.25*(p)[ind - (10*(m/11) - 1 )]*(Residu)[ind - (10*(m/11) - 1)];
              SE = 0.25*(p)[ind - (10*(m/11) - 2 )]*(Residu)[ind - (10*(m/11) - 2)];
              O  = 0.25*(p)[ind - 1]*(Residu)[ind - 1];
              M = 0.25*(p)[ind ]*(Residu)[ind ];
              E = 0.25*(p)[ind + 1 ]*(Residu)[ind +1 ];
              NO = 0.25*(p)[ind + (10*(m/11)- 2)]*(Residu)[ind + (10*(m/11) - 2)];
              N = 0.25*(p)[ind + (10*(m/11) - 1)]*(Residu)[ind + (10*(m/11) - 1)];
              NE = 0.25*(p)[ind + (10*(m/11))]*(Residu)[ind + (10*(m/11))];
              (*R)[nnz] = SO + S + SE + O + M + E + NO + N + NE; 
              
              nnz++;

            }

            ind++;
             }

     }


     for (iy = 7*(m/11) ; iy <= m-(m/11)-1 ; iy++) {
              for (ix = 1; ix <= 5*(m/11)-1; ix++) {

              if (iy == 7*(m/11) && (p)[ind] == 1.0) { 

              SO = 0.25*(p)[ind - (10*(m/11))]*(Residu)[ind - (10*(m/11))];
              S  = 0.25*(p)[ind - (10*(m/11) - 1 )]*(Residu)[ind - (10*(m/11) - 1)];
              SE = 0.25*(p)[ind - (10*(m/11) - 2 )]*(Residu)[ind - (10*(m/11) - 2)];
              O  = 0.25*(p)[ind - 1]*(Residu)[ind - 1];
              M = 0.25*(p)[ind ]*(Residu)[ind ];
              E = 0.25*(p)[ind + 1 ]*(Residu)[ind +1 ];
              NO = 0.25*(p)[ind + (5*(m/11)-2)]*(Residu)[ind + (5*(m/11)-2)];
              N = 0.25*(p)[ind + (5*(m/11)-1)]*(Residu)[ind + (5*(m/11)-1)];
              NE = 0.25*(p)[ind + (5*(m/11))]*(Residu)[ind + (5*(m/11))];
              (*R)[nnz] = SO + S + SE + O + M + E + NO + N + NE; 
              nnz++;                  
                
            }

             else if (ix == 5*(m/11)-1 && (p)[ind] == 1.0)
             {
              SO = 0.25*(p)[ind - (5*(m/11))]*(Residu)[ind - (5*(m/11))];
              S  = 0.25*(p)[ind - (5*(m/11)-1)]*(Residu)[ind - (5*(m/11)-1)];
              O  = 0.25*(p)[ind - 1]*(Residu)[ind - 1];
              M = 0.25*(p)[ind ]*(Residu)[ind ];
              NO = 0.25*(p)[ind + (5*(m/11)-2)]*(Residu)[ind + (5*(m/11)-2)];
              N = 0.25*(p)[ind + (5*(m/11)-1)]*(Residu)[ind + (5*(m/11)-1)];
              (*R)[nnz] = SO + S  + O + M  + NO + N ; 
              nnz++;
             } 

             else if ((p)[ind] == 1.0)
             {

              SO = 0.25*(p)[ind - (5*(m/11))]*(Residu)[ind - (5*(m/11))];
              S  = 0.25*(p)[ind - (5*(m/11)-1)]*(Residu)[ind - (5*(m/11)-1)];
              SE = 0.25*(p)[ind - (5*(m/11)-2)]*(Residu)[ind - (5*(m/11)-2)];
              O  = 0.25*(p)[ind - 1]*(Residu)[ind - 1];
              M = 0.25*(p)[ind ]*(Residu)[ind ];
              E = 0.25*(p)[ind + 1 ]*(Residu)[ind +1 ];
              NO = 0.25*(p)[ind + (5*(m/11)-2)]*(Residu)[ind + (5*(m/11)-2)];
              N = 0.25*(p)[ind + (5*(m/11)-1)]*(Residu)[ind + (5*(m/11)-1)];
              NE = 0.25*(p)[ind + (5*(m/11))]*(Residu)[ind + (5*(m/11))];
              (*R)[nnz] = SO + S + SE + O + M + E + NO + N + NE; 
              
              nnz++;
              
               
             }
            

              ind++;}
      }



      
    
    



  
  return 0;
}