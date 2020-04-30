#include "io.h"
#include "err.h"

void mtr_free(int **mtr, int n)
{
    if (mtr)
    {
        for (int i = 0; i < n; i++)
        {
            free(mtr[i]);
        }
        free(mtr);
    }
}

int matrix_alloc(int ***mtr, int n, int m)
{
    if (n <= 0 || m <= 0)
        return ERR_IO;
    
    int **temp = calloc(n, sizeof(int *));
    if (temp)
    {
        for (int i = 0; i < n; i++)
        {
            temp[i] = malloc(m * sizeof(int));
            if (!(temp[i]))
            {
                mtr_free(temp, i);
                return ERR_MEM_ALLOC;
            }
        }
    }

    *mtr = temp;
    return OK;
}

int mtr_input(int ***mtr, int *n, int *m)
{
    printf("\nPlease enter rows and collumns: ");
    if (scanf("%d%d", n, m) != 2)
        return ERR_IO;
    
    if (*n <= 0 || *m <= 0)
        return ERR_RANGE;

    if (matrix_alloc(mtr, *n, *m) != 0)
        return ERR_MEM_ALLOC;
    
    printf("\nEnter elements of the matrix:\n");
    //(*mtr)[0][0] = 3;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            if (scanf("%d", &(*mtr)[i][j]) != 1)
                return ERR_IO;
        }
    }
    return OK;
}

void mtr_print(int **mtr, int n, int m)
{
    printf("\n --- Matrix --- \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
            printf("%d ", mtr[i][j]);
        printf("\n");
    }
}