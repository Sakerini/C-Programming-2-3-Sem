#ifndef _IO_H_
#define _IO_H_

void mtr_free(int **mtr, int n);
int matrix_alloc(int ***mtr, int n, int m);
int mtr_input(int ***mtr, int *n, int *m);
void mtr_print(int **mtr, int n, int m);

#endif