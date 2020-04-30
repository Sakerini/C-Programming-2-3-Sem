#include "obj_arr.h"

void init_arr(o_arr *object)
{
    object->data = NULL;
    object->allocated = 0;
    object->appended = 0;
}

int alloc_mem(o_arr *db, FILE *f)
{
    int num;
    int rc = OK;
    num = objects_count(f, &rc);
    //printf("RC = %d", rc);
    if (num < 1)
        return ERR_IO;
    if (rc != OK)
        return ERR_IO;
    db->data = malloc(num * sizeof(object_t*));
    if(!(db->data))
        return ERR_MEM_ALLOC;

    db->allocated = num;
    return OK;
}

void append_object(o_arr *db, object_t *object)
{
    db->data[db->appended] = object;
    db->appended++;
}

void print_db(o_arr *db)
{
    for (int i = 0; i < db->appended; i++)
    {
        printf("%s\n", db->data[i]->name);
        printf("%f\n", db->data[i]->mass);
        printf("%f\n", db->data[i]->obem);
    }
}

void print_db_by_key(o_arr *db, char *key)
{
    if (!strcmp(key, "ALL"))
    {
        print_db(db);
    }
    else
    {
        for (int i = 0; i < db->appended; i++)
        {
            if ((strstr(db->data[i]->name, key) - db->data[i]->name) == 0)
            {
                if(strstr(db->data[i]->name, key) != NULL)
                {
                    printf("%s\n", db->data[i]->name);
                    printf("%f\n", db->data[i]->mass);
                    printf("%f\n", db->data[i]->obem);
                }
            }
        }
    }
}

void sort_arr(o_arr *db)
{
    int comps, sorted = 0;
    comps = db->appended - 1;
    int p1 = 0;
    int p2 = 0;

    while(!sorted)
    {
        sorted = 1;
        for (int i = 0; i < comps; i++)
        {
            p1 = db->data[i]->mass / db->data[i]->obem;
            p2 = db->data[i + 1]->mass / db->data[i + 1]->obem;
            if (p1 > p2)
            {
                object_t *tmp = db->data[i];
                db->data[i] = db->data[i + 1];
                db->data[i + 1] = tmp;
                sorted = 0;
            }
        }
        comps--;
    }
}

void free_db(o_arr *db)
{
    for (int i = 0; i < db->appended; i++)
    {
        free(db->data[i]->name);
        free(db->data[i]);
    }
    free(db->data);
    init_arr(db);
}