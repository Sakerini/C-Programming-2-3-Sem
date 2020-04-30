#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "io.h"
#include "err.h"
#include "process.h"
#include "add_or_delete.h"

int main(void)
{
    int rc = ERR_OK;
    double *beg = NULL, *end = NULL;
    setbuf(stdout, NULL);
    if ((rc = input(&beg, &end)) != 0)
    {
        if (rc == ERR_RANGE)
            printf("Wrong input range!!!");
        else if (rc == ERR_IO)
            printf("Wrong input number!!!");
        else if (rc == ERR_MEM_ALLOC)
            printf("Memmory allocation error!!!");
		
        free(beg);
        beg = NULL;
        end = NULL;
    }
    else
    {
        int size = end - beg;
	
        double miu1 = compute_miu1(beg, end);
        double *position = find_element(beg, end, miu1);
        rc = complete_delete(&beg, &end, position);
        if (rc == ERR_MEM_ALLOC)
        {
            printf("Error MEM ALLOCATION");
        }
        else
        {
            position = find_element(beg, end, miu1);
            rc = complete_delete(&beg, &end, position);
            if (rc == ERR_MEM_ALLOC)
            {
                printf("Error MEM ALLOCATION");
            }
            else
            {
                size = end - beg;
                double miu2 = compute_miu2(beg, end);
                int p;
                if ((rc = input_p(&p, beg, end)) == ERR_OK)
                {
                    rc = change_arr_size(&beg, &size, size + 3);
                    if (rc != ERR_OK)
                    {
                        printf("ERROR MEMORY ALLOCATION");
                    }
                    else
                    {
                        end = beg + size;
                        add_element(beg, end, miu2, p);	
                        print_arr(beg, end);
                    }
                }
                else if (rc == ERR_RANGE)
                {
                    printf("Position must be p > ZERO & p < size of the array!!!");
                }
                else
                {
                    printf("ERROR entering p position!!");
                }
            }
        }
    }
    free(beg);
    return rc;
}
                