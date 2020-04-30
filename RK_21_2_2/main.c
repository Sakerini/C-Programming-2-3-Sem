#include<stdio.h>
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define N_MAX 10

int input_arr(int *a, int *n)
{
    int rc = OK;
    printf("Input size of the array: ");
    if (scanf("%d", n) != 1)
        rc = ERR_IO;
    else
    {
        if (n <= 0)
            rc = ERR_RANGE;
        else
        {
            printf("input elements:\n");
            for (int i = 0; i < *n; i++)
            {
                if (scanf("%d", &a[i]) != 1)
                    rc = ERR_IO;
            }
        }
    }
    return rc;
}

void print_arr(const int *a, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int find_numbers(const int *a, int n)
{
    int position = -1;
    for (int i = 0; i < n; i++)
    {
        for (int k = i+1; k < n; k++)
        {
            if (a[i] == a[k])
                position = k;
        }
    }
    return position;
}

void del_number(int *a, int *n, int position)
{
    int c;
    for (int i = position; i < *n - 1; i++)
    {
        c = a[i];
        a[i] = a[i + 1];
        a[i + 1] = c;
    }
    *n -= 1;
}

int main(void)
{
    int a[N_MAX], n, rc = OK, pos;
    setbuf(stdout, NULL);
    if (input_arr(a, &n) != 0)
    {
        rc = ERR_IO;
        printf("error!!");
    }
    else
    {
        printf("\n");
        printf("Our ARRAY \n");
        print_arr(a, n);
        printf("\n");
       // for (int i = 0; i < n; i++)
        //{
            //printf("find_numbers = %d \n", find_numbers(a, n));
            while (find_numbers(a, n) != -1)
            {
                pos = find_numbers(a, n);
                del_number(a, &n, pos);
            }
        printf("Array after: \n");
        print_arr(a, n);
        printf("\n");
    }
    return rc;
}
