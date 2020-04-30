#ifndef _ADD_H_
#define _ADD_H_

int row_allocate(int64_t ***ptrs, int *n, int m);
void insert_geom_mean(int64_t **ptrs, int n, int m);
int matrix_grow(int64_t ***ptrs, int *n, int *m, int new_size);

#endif