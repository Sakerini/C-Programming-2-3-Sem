#include "add_or_delete.h"
#include <assert.h>
#include <math.h>
#include "err.h"
#include"process.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

#define NOT_PASSED 1
#define PASSED 0
int arr_cmp(double *beg, double *end, double *array, int n)
{
    double *pcur = beg;
    for (int i = 0; pcur < end; pcur++)
    {
        if (*(pcur) != array[i])
        {
            printf("ELEMENT: %lf vs %lf", *pcur, array[i]);
            printf("DIDN'T PASSED\n");
            return NOT_PASSED;
        }
        i++;
    }
    return PASSED;
}
int test_add()
{
    printf("----------: %s :----------\n", __func__);
    int err_cnt = 0;
	
    {
        int size = 5, position = 3;
        double array[] = { 5.31, 51.1, 0.2, 5., 0 };
        double *end = array + size;
        add(array, end - 1, position, 0.3);
        double result_arr[] = { 5.31, 51.1, 0.2, 0.3, 5. };

        for (int i = 0; i < size; i++)
        {
            if (array[i] != result_arr[i])
            {
                err_cnt++;
                printf("DIDN'T PASSED\n");
            }
        }
        if (err_cnt == 0)
            printf("PASSED\n");
    }
    return err_cnt;
}

int test_del_element()
{
    printf("----------: %s :----------\n", __func__);
    int err_cnt = 0;
    //element in middle
    {
        int size = 5, position = 2;
        double array[] = { 5.31, 51.1, 0.2, 5., 0 };
        double *end = array + size;
        del_element(array + position, end);
        size = 4;
        double result_arr[] = { 5.31, 51.1, 5., 0 };

        for (int i = 0; i < size; i++)
        {
            if (array[i] != result_arr[i])
            {
                err_cnt++;
                printf("DIDN'T PASSED\n");
            }
        }
        if (err_cnt == 0)
            printf("PASSED\n");
    }
    //first element!
    {
        int size = 5, position = 0;
        double array[] = { 5.31, 51.1, 0.2, 5., 0 };
        double *end = array + size;
        del_element(array + position, end);
        size = 4;
        double result_arr[] = { 51.1, 0.2, 5, 0 };

        for (int i = 0; i < size; i++)
        {
            if (array[i] != result_arr[i])
            {
                err_cnt++;
                printf("DIDN'T PASSED\n");
            }
        }
        if (err_cnt == 0)
            printf("PASSED\n");
    }
    //last element!
    {
        int size = 5, position = 4;
        double array[] = { 5.31, 51.1, 0.2, 5., 0 };
        double *end = array + size;
        del_element(array + position, end);
        size = 4;
        double result_arr[] = { 5.31, 51.1, 0.2, 5 };

        for (int i = 0; i < size; i++)
        {
            if (array[i] != result_arr[i])
            {
                err_cnt++;
                printf("DIDN'T PASSED\n");
            }
        }
        if (err_cnt == 0)
            printf("PASSED\n");
    }
    return err_cnt;
}

int test_find_element()
{
    printf("----------: %s :----------\n", __func__);
    int err_cnt = 0;

    {
        int size = 4;
        double number = 0.54;
        double array[] = { 0, 1.4, 64, 32 };
        double *end = array + size;
        if (find_element(array, end, number) == NULL)
        {
            err_cnt++;
            printf("DIDN'T PASSED\n");
        }
        else
            printf("PASSED\n");
    }
    return err_cnt;
}

int test_compute_miu1()
{
    printf("----------: %s :----------\n", __func__);
    int err_cnt = 0;
    //Normal numbers
    {
        int size = 4;
        double array[] = { 5, -7, 6, 2 };
        double *end = array + size;
        double number = compute_miu1(array, end);
        double eps = 1e-1;
        if (fabs(number - 2.1) < eps)
        {
            printf("PASSED\n");
        }
        else
        {
            err_cnt++;
            printf("DIDN'T PASSED\n");
        }
    }
    //AllNumsZero
    {
        int size = 6;
        double array[] = { 0, 0, 0, 0, 0, 0 };
        double *end = array + size;
        double number = compute_miu1(array, end);
        double eps = 1e-1;
        if (fabs(number - 0) < eps)
        {
            printf("PASSED\n");
        }
        else
        {
            err_cnt++;
            printf("DIDN'T PASSED\n");
        }
    }
    //mixed negative and positive
    {
        int size = 5;
        double array[] = { -5, 1, -5, 4, -6 };
        double *end = array + size;
        double number = compute_miu1(array, end);
        double eps = 1e-1;
        if (fabs(number - -2.4) < eps)
        {
            printf("PASSED\n");
        }
        else
        {
            err_cnt++;
            printf("DIDN'T PASSED\n");
        }
    }
    return err_cnt;
}
int test_complete_delete()
{
    printf("----------: %s :----------\n", __func__);
    int err_cnt = 0;

    {
        int size = 5, rc = ERR_OK;
        double array[] = { 5.31, 51.1, 0.2, 5., 0 };
        double *beg = NULL;
        beg = malloc(size * sizeof(double));

        assert(beg != NULL);
        for (int i = 0; i < size; i++)
        {
            beg[i] = array[i];
            //printf("\n %lf", beg[i]);
        }
        double *end = beg + size;
        double result_arr[] = { 5.31, 51.1, 0.2, 0 };
        double *position = beg + 3;
        rc = complete_delete(&beg, &end, position);
        if (rc == ERR_MEM_ALLOC)
        {
            err_cnt++;
            free(beg);
            beg = NULL;
            printf("DIDN'T PASSED MEM ERROR\n");
        }
        else
        {
            err_cnt += arr_cmp(beg, end, result_arr, size - 1);
            if (err_cnt == 0)
                printf("PASSED\n");
        }
        free(beg);
    }
    return err_cnt;
}

int main(void)
{
    int errs = 0;

    errs += test_add();
    errs += test_del_element();
    errs += test_find_element();
    errs += test_compute_miu1();
    errs += test_complete_delete();
    printf("\n\nTOTAL ERRORS: %i", errs);

    return 0;
}

