#ifndef READFILE_H
#define READFILE_H

#include <stdio.h>
#include "stud_arr.h"
#include <stdlib.h>
#include <string.h>
#include "err.h"

int count_object(FILE *f, int *rc);
stud_t* read_object(FILE *f);

#endif // READFILE_H
