#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <string.h>

#include "stud_arr.h"
#define EQUAL 0
#define NOT_EQUAL 1
#define FOUND '0'
#define NOT_FOUND '1'

void create_diff(stud_arr* db, stud_arr* db2, stud_arr* result);

#endif // PROCESS_H
