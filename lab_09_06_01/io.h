#ifndef _IO_H_
#define _IO_H_
#include <stdio.h>
#include <stdlib.h>

int in_ro_gamma(int *ro, int *gamma);
void matrix_free(long **arr_ptrs, int n);
long **matrix_alloc(int n, int m);
int matrix_input(long **ptrs, int n, int m);
int matrix_create(long ***arr_ptrs, int *n, int *m);
void matrix_print(long **arr_ptrs, int n, int m);

#endif
