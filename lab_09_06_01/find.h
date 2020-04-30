#ifndef _FIND_H_
#define _FIND_H_

#include <math.h>
void find_min(int64_t **ptrs, int n, int m, int *pos_n, int *pos_m);
int64_t min_in_row(int64_t **ptrs, int row, int elements);
long geometric_mean(long **ptrs, int elements, int collumn);


#endif