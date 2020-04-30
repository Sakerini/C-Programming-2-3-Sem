#include <stdio.h>
#include "readfile.h"
#include "obj_arr.h"

int db_cmp(o_arr *a, o_arr *b)
{
    if (a->appended != b->appended)
        return -1;
    if (a->allocated != b->allocated)
        return -1;
    
    for (int i = 0; i < a->appended; i++)
    {
        if (strcmp(a->data[i]->name, b->data[i]->name))
            return -1;
    }

    return 0;
}

int test_count_object()
{
    printf("\nTEST: %s ", __func__);
    int err_count = 0;
    {
        FILE *f;
        int rc = OK;
        f = fopen("testcount.txt", "r");
        if (!f)
        {
            printf("\nINFO: TEST FILE DID NOT OPEN");
        }
        else
        {
            int num = objects_count(f, &rc);
            printf("%d", rc);
            if (num == 3)
                printf("\nTEST: PASSED !!!");
            else
            {
                printf("\nTEST: NOT PASSED !!!");
                err_count++;
            }
        }
        fclose(f);
    }
    return err_count;
}

int test_read_object()
{
    printf("\nTEST: %s ", __func__);
    int err_count = 0;
    {
        FILE *f;
        f = fopen("testcount.txt", "r");
        int rc = OK;
        if (!f)
        {
            printf("\nINFO: TEST FILE DID NOT OPEN");
        }
        object_t *object = NULL;
        object = read_object(f, &rc);
        if (!strcmp(object->name, "Roni"))
            if (object->mass == 123.53)
                if (object->obem == 34.53)
                    printf("\nTest: PASSED !!!");
                else
                {
                    printf("\nTEST: NOT PASSED !!!");
                    err_count++;
                }
            else
            {
                printf("\nTEST: NOT PASSED !!!");
                err_count++;
            }
        else
        {
            printf("\nTEST: NOT PASSED !!!");
            err_count++;
        }                  
        free(object->name);
        free(object);
        fclose(f);
    }
    return err_count;
}

int test_sort_arr()
{
    printf("\nTEST: %s ", __func__);
    int err_count = 0;
    {
        FILE *f;
        f = fopen("testcount.txt", "r");
        if (!f)
        {
            printf("TEST: NOT PASSED !!!");
            err_count++;
        }
        int rc = OK;
        o_arr db;
        init_arr(&db);
        //printf("\nINFO: DB INITIALIZED");

        rc = alloc_mem(&db, f);
        if (rc == OK)
        {
            //printf("\nINFO: MEMORY ALLOCATED");
            read_db(f, &db, &rc);
        }
        else
        {
            printf("TEST: NOT PASSED !!!");
            err_count++;
        }
        fclose(f);

        sort_arr(&db);

        f = fopen("sortedtest.txt", "r");
        if (!f)
        {
            printf("TEST: NOT PASSED !!!");
            err_count++;
        }
        rc = OK;
        o_arr sort_db;
        init_arr(&sort_db);
        //printf("\nINFO: DB INITIALIZED");

        rc = alloc_mem(&sort_db, f);
        if (rc == OK)
        {
            //printf("\nINFO: MEMORY ALLOCATED");
            read_db(f, &sort_db, &rc);
        }
        else
        {
            printf("\nTEST: NOT PASSED !!!");
            err_count++;
        }
        fclose(f);
        if (db_cmp(&db, &sort_db) == 0)
            printf("\nTEST: PASSED !!!");
        else
        {
            printf("\nTEST: NOT PASSED !!!");
            err_count++;
        }

        free_db(&db);
        free_db(&sort_db);
    }
    return err_count;
}
int main(void)
{
    int errs = 0;
    errs += test_count_object();
    errs += test_read_object();
    errs += test_sort_arr();
    return errs;
}