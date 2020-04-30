#include<stdio.h>
#define ERR_IO 1  // Ошибка Ввода/ Вывода
#define ERR_RANGE 2  // Ошибка диапазона
#define OK 0  // Все в порядке
#define FALSE 0 // условие не выполнено
#define TRUE 1 // Условие выполнено
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
                        rc = ERR_IO;
        }
        else
            rc = ERR_RANGE;
    }
    else
        rc = ERR_IO;
    return rc;
}
/*
 * Функция которая создает новый массив b из матрицу,
 * проверяет если строка симетричная и вставляет на позицию k
 * в новом массиве 1 если условие выполнено и 0 если не выполнено
 * параметры которые задаем
 * (int Матрица int строки int столбци int массив)
 * возврощает код ошибки
 */

int is_simmetrical(const int *a, int m)
{
    int simmetrical = TRUE;
    for (int j = 0; j < m; j++)
    {
        if (a[j] != a[m - 1 - j])
            simmetrical = FALSE;
    }
    return simmetrical;
}

/*
 * Функция которая создает новый массив b из матрицу,
 * проверяет если строка симетричная и вставляет на позицию k
 * в новом массиве 1 если условие выполнено и 0 если не выполнено
 * параметры которые задаем
 * (int Матрица int строки int столбци int массив)
 * возврощает код ошибки
 */

void new_arr(int a[][N_MAX], int n, int m, int *b)
{
    for (int stroka = 0; stroka < n; stroka++)
    {
        b[stroka] = is_simmetrical(a[stroka], m);
    }
}
/*
 * Функция вывода массива
 * Параметры (const int массив, int размер массива)
 * возвращает числа массива на екран
*/

void arr_print(const int *a, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main(void)
{
    int a[N_MAX][N_MAX], b[N_MAX], n, m, rc = OK;
    setbuf(stdout, NULL);
    if (mtr_input(a, &n, &m) != 0)
    {
        rc = ERR_IO;
        printf("Error input output!!!");
    }
    else
    {
        new_arr(a, n, m, b);
        arr_print(b, n);
    }
    return rc;
}
