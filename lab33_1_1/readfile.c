#include "readfile.h"

int count_object(FILE *f, int *rc){
    int counter = 0;

    while (!feof(f))
    {
        stud_t *tmp = NULL;
        if ((tmp = read_object(f)) != NULL)
        {
            counter++;
            free(tmp->name); 
            free(tmp);
        }
        else
        {
            if(feof(f))
                return counter;
            *rc = ERR_READ_OBJECT;
        }
    }
    //printf("%d", counter);
    return counter;
}

stud_t* read_object(FILE *f){

    stud_t *tmp;
    char buf[101];
    int len;

    if (!fgets(buf, 101, f))
        return NULL;

    len = strlen(buf);

    if (buf[len - 1] != 0)
        buf[len - 1] = 0;
    if(len <= 1)
        return NULL;

    tmp = malloc(sizeof(stud_t));
    tmp->name = malloc((len + 1) * sizeof(char));

    if(!tmp->name)
        return NULL;
    //printf("\n IN Read_OB: %s", buf);
    strcpy(tmp->name, buf);
    
    if (fscanf(f, "%d", &tmp->year) != 1)
    {
        //printf("here?");
        free(tmp->name);
        free(tmp);
        return NULL;
    }
    if(tmp->year <= 0)
    {
        //printf("here?");
        free(tmp->name);
        free(tmp);
        return NULL;
    }
    fgets(buf, 101, f); // fscanf
    //printf("\n Read year: %d", tmp->year);
    return tmp;
}

/*
stud_arr* read_db(FILE *f)
{
    stud_arr *db;
    stud_arr_init(&db);
    int obj_c = count_object(f, &rc);
    if (rc == OK)
    {
        rc = stud_arr_alloc(&db, obj_c);
        if (rc == OK)
        {
            rewind(f);
            while (!feof(f))
            {
                db.data[db.len] = read_object(f);
                if (!(db.data))
                {
                    rc = ERR_READ_OBJECT;
                    break;
                }
                db.len++;
            }
            if (rc == OK)
            {
                print_db(&db);
            }
        }
    }
}
*/
