#include "err.h"
#include "find.h"
#include "io.h"
#include "assert.h"
#include "compute.h"
#include "add.h"
#include "delete.h"
#define ROWS 10

void matrix_cpy(int64_t (*matrix)[ROWS], int n, int m, int64_t **dyn_matrix)
{
    assert(dyn_matrix);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            dyn_matrix[i][j] = matrix[i][j];
        }
}

int matrix_compare(int64_t (*matrix)[ROWS], int64_t **dyn_matrix, int n, int m)
{
    int errors = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            //printf("\n I:%d, J:%d, EL: %ld", i, j, dyn_matrix[i][j]);
            if (matrix[i][j] != dyn_matrix[i][j])
            {
                errors += 1;
            }
        }
    return errors;
}
int test_find_min()
{
    printf("----------: %s :----------\n", __func__);
    int err_cnt = 0;
    {
        int n = 3, m = 4, pos_n, pos_m;
        int64_t matrix[][ROWS] = { { -5, 3, 1, 36 }, { 5, 3, 1, 2 }, { 43, -7, 1, 1 } };
        int64_t **matrix_dyn;
        matrix_dyn = matrix_alloc(n, m);

        matrix_cpy(matrix, n, m, matrix_dyn);

        find_min(matrix_dyn, n, m, &pos_n, &pos_m);
        if (matrix_dyn[pos_n][pos_m] == -7)
        {
            //printf("%ld", matrix_dyn[pos_n][pos_m]);
            printf("\nPASSED");
        }
        else
        {
            err_cnt++;
            printf("\nFAILED");
        }
        matrix_free(matrix_dyn, n);
    }
    return err_cnt;
}

int test_multi()
{
    printf("\n----------: %s :----------\n", __func__);
    int err_cnt = 0;
    {
        int n = 2, m = 2;
        int64_t matrix[][ROWS] = { { 1, 2 }, { 3, 4 } };
        int64_t matrix_test[][ROWS] = { { 7, 10 }, { 15, 22 } };

        int64_t **matrix_dyn;
        int64_t **matrix_result;
        matrix_dyn = matrix_alloc(n, m);
        matrix_result = matrix_alloc(n, m);

        matrix_cpy(matrix, n, m, matrix_dyn);

        multi(matrix_dyn, matrix_dyn, matrix_result, n);
        err_cnt = matrix_compare(matrix_test, matrix_result, n, m);
        if (err_cnt != 0)
            printf("\nFAILED");
        else
            printf("\nPASSED\n");
        matrix_free(matrix_result, n);
        matrix_free(matrix_dyn, n);
    }
    return err_cnt;
}

int test_tranform_quadratic()
{
    printf("\n----------: %s :----------\n", __func__);
    int err_cnt = 0;
    //Delete rows
    {
        int n = 4, m = 2;
        int64_t matrix[][ROWS] = { { 1, 2 }, { 3, 4 }, { -6, 1 }, { 8, 2 } };
        int64_t matrix_test[][ROWS] = { { 3, 4 }, { 8, 2 } };

        int64_t **matrix_dyn;
        matrix_dyn = matrix_alloc(n, m);

        matrix_cpy(matrix, n, m, matrix_dyn);

        tranform_quadratic(&matrix_dyn, &n, &m);

        err_cnt = matrix_compare(matrix_test, matrix_dyn, n, m);
        if (err_cnt != 0)
            printf("\nFAILED");
        else
            printf("\nPASSED\n");
        matrix_free(matrix_dyn, n);
    }
    //Delete Collumn
    {
        int n = 2, m = 4;
        int64_t matrix[][ROWS] = { { 7, 8, 4, 3 }, { 5, 6, 3 ,2 } };
        int64_t matrix_test[][ROWS] = { { 7, 8 }, { 5, 6 } };

        int64_t **matrix_dyn;
        matrix_dyn = matrix_alloc(n, m);

        matrix_cpy(matrix, n, m, matrix_dyn);

        tranform_quadratic(&matrix_dyn, &n, &m);

        err_cnt = matrix_compare(matrix_test, matrix_dyn, n, m);
        if (err_cnt != 0)
            printf("\nFAILED");
        else
            printf("\nPASSED\n");
        matrix_free(matrix_dyn, n);
    }
    return err_cnt;
}

int test_matrix_grow()
{
    printf("\n----------: %s :----------\n", __func__);
    int err_cnt = 0;
    {
        int n = 2, m = 2;
        int64_t matrix[][ROWS] = { { 2, 7 }, { 4, 3 } };
        int64_t matrix_test[][ROWS] = { { 2, 7, 2, 2, 2 }, { 4, 3, 3, 3, 3 }, { 2, 4, 2, 2, 2 }, { 2, 4, 2, 2, 2 }, { 2, 4, 2, 2, 2 } };

        int64_t **matrix_dyn;
        matrix_dyn = matrix_alloc(n, m);

        matrix_cpy(matrix, n, m, matrix_dyn);
       // matrix_print(matrix_dyn, n, m);

        matrix_grow(&matrix_dyn, &n, &m, 5);

        //printf("\n");
        //matrix_print(matrix_dyn, n, m);

        err_cnt = matrix_compare(matrix_test, matrix_dyn, n, m);
        if (err_cnt != 0)
            printf("\nFAILED");
        else
            printf("\nPASSED\n");
        matrix_free(matrix_dyn, n);
    }
    return err_cnt;
}

int test_computation()
{
    printf("\n----------: %s :----------\n", __func__);
    int err_cnt = 0;
    {
        int n = 2;
        int64_t matrix_a[][ROWS] = { { 2, 7 }, { 4, 3 } };
        int64_t **matrix_dyn_a;
        matrix_dyn_a = matrix_alloc(n, n);
        matrix_cpy(matrix_a, n, n, matrix_dyn_a);
        int64_t matrix_b[][ROWS] = { { -53, 61 }, { 32, 11 } };
        int64_t **matrix_dyn_b;
        matrix_dyn_b = matrix_alloc(n, n);
        matrix_cpy(matrix_b, n, n, matrix_dyn_b);
        //test
        computation(&matrix_dyn_a, &matrix_dyn_b, n, 4, 0);
        int64_t matrix_result[][ROWS] = { { 1724, 2415 }, { 1380, 2069 } };
        err_cnt = matrix_compare(matrix_result, matrix_dyn_b, n, n);
        if (err_cnt != 0)
            printf("\nFAILED");
        else
            printf("\nPASSED\n");

        matrix_free(matrix_dyn_a, n);
        matrix_free(matrix_dyn_b, n);
    }
    return err_cnt;
}

int main(void)
{
    int errs = 0;

    errs += test_find_min();
    errs += test_multi();
    errs += test_tranform_quadratic();
    errs += test_matrix_grow();
    errs += test_computation();
    
    printf("\n\nTOTAL ERRORS: %i", errs);

    return 0;
}

