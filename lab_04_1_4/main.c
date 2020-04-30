#include<stdio.h>
#define OK 0                 // Если ввод правильный
#define ERR_IO 1             // при ошибке ввода
#define ERR_RANGE 2
#define N_MAX 10              // Максимальный массив
#define TRUE 0
#define FALSE 1

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

/*
 * Функция которая сортирует массив метод вставкам
 * Параметры (int *массив, int размер массива)
 * Возвращает отсортированный массив
*/
void sorted(int *array, int size)
{
    int v, j; // v, j - позиции в массиве
    for (int i = 0; i < size; i++)
    {
        v = array[i];
        j = i;
        while (array[j - 1] > v && j > 0)
        {
            array[j] = array[j - 1];
            j = j - 1;
            array[j] = v;
        }
    }
}

/*
 * Функция которая сортирует массив метод пузырка
 * Параметры (int *массив, int размер массива)
 * Возвращает отсортированный массив
*/

void bubblesort(int *arr, int n)
{
    int c, flag = TRUE;

    while (!flag)
    {
        flag = FALSE;
        for (int j = 0; j < n - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                c = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = c;
                flag = TRUE;
            }
        //printf("%d", flag);
    }
}

int main(void)
{
    int array[N_MAX], size_a, rc = OK; // size_a - Размер массива rc - Проверка
    setbuf(stdout, NULL);
    if (arr_input(array, &size_a) != 0)
    {
        rc = ERR_IO;
        printf("Error!!!");
    }
    else
    {
        bubblesort(array, size_a);
        arr_print(array, size_a);
    }
    return rc;
}
