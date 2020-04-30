#include "err.h"
#include "io.h"

/**
 * @brief Функция ввода и вывода гамма и ро с проверкой
 * 
 * @param ro Ро
 * @param gamma Гамма 
 * @return int код ошибки
 */
int in_ro_gamma(int *ro, int *gamma)
{
    printf("\nInput ro and gamma:");
    if (scanf("%d%d", ro, gamma) != 2)
        return ERR_IO;
    
    if (*ro < 0 || *gamma < 0)
        return ERR_IO;

    return OK;
}

/**
 * @brief Функция освобождение памяти матрица
 * 
 * @param arr_ptrs Матрица
 * @param n Кол-во строк
 */

void matrix_free(int64_t **arr_ptrs, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr_ptrs[i] != NULL)
        {
            free(arr_ptrs[i]);
            arr_ptrs[i] = NULL;
        }
    }
    if (arr_ptrs != NULL)
    {
        free(arr_ptrs);
        arr_ptrs = NULL;
    }
}

/**
 * @brief Фунцкия локализации памяти для матрицу
 * 
 * @param n нужные строки
 * @param m нужные столбцы
 * @return int64_t** Указатель на матрицу
 */

int64_t **matrix_alloc(int n, int m)
{
    int64_t **arr_ptrs = calloc(n, sizeof(int64_t *));
    if (!arr_ptrs)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        arr_ptrs[i] = malloc(m * sizeof(int64_t));
        if (!arr_ptrs[i])
        {
            matrix_free(arr_ptrs, n);
            return NULL;
        }
    }
    return arr_ptrs;
}

/**
 * @brief Функция ввода матрицу
 * 
 * @param ptrs Матрица
 * @param n Рамзер строки
 * @param m Размер столбцы
 * @return int код ошибки
 */

int matrix_input(int64_t **ptrs, int n, int m)
{
    assert(ptrs != NULL);

    printf("\n====== Input Matrix ======\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter elements of the row: ");
        for (int j = 0; j < m; j++)
            if (scanf("%li", &ptrs[i][j]) != 1)
                return ERR_IO;
    }
    return OK;
}

/**
 * @brief Функция создать матрицу
 * 
 * @param arr_ptrs Матрица
 * @param n Строки
 * @param m Столбец
 * @return int код ошибки
 */
int matrix_create(int64_t ***arr_ptrs, int *n, int *m)
{
    assert(arr_ptrs != NULL);

    int64_t **ptrs = NULL;
    int rc = OK;
    printf("Input n and m: ");
    if (scanf("%d%d", n, m) != 2)
        return ERR_IO;
    
    if (*n <= 0 || *m <= 0)
    {
        return ERR_IO;
    }

    ptrs = matrix_alloc(*n, *m);
    if (!ptrs)
        return ERR_IO;
    rc = matrix_input(ptrs, *n, *m);
    if (rc != OK)
    {
        matrix_free(ptrs, *n);
        return ERR_IO;
    }
    *arr_ptrs = ptrs;
    return rc;
}

/**
 * @brief Функция выводить матрица на экран
 * 
 * @param arr_ptrs Матрица
 * @param n Строка
 * @param m Столбец
 */
void matrix_print(int64_t **arr_ptrs, int n, int m)
{
    assert(arr_ptrs != NULL);
    
    printf("\nArray\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("% " PRId64 "", arr_ptrs[i][j]);
        printf("\n");
    }
}
