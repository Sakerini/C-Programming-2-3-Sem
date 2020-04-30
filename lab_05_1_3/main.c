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
int mtr_input(int a[][N_MAX], int *n, int *m)
{
    int rc = OK; // rc код ошибка
    printf("Input rows and collumns of the matrix \n");
    if (scanf("%d%d", n, m) == 2)
    {
        if (1 <= *n && *n <= N_MAX && 1 <= *m && *m <= N_MAX)
        {
            printf("Input element of the matrix by rows \n");
            for (int i = 0; i < *n; i++)
                for (int j = 0; j < *m; j++)
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
void mtr_print(int a[][N_MAX], int n, int m)
{
    printf("Matrix \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
/*
 * Функция которая ищет максимум в массиве
 * Параметры (int Матрица, int строки, int столбци)
 * вовращет максимум в строке
 */

int max_find(int a[][N_MAX], int i, int m)
{
    int max = a[i][0];
    for (int j = 1; j < m; ++j)
        if (max < a[i][j])
            max = a[i][j];
    return max;
}

/*
 * Функция которая сортирует строки массива
 * Параметры (int Матрица, int строки, int столбци)
 * ничего не возвращает, кроме уже сортированый массив
 */

void swap_lines(int *a, int *b, int m)
{
    int temp[N_MAX];

    for (int k = 0; k < m; k++)
    {
        temp[k] = a[k];
        a[k] = b[k];
        b[k] = temp[k];
    }
}

void sorted(int a[][N_MAX], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (max_find(a, j, m) < max_find(a, i, m))
            {
                swap_lines(a[i], a[j], m);
            }
        }
    }
}

int main(void)
{
    int a[N_MAX][N_MAX], n, m, rc = OK;
    setbuf(stdout, NULL);
    if (mtr_input(a, &n, &m) == 0)
    {
        sorted(a, n, m);
        mtr_print(a, n, m);
    }
    else
    {
        rc = ERR_IO;
        printf("Error!!! \n");
    }
    return rc;
}
