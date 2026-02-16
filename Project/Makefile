# librairies de SuiteSparse et superLU
L1 = SuiteSparse/UMFPACK/Lib/libumfpack.a
L2 = SuiteSparse/CHOLMOD/Lib/libcholmod.a 
L3 = SuiteSparse/AMD/Lib/libamd.a 
L4 = SuiteSparse/CAMD/Lib/libcamd.a  
L5 = SuiteSparse/COLAMD/Lib/libcolamd.a 
L6 = SuiteSparse/CCOLAMD/Lib/libccolamd.a 
L7 = SuiteSparse/metis-4.0/libmetis.a
L8 = SuiteSparse/SuiteSparse_config/libsuitesparseconfig.a
#LIB1 = $(L9) $(L10) $(L11) $(L12) -lm -lblas -llapack
LIB = $(L1) $(L2) $(L3) $(L4) $(L5) $(L6) $(L7) $(L8)  -lm -lblas -llapack




COPT = -O3 -Wall

default: main

clean: 
	rm *.o 
	rm main

main: main.c time.o  umfpack.o residu.o graphique.o Prob.o Bresidue.o er.o residual.o Matrix_p.o Restriction.o Ac.o Coarse_grid_correction.o prolongation.o multigrid.o v_cycle.o two_grid.o conjugate_gradiant.o w_cycle.o
	cc $(COPT) $^ -o $@ $(LIB) 


umfpack.o: umfpack.c
	cc $(COPT) -c $< -o $@ -ISuiteSparse/UMFPACK/Include \
  -ISuiteSparse/SuiteSparse_config  -ISuiteSparse/AMD/Include

%.o: %.c
	cc $(COPT) -c $< -o $@


