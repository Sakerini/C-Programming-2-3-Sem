#ifndef _READFILE_H_
#define _READFILE_H_

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "object.h"
#include "obj_arr.h"
#include "err.h"

int objects_count(FILE *f, int *rc);
object_t* read_object(FILE *f, bool *haveData);
void read_db(FILE *f, o_arr *db, int *rc);
void free_object(object_t* object);

#endif