#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void gaussian_elimination(int n, double **A, double *x, double *b);
void matrix_row_exchange(int n, double **A, int i, int j);
void vector_row_exchange(int n, double *b, int i, int j);
