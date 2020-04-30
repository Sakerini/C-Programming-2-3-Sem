#include <assert.h>

#include "readfile.h"

#define BUFF_LEN 101
#define BOOL_TO_STR(a) (a == false? "false":"true")
int objects_count(FILE *f, int *rc)
{
    /*
    int count = 0;
    char a[100];
    while (fgets(a , 100, f))
        count += 1;
    fseek(f, 0, 0);
    return count / 3;
    */
   object_t *object = NULL;
   int count = 0;
   bool haveData;
   while(!feof(f))
   {
        if (!(object = read_object(f, &haveData)))
            break;
        else
            count++;
        free_object(object);
   }
   //printf("CHECK: %s\n", BOOL_TO_STR(haveData));
   if (haveData == false)
   {
       count = 0;
   }
   //printf("%d", count);
   return count;
}
/*
int digit_check(const char *str)
{
    int floating_point = 0;
    //printf("\nSTRING: %s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (!(isdigit(str[i])))
        {
            if (str[i] == '.' && floating_point == 0)
                floating_point = 1;
            else
            {
                //printf("ERROR NUMBER");
                return ERR_IO;
            }
        }
    }
    return OK;
}
*/

object_t* new_object(int len)
{
    assert(len > 0);

    object_t* tmp = NULL;
    if (!(tmp = malloc(sizeof(object_t))))
        return NULL;
    
    if (!(tmp->name = malloc((len + 1) * sizeof(char))))
    {
        free(tmp);
        return NULL;
    }

    return tmp;
}

int read_positive_double(FILE *f, double *num)
{
    assert(f);
    assert(num);

    char buff[BUFF_LEN] = { 0 };

    if(!(fgets(buff, BUFF_LEN, f)))
        return ERR_IO;

    char *temp;
    *num = strtod(buff, &temp);

    if (*num <= 0 && (!feof(f) || strcmp(temp, "\n")))
        return ERR_IO;

    return OK;
}

void free_object(object_t* object)
{
    if (object)
    {
        if (object->name)
            free(object->name);
            
        free(object);
    }
}

object_t* read_object(FILE *f, bool *haveData)
{
    *haveData = false;
    object_t *tmp = NULL;
    char buff[BUFF_LEN];
    int len;
    // name
    if(!(fgets(buff, BUFF_LEN, f)) || !strcmp(buff, "\n"))
        return NULL;
        
    if ((len = strlen(buff)) <= 1)
        return NULL;

    if (buff[len - 1] == '\n')
        buff[len - 1] = 0;
    
    if (!(tmp = new_object(len)))
        return NULL;
    
    strcpy(tmp->name, buff);

    if (read_positive_double(f, &(tmp->mass)) != OK)
    {
        free_object(tmp);
        return NULL;
    }

    if (read_positive_double(f, &(tmp->obem)) != OK)
    {
        free_object(tmp);
        return NULL;
    }
    *haveData = true;
    return tmp;
}

void read_db(FILE *f, o_arr *db, int *rc)
{
    //printf("\n%ld", ftell(f));
    object_t *object = NULL;
    //printf("\n APPEND %d and ALLOC %d", db->appended, db->allocated);
    bool haveData;
    while(db->appended != db->allocated)
    {
        if ((object = read_object(f, &haveData)))
        {
            append_object(db, object);
        }
    }
}