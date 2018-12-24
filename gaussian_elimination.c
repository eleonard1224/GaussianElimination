#include "gaussian_elimination.h"

/* Gaussian elimination with partial pivoting */
void gaussian_elimination(int n, double **A, double *x, double *b) {

	int i, j, k;
	double multiplier;
	double max_value;
	int max_index;
	
	for (i = 0; i < n; i++) {
		max_value = A[i][i];
		max_index = i;

		/* Getting the row index of the largest pivot */
		for (j = (i+1); j < n; j++) {
			if (A[j][i] > max_value) {
				max_value = A[j][i];
				max_index = j;
			}
		}

		/* Row exchanges in A and b */
		matrix_row_exchange(n, A, i, max_index);
		vector_row_exchange(n, b, i, max_index);

		/* Using the pivot to clear out the entries beneath it */
		for (j = (i+1); j < n; j++) {
			multiplier = A[j][i]/A[i][i];
			for (k = i; k < n; k++) {
				A[j][k] = A[j][k] - multiplier*A[i][k];
			}
			b[j] = b[j] - multiplier*b[i];
		}

	}

	/* Now have A in row echelon form, next do back substitution */
	x[n-1] = b[n-1]/A[n-1][n-1];
	for (i = (n-2); i >= 0; i--) {
		for (j = (n-1); j >= (i+1); j--) {
			b[i] = b[i] - A[i][j]*x[j];
			x[i] = b[i]/A[i][i];
		}
	}
}


/* matrix_row_exchange exchanges rows i and j of an n x n matrix */
void matrix_row_exchange(int n, double **A, int i, int j) {

	int k;
	double *row_i = NULL;
	double *row_j = NULL;

	row_i = (double *) calloc(n, sizeof(*row_i));
	row_j = (double *) calloc(n, sizeof(*row_j));

	for (k = 0; k < n; k++) {
		row_i[k] = A[i][k];
		row_j[k] = A[j][k];
	}

	for (k = 0; k < n; k++) {
		A[i][k] = row_j[k];
		A[j][k] = row_i[k];
	}
}

/* vector_row_exchange exchanges entries i and j of an n x 1 vector */
void vector_row_exchange(int n, double *b, int i, int j) {

	double entry_i;
	double entry_j;

	entry_i = b[i];
	entry_j = b[j];

	b[i] = entry_j;
	b[j] = entry_i;
}






