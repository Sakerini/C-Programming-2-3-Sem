#include<stdio.h>
#include<math.h>
#define OK 0                 // Если ввод правильный
#define ERR_IO 1             // при ошибке ввода
#define ERR_RANGE 2          // При ошибка размера ввода
#define N_MAX 10             // Максимальный размер массива
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
/* Считает все элементы которые
 * не деляться на 2 и возвращает произведение
 * и код ошибки
 * Параметы (Масив с числамы, размер массива, результат который выводим)
*/
int s_arr(int *array, int n, int *res)
{
    int summa = *res, found = 0;         // Сумма которую мы выводим
    for (int i = 0; i < n; i++)
    {
        //printf("%d", -5 % 2);
        if ((array[i]) % 2 == 1 || (array[i] % 2 == -1))
        {
            summa *= array[i];
            found++;
        }
    }

    if (found == 0)
    {
        return ERR_IO;
    }
    else
        *res = summa;
    return OK;
}

int main(void)
{
    int y, result = 1, rc = OK;      // y - Размер массива, е - элемент массива rc - P
    int a[N_MAX];
    setbuf(stdout, NULL);
    if (arr_input(a, &y) == 0)
        if (s_arr(a, y, &result) == 0)
            printf("%d", result);
        else
        {
            printf("Error");
            rc = ERR_IO;
        }
    else
    {
        printf("ERROR");
        rc = ERR_IO;
    }
    return rc;
}
