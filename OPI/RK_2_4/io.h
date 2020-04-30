#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>

int freadline(FILE *f, char *str, int str_size);
void print(FILE *f, char **str, int n);

#endif