#include<stdio.h>
#define OK 0                 // Если ввод правильный
#define ERR_IO 1             // при ошибке ввода
#define ERR_RANGE 2
#define N_INPUT_MAX 10
#define N_MAX 20              // Максимальный массив

/* ввод элементы массива
 * (массив, размер массива)
 * Возврощает массив и его число
 * Возврощает код ошибки
*/
int arr_input(int *a, int *n)
{
    printf("Input n:");
    if (scanf("%d", n) != 1)
        return ERR_IO;
    if (*n <= 0 || *n > N_INPUT_MAX)
        return ERR_RANGE;
    for (int i = 0; i < *n ; i++)
    {
        printf("Input element: ");
        if (scanf("%d", &a[i]) != 1)
            return ERR_IO;
    }
    return OK;
}

/*
 * Функция вывода массива
 * Параметры (const int массив, int размер массива)
 * возвращает числа массива на екран
*/
void arr_print(int *a, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* Функция которая считает число фиббоначи
 * Параметры (int Номер число)
 * Возвращает число фиббоначи
*/
int fib(int n)
{
    int fib1 = 1, fib2 = 1;
    if (n == 0)
        fib2 = 0;
    else
    {
        for (int i = 2; i < n; i++)
        {
            fib2 = fib1 + fib2;
            fib1 = fib2 - fib1;
        }
    }
    return fib2;
}
/*
 * Функция вставляет число фиббоначи
 * параметры (int *Массив int *размер массива, int позиция, int число)
*/

void add_element(int *a, int *size, int pos, int fib_n)
{
    int n = *size;
    for (int j = 1; j < n - pos; j++)
    {
        a[n - j + 1] = a[n - j];
    }
    n += 1;
    a[pos + 1] = fib_n;

    *size = n;
}


/*
 * Функция вставляет число фиббоначи после каждое
 * число в массиве кратно трем
 * параметры (int *Массив int *размер массива)
*/
void put_fib(int *a, int *size)
{
    int fib_n = 0, n = *size;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 3 == 0)
        {
            add_element(a, &n, i, fib(fib_n));
            fib_n++;
            i++;
        }
    }
    *size = n;
}

int main(void)
{
    /*
      а - массив , size_a - размер массива, rc - Проверка, fib_n - номер число фибоначи ,
      с переменая нужна для смена местами в массиве
      p - счетчик j - счетчик
    */
    int a[N_MAX], size_a, rc = OK;
    setbuf(stdout, NULL);
    if (arr_input(a, &size_a) != 0)
    {
        rc = ERR_IO;
        printf("Error!");
    }
    else
    {
        put_fib(a, &size_a);
        arr_print(a, size_a);
    }
    return rc;
}
