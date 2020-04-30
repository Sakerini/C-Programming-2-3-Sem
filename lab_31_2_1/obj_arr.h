#ifndef _OBJ_ARR_H_
#define _OBJ_ARR_H_

#include "object.h"

typedef struct
{
    object_t *(*data);
    int allocated;
    int appended;
}o_arr;

#include "readfile.h"
#include "err.h"
#include <stdio.h>
#include <string.h>


void init_arr(o_arr *object);
int alloc_mem(o_arr *db, FILE *f);
void append_object(o_arr *db, object_t *object);
void print_db(o_arr *db);
void print_db_by_key(o_arr *db, char* key);
void free_db(o_arr *db);
void sort_arr(o_arr *db);

#endif