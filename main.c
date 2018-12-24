#include "gaussian_elimination.h"

/* Code to solve Ax = b by Gaussian elimination using partial pivoting */
int main()
{
   
	int n = 3;  /* n is the dimension of the matrix A */
	int i,j; 
	double **A = NULL; 
	double *x = NULL;
	double *b = NULL;
	double max_value;
	int max_index;

	A = (double **) calloc(n, sizeof(*A));

	for(i = 0; i < n; i++) {
		A[i] = (double *) calloc(n, sizeof(**A));
	}

	b = (double *) calloc(n, sizeof(*b));

	x = (double *) calloc(n, sizeof(*x));
	
	/* Example */ 
	A[0][0] = 2.0; A[0][1] = 1.0; A[0][2] = 1.0; 
	A[1][0] = 4.0; A[1][1] = -6.0; A[1][2] = 0.0;
	A[2][0] = -2.0; A[2][1] = 7.0; A[2][2] = 2.0;
	
	b[0] = 5.0; b[1] = -2.0; b[2] = 9.0;
	

	gaussian_elimination(n, A, x, b);

	/* Printing the results */
	for (i = 0; i < n; i++) {
		printf("x[%d] = %.2f\n", i, x[i]);
	}


	/* Freeing pointers */
	for (i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	free(b);
	free(x);

   return 0;
}