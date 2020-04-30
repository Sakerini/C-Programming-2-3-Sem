#include<stdio.h>
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

int len_m(int n)
{
    int size, check = n;
    while (check % 10 != 0)
    {
        check = check/10;
        size++;
    }
    return size;
}

int input_data(int *n, int *m)
{
    int rc = OK;
    printf("Input number: ");
    if (scanf("%d", n) != 1)
    {
        printf("Error: this is not a number");
        rc = ERR_IO;
    }
    else
    {
        printf("Input m: ");
        if (scanf("%d", m) != 1)
        {
            rc = ERR_IO;
            printf("Error: this is not a number");
        }
    }
    return rc;
}

int summa(int n, int m)
{
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        res += n % 10;
        n = n / 10;
    }
    return res;
}



int main(void)
{
    int n, m, rc = OK;
    setbuf(stdout, NULL);
    if (input_data(&n, &m) != 0)
        rc = ERR_IO;
    else
    {
        printf("size of n is: %d symbols \n", len_m(n));
        if (m > len_m(n))
        {
            printf("Error n < m");
            rc = ERR_RANGE;
        }
        else
            printf("The result is : %d \n", summa(n, m));
    }
    return rc;

}
