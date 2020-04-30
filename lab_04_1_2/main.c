#include<stdio.h>
#define OK 0                 // Если ввод правильный
#define ERR_IO 1             // при ошибке ввода
#define ERR_RANGE 2
#define N_MAX 10              // Максимальный массив

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
    if (*n <= 0 || *n > N_MAX)
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
 * Функция проверяет если число является простое,
 * параметры (int Число)
 * Возвращает 0 или 1 как резултат
*/
int is_prime(int n)
{
    int d = 2, answer;    // d - делитель answer ответ
    if (n == 1 || n == 0 || n < 0)
        answer = 1;
    else
    {
        while (d * d <= n && n % d != 0)
            d += 1;
        if (d * d > n)
            answer = 0;
        else
            answer = 1;
    }
    return answer;
}
/*
 * Функция добавляет все найдены простые елементы
 * в второй массив
 * параметры (const int первый массив, int размер массива ,int второй массив,int размер)
 * возвращает массив с простые числа или Ошибка
*/
int new_arr(const int *array_a, int size_a, int *array_b, int *size_b)
{
    int size = 0;
    for (int i = 0; i < size_a; i++)
    {
        if (is_prime(array_a[i]) == 0)
        {
            array_b[size] = array_a[i];
            size += 1;
        }
    }
    if (size == 0)
        return ERR_RANGE;
    else
    {
        *size_b = size;
        return OK;
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
    int a[N_MAX], b[N_MAX];  // Массивы а и б
    int size_a, size_b, rc = OK; //размер масивы
    setbuf(stdout, NULL);
    if (arr_input(a, &size_a) != 0)
    {
        rc = ERR_IO;
        printf("ErRor");
    }
    if (rc == OK)
    {
        if (new_arr(a, size_a, b, &size_b) != OK)
        {
            rc = ERR_IO;
            printf("Error");
        }
        if (rc == OK)
            arr_print(b, size_b);
    }
    return rc;
}
