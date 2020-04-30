#ifndef _ADD_OR_DELETE_H_
#define _ADD_OR_DELETE_H_

#include <stdio.h>

double *find_element(double *beg, const double *end, double miu);
void del_element(double *beg, double *end);
int change_arr_size(double **array, int *size, int newn);
void add(double *beg, double *end, int position, double miu);
void add_element(double *beg, double *end, double miu, int p);
int complete_delete(double **beg, double **end, double *position);
#endif
