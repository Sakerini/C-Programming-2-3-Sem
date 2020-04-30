#ifndef _DELETE_H_
#define _DELETE_H_

#include "err.h"

int rows_resize(int64_t ***ptrs, int *n, int newn);
int collumn_resize(int64_t **ptrs, int m, int newn);
void move_rows(int64_t **ptrs, int n, int m, int posn);
void move_collumn(int64_t **ptrs, int n, int m, int posm);
int delete_row(int64_t ***ptrs, int *n, int m, int posn);
int delete_collumn(int64_t ***ptrs, int n, int *m, int posm);
int tranform_quadratic(int64_t ***ptrs, int *n, int *m);




#endif