#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "err.h"
#include "readfile.h"
#include "object.h"
#include "obj_arr.h"

void info()
{
    printf("\nTo run program use app.exe FILE_NAME\n");
    printf("if you want to see non - sorted data run with app.exe FILE_NAME STRING_BEGIN\n");
}

int main(int argc, char **argv)
{
    int rc = OK;
    setbuf(stdout, NULL);
    if (argc <= 1)
    {
        info();
        return ERR_OPEN_FILE;
    }
    FILE *f;
    f = fopen(argv[1], "r");
    if (!f)
    {
        //printf("\nINFO: CANNOT OPEN FILE!!!");
        return ERR_OPEN_FILE;
    }
    //printf("\nINFO: FILE OPPENED");

    o_arr db;
    init_arr(&db);
    //printf("\nINFO: DB INITIALIZED");

    rc = alloc_mem(&db, f);
    rewind(f);
    if (rc == OK)
    {
        //printf("\nINFO: MEMORY ALLOCATED");
        read_db(f, &db, &rc);
    }
    
    if (argc == 2 && rc == OK)
    {
        sort_arr(&db);
        print_db(&db);
    }
    else if (rc == OK && argv[2] != NULL)
    {
        print_db_by_key(&db, argv[2]);
    }
    free_db(&db);
    fclose(f);
    return rc;
}