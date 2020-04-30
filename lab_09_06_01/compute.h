#ifndef _COMPUTE_H_
#define _COMPUTE_H_

void multi(int64_t **mat_a, int64_t **mat_b, int64_t **mat_c, int size);
void multiply_matrix(int64_t **mat_a, int64_t **mat_b, int n);
void computation(int64_t ***mat_a, int64_t ***mat_b, int n, int ro, int gamma);

#endif