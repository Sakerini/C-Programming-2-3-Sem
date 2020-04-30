#ifndef STUD_ARR_H
#define STUD_ARR_H

#include <stdio.h>
#include <stdlib.h>

#include "err.h"

typedef struct stud_t{
    char *name;
    int year;
}stud_t;

typedef struct stud_arr{
    stud_t **data;
    int allocated;
    int len;
} stud_arr;

void stud_arr_init(stud_arr *data);
int stud_arr_alloc(stud_arr *data, int size);
void print_db(stud_arr *data);
void stud_arr_free(stud_arr *data);

#endif // STUD_ARR_H
