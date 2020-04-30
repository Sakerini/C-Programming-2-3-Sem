#include "err.h"
#include "find.h"

/**
 * @brief Функция ищет минимум в матрице
 * 
 * @param ptrs Матрица
 * @param n размер строка
 * @param m размер столбец
 * @param pos_n индекс позиции строке
 * @param pos_m индекс позиции столбце
 */
void find_min(int64_t **ptrs, int n, int m, int *pos_n, int *pos_m)
{
    assert(ptrs != NULL);

    int64_t minimum_element = ptrs[0][0];
    int r = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ptrs[i][j] < minimum_element)
            {
                minimum_element = ptrs[i][j];
                r = i;
                c = j;
            }
        }
    }
    *pos_n = r;
    *pos_m = c;
}

/**
 * @brief Функция ищет минимум в строке в матрице
 * 
 * @param ptrs Матрица
 * @param row строка 
 * @param elements элементы
 * @return int64_t минимум
 */
int64_t min_in_row(int64_t **ptrs, int row, int elements)
{
    assert(ptrs != NULL);

    int64_t minimum = ptrs[row][0];
    for (int i = 0; i < elements; i++)
        if (ptrs[row][i] < minimum)
            minimum = ptrs[row][i];
    return minimum;
}

/**
 * @brief Функция ищет средное геометрическое
 * 
 * @param ptrs Матрица
 * @param rows строка
 * @param collumn столбец
 * @return int64_t средное геометрическое
 */
int64_t geometric_mean(int64_t **ptrs, int rows, int collumn)
{
    assert(ptrs != NULL);
    int64_t mean = 1;
    int64_t result = 0;
    for (int i = 0; i < rows; i++) 
        mean = mean * ptrs[i][collumn];

    result = pow(abs(mean), (float) 1 / rows);
    return result;
    /*
    while (1)
    {
        if (pow(result, rows - 1) <= abs(mean) && abs(mean) <= pow(result, (rows)))
            return result - 1;
        result++;
    }
    */
}