#include "str.h"
#include "err.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool comparer(char **a, int na, char **b, int nb)
{
    if (na != nb)
        return false;
    if (na == nb && na == 0)
        return true;

    for (int i = 0; i < na; i++)
    {
        if (strcmp(a[i], b[i]) != 0)
            return false;
    }

    return true;
}

int test_split()
{
    printf("----------: %s :----------\n", __func__);
    int err_cnt = 0;
    int i = 0;

    // Normal string
    {
        i++;
        printf("Test number %i: ", i);
        // ----------------------------------------------------------
        char in[] = "Hello world to me";

        int n_buff = 10;
        char *buff[n_buff];

        char *exp[] = { "Hello", "world", "to", "me" };
        int n_exp = 4;
        int rc = split(in, buff, &n_buff);

        if (comparer(buff, n_buff, exp, n_exp) && rc == OK)
            printf("PASSED\n");
        else
        {
            err_cnt++;
            printf("DIDN'T PASSED\n");
        }
    }

    // Lots of spaces
    {
        i++;
        printf("Test number %i: ", i);
        // ----------------------------------------------------------
        char in[] = "    Hello    world    to   me   ";

        int n_buff = 10;
        char *buff[n_buff];

        char *exp[] = { "Hello", "world", "to", "me" };
        int n_exp = 4;
        int rc = split(in, buff, &n_buff);

        if (comparer(buff, n_buff, exp, n_exp) && rc == OK)
            printf("PASSED\n");
        else
        {
            err_cnt++;
            printf("DIDN'T PASSED\n");
        }
    }

    // Empty
    {
        i++;
        printf("Test number %i: ", i);
        // ----------------------------------------------------------
        char in[] = "    ";

        int n_buff = 10;
        char *buff[n_buff];

        char *exp[] = { 0 };
        int n_exp = 0;
        int rc = split(in, buff, &n_buff);

        if (comparer(buff, n_buff, exp, n_exp) && rc != OK)
            printf("PASSED\n");
        else
        {
            err_cnt++;
            printf("DIDN'T PASSED\n");
        }
    }

    return err_cnt;
}

int test_process(void)
{
    printf("----------: %s :----------\n", __func__);
    int err_cnt = 0;
    /* TODO add tests
    int i = 0;

    {
        i++;
        printf("Test number %i: ", i);
        // ----------------------------------------------------------
        if (1)
            printf("PASSED\n");
        else
        {
            err_cnt++;
            printf("DIDN'T PASSED\n");
        }
    }
    */

    return err_cnt;
}

int main(void)
{
    int errs = 0;

    errs += test_split();
    errs += test_process();

    printf("\n\nTOTAL ERRORS: %i", errs);

    return 0;
}
