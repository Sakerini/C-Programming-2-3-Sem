#include "stud_arr.h"

void stud_arr_free(stud_arr *data)
{
    for (int i = 0; i < data->len; i++)
    {
        free(data->data[i]->name);
        free(data->data[i]);
    }
    free(data->data);
}

void stud_arr_init(stud_arr *data){
    data->data = NULL;
    data->allocated = 0;
    data->len = 0;
}


int stud_arr_alloc(stud_arr *data, int size)
{
    data->data = malloc(size * sizeof(stud_t*));
    if(!(data->data))
        return ERR_MEM_ALLOC;
    data->allocated = size;
    return OK;
}

void print_db(stud_arr *data)
{
    for (int i = 0; i < data->len; i++)
    {
        printf("%s\n", data->data[i]->name);
        printf("%d\n", data->data[i]->year);
    }
}
