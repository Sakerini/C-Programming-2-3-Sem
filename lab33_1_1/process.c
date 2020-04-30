#include "process.h"

int obj_cmp(stud_t* a, stud_t* b)
{
    if(!strcmp(a->name, b->name))
    {
        if (a->year == b->year)
            return EQUAL;
    }

    return NOT_EQUAL;
}

void obj_cpy(stud_t** a, stud_t* b)
{
    (*a) = malloc(sizeof(stud_t));
    (*a)->name = malloc(sizeof(char) * strlen(b->name) + 1);
    strcpy((*a)->name, b->name);
    (*a)->year = b->year;
}

void print_obj(stud_t* a)
{
    printf("\n%s", a->name);
    printf("\n%d", a->year);
}

void create_diff(stud_arr* db, stud_arr* db2, stud_arr* result)
{
    char found = NOT_FOUND;
    for (int i = 0 ; i < db->len;i++)
    {
        found = NOT_FOUND;
        for (int j = 0; j < db2->len;j++)
        {
            if (obj_cmp(db->data[i], db2->data[j]) == EQUAL)
            {
                found = FOUND;
                break;
            }
        }

        if (found == NOT_FOUND)
        {
            //printf("%d",result->len);
            obj_cpy(&result->data[result->len++], db->data[i]);
        }
    }
}
