#include <stdio.h>
#include "err.h"
#include "stud_arr.h"
#include "readfile.h"
#include "process.h"

int main (int args, char** argv)
{
    setbuf(stdout, NULL);
    int rc = OK;
    if (args != 3)
        return ERR_ARGS;

    FILE *f = fopen(argv[1], "r");
    if (!f)
        return ERR_OPEN_FILE;

    FILE *f2 = fopen(argv[2], "r");
    if (!(f2))
    {
        fclose(f);
        return ERR_OPEN_FILE;
    }

    stud_arr db;
    stud_arr_init(&db);
    int obj_c = count_object(f, &rc);
    if (rc == OK)
    {
        rc = stud_arr_alloc(&db, obj_c);
        if (rc == OK)
        {
            rewind(f);
            while (db.len != obj_c)
            {
                db.data[db.len] = read_object(f);
                if (!(db.data))
                {
                    rc = ERR_READ_OBJECT;
                    break;
                }
                db.len++;
            }
            if (rc == OK)//TIL HERE
            {
                //printf("first file completed");
                stud_arr db2;
                stud_arr_init(&db2);
                obj_c = count_object(f2, &rc);
                if (rc == OK)
                {
                    //printf("%d", obj_c);
                    rc = stud_arr_alloc(&db2, obj_c);
                    if (rc == OK)
                    {
                        rewind(f2);
                        while (db2.len != obj_c)
                        {
                            db2.data[db2.len] = read_object(f2);
                            if (!(db2.data))
                            {
                                rc = ERR_READ_OBJECT;
                                break;
                            }
                            db2.len++;
                        }
                        if (rc == OK)
                        {
                            stud_arr result;
                            stud_arr_init(&result);
                            int max_elements = db.len + db2.len;

                            rc = stud_arr_alloc(&result, max_elements);
                            if (rc == OK)
                            {
                                //printf("\n %d", db.len);
                                create_diff(&db, &db2, &result);
                                create_diff(&db2, &db, &result);
                                print_db(&result);
                                if (result.len == 0)
                                    rc = ERR_RESULT;
                            }
                            stud_arr_free(&result);
                        }
                    }
                }
                stud_arr_free(&db2);
            }
        }
    }

    stud_arr_free(&db);
    fclose(f);
    fclose(f2);


    return rc;
}
