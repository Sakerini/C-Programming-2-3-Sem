#include "err.h"
#include "delete.h"
#include "find.h"

/**
 * @brief Функция создает место для новая строка
 * 
 * @param ptrs матрица
 * @param n размер строки
 * @param m размер столбца
 * @return int код ошибки
 */
int row_allocate(int64_t ***ptrs, int *n, int m)
{
    assert(ptrs != NULL);

    int rc = OK;
    rc = rows_resize(ptrs, n, *n + 1);
    if (rc != OK)
        return rc;
    
    (*ptrs)[*n - 1] = malloc(m * sizeof(int64_t));
    if (!(*ptrs)[*n - 1])
        return ERR_MEM_ALLOC;

    return rc;
}

/**
 * @brief Функция добавляет средное геометрическое на позицию посдлений элемент в строке
 * 
 * @param ptrs матрица
 * @param n размер строка 
 * @param m размер столбец
 */
void insert_geom_mean(int64_t **ptrs, int n, int m)
{
    assert(ptrs != NULL);

    for (int coll = 0; coll < m; coll++)
    {
        int64_t mean = geometric_mean(ptrs, n - 1, coll);
        //printf("\n %ld", mean);
        ptrs[n - 1][coll] = mean;
    }
}

/**
 * @brief Фунцкия создает место для новый столбец
 * 
 * @param ptrs Матрица
 * @param n размер строки
 * @param m размер столбца
 * @return int код ошибки
 */
int collumn_allocate(int64_t ***ptrs, int n, int *m)
{
    assert(ptrs != NULL);

    int rc = OK;
    for (int row = 0; row < n; row++)
    {
        rc = collumn_resize(&(*ptrs)[row], *m, *m + 1);
        if (rc != OK)
            return rc;
    }
    *m = *m + 1;
    return rc;
}

/**
 * @brief Функция добавляет в последний элемент строки минимальный элемент
 * 
 * @param ptrs Матрица
 * @param n размер строки
 * @param m размер столбца
 */
void collumn_insert(int64_t **ptrs, int n, int m)
{
    assert(ptrs != NULL);

    for (int i = 0; i < n; i++)
    {
        ptrs[i][m - 1] = min_in_row(ptrs, i, m - 1);
    }
}

/**
 * @brief Функция делает матрица данного размера чрез добавление элементы
 * 
 * @param ptrs Матрица
 * @param n текущий размер строка
 * @param m текущий резмер столбца
 * @param new_size размер желаемая квадратная матрица
 * @return int код ошибки
 */

int matrix_grow(int64_t ***ptrs, int *n, int *m, int new_size)
{
    assert(ptrs != NULL);
    
    int rc = OK;
    while (*n != new_size)
    {
        rc = row_allocate(ptrs, n, *m);
        if (rc != OK)
            return rc;

        insert_geom_mean(*ptrs, *n, *m);
    }
    while (*m != new_size)
    {
        rc = collumn_allocate(ptrs, *n, m);
        if (rc != OK)
            return rc;
        collumn_insert(*ptrs, *n, *m);
    }

    return rc;
}