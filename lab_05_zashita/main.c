#include<stdio.h>
#define ERR_IO 1  // Ошибка Ввода/ Вывода
#define ERR_RANGE 2  // Ошибка диапазона
#define OK 0  // Все в порядке
#define N_MAX 10  // Максимальный размер

/*
 * Функция которая вводит размаер массива и елементы массива
 * передаем как параметры
 * int Матрица, int *строки,int *столбцы
 * Возвращает матрица, и код ошибки
*/
int mtr_input(int a[][N_MAX], int *n)
{
    int rc = OK; // rc код ошибка
    printf("Input rows and collumns of the matrix \n");
    if (scanf("%d", n) == 1)
    {
        if (1 < *n && *n <= N_MAX)
        {
            printf("Input element of the matrix by rows \n");
            for (int i = 0; i < *n; i++)
                for (int j = 0; j < *n; j++)
                    if (scanf("%d", &a[i][j]) != 1)
                    {
                        rc = ERR_IO;
                        printf("Error");
                    }
        }
        else
        {
            rc = ERR_RANGE;
            printf("Error");
        }
    }
    else
    {
        rc = ERR_IO;
        printf("Error");
    }
    return rc;
}

/*
 * Функция которая выводить матрица на екран
 * Параметры (int Матрица, int строки, int столбци)
 * Возвращает ничего, кроме матрицу на екран
 */
void mtr_print(int a[][N_MAX], int n)
{
    printf("Matrix \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int max_under1(int a[][N_MAX], int n)
{
    int max = a[1][n-1];
    for (int i = n-1; i > 1; i--)
    {
        for (int j = n-1; j > 1; j--)
        {
            printf("%d ", a[i][j]);
            if (a[i][j] > max)
                max = a[i][j];
        }
    }
    return max;
}

int max_under(int a[][N_MAX], int n)
{
    int max = a[1][n-1];
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }
    }
    return max;
}

int max_upper(int a[][N_MAX], int n)
{
    int max = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }
    }
    return max;
}

void print_upper(int a[][N_MAX], int n)
{
    printf("Elements under:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");
}


void print_under(int a[][N_MAX], int n)
{
    printf("Elements under:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");
}


int main(void)
{
    int a[N_MAX][N_MAX], n, rc = OK;
    setbuf(stdout, NULL);
    if (mtr_input(a, &n) == 0)
    {
        print_under(a, n);
        print_upper(a, n);
        printf("The max under is: %d\n", max_under(a, n));
        printf("The max upper is: %d\n", max_upper(a, n));
    }
    else
    {
        rc = ERR_IO;
        printf("Error!!! \n");
    }
    return rc;
}
