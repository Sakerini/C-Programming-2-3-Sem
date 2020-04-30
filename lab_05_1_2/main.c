#include<stdio.h>
#include<stdlib.h>
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

void mtr_print(int a[][N_MAX], int n, int m, int *rc)
{
    printf("Matrix \n");
    if (n + 1 == 1 || m + 1 == 1)
    {
        printf("This matrix is empty");
        *rc = ERR_RANGE;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
}

/* функция которая удаляет столбцы и строки
 * параметры которые задаем
 * int Матрица int *строки int *столбец int номерстрока int номер столбец
 * возвращет преобразованый массив
 */
void delete_line_and_column(int a[][N_MAX], int n, int m, int line, int column)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = column; j < m; j++)
        {
            if (j < m - 1)
                a[i][j] = a[i][j + 1];
        }
    }

    for (int i = line; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < n - 1)
                a[i][j] = a[i + 1][j];
        }
    }
}
/*
 * Функция которая ищет суму елемента
 * параметры которые предаем
 * елемент
 * сумма
*/

int sum_numbers(int number)
{
    number = abs(number);
    int result = 0;
    while (number != 0)
    {
        result += number % 10;
        number = number / 10;
    }
    return result;
}
/*
 * Функция которая ищет суму минимального елемента их позиции
 * параметры которые предаем
 * Матрица, строка, столбец, позиция_строки, позиция_столбец
 * возвращает позиции
 */
void find_min(int a[][N_MAX], int n, int m, int *pos_i, int *pos_j)
{
    int position_i = 0, position_j = 0, min_sum = sum_numbers(a[0][0]), x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            x = sum_numbers(a[i][j]);
            if (x < min_sum)
            {
                min_sum = x;
                position_i = i;
                position_j = j;
            }
        }
    *pos_i = position_i;
    *pos_j = position_j;
    //printf("you re deleting %d row and %d collumn \n", pos_i, pos_j);
    //printf("The min element sum is %d \n", min_sum);
}

int main(void)
{
    int rc = OK;
    int a[N_MAX][N_MAX], n, m, pos_i, pos_j;
    setbuf(stdout, NULL);

    if (mtr_input(a, &n, &m) != 0)
        rc = ERR_IO;
    else
    {
        //printf("%d",sum_numbers(abs(-5617)));
        find_min(a, n, m, &pos_i, &pos_j);
        delete_line_and_column(a, n, m, pos_i, pos_j);
        mtr_print(a, n - 1, m - 1, &rc);
        //printf("%d", sum_numbers(-5112));
    }
    return rc;
}

