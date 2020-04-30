#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "err.h"

int main(void)
{
    int **mtr = NULL;
    int n,m;
    int rc =  OK;
    setbuf(stdout, NULL);

    rc = mtr_input(&mtr, &n, &m);
    if (rc == OK)
    {
        mtr_print(mtr, n, m);
        if (n == m)
        {
            printf("\n Matrix quadratic");
            int *arr = malloc((2 * n) * sizeof(int));
            int count = 0;
            if (arr)
            {
                for (int i = 0; i < n; i++)
                {
                    arr[count] = mtr[i][i];
                    arr[count + n] = mtr[i][n-1-i];
                    count++;
                }
                
                printf("\n ARRAY: ");
                for (int i = 0; i < 2 * count; i++)
                    printf("%d ", arr[i]);

                free(arr);
            }
        }
    }
    mtr_free(mtr, n);
    return rc;
}