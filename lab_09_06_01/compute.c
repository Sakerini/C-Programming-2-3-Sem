#include "err.h"
#include "io.h"

/**
 * @brief Функция умножает две матрицы
 * 
 * @param mat_a матрица один
 * @param mat_b матрица два
 * @param mat_c результатная матрица от умножения
 * @param size размер матриц
 */
void multi(int64_t **mat_a, int64_t **mat_b, int64_t **mat_c, int size)
{
    assert(mat_a != NULL);
    assert(mat_b != NULL);
    assert(mat_c != NULL);

    for (int i = 0;i < size ;i++)
        for (int j = 0; j < size ; j++)
        {
            mat_c[i][j] = 0;
            for (int k = 0; k < size ; k++)
                mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
        }
}

/**
 * @brief Функция которая копирает динамическую матрицу 
 * 
 * @param mat_a динамическая матрица
 * @param mat_b динамическая матрица
 * @param n размер строки
 * @param m размер столбца
 */
void dyn_mat_cpy(int64_t **mat_a, int64_t **mat_b, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //mat_b[i][j] = 0;
            mat_b[i][j] = mat_a[i][j];
        }
    }
}

/**
 * @brief Функция умножает две матрицы
 * 
 * @param mat_a матрица один
 * @param mat_b матрица два
 * @param n размер матриц
 * @return int64_t** 
 */

void multiply_matrix(int64_t **mat_a, int64_t **mat_b, int n)
{
    assert(mat_a != NULL);
    assert(mat_b != NULL);

    int64_t **mat_res;                              
    mat_res = matrix_alloc(n, n);  // RESULT MATRIX ALLOCATED!!
    if (mat_res == NULL)
    {
        mat_res = NULL;
    }
    else
    {
        multi(mat_a, mat_b, mat_res, n);
        dyn_mat_cpy(mat_res, mat_b, n, n);

        matrix_free(mat_res, n);
    }
}

void single_matrix(int64_t **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
}

/**
 * @brief Функция Умножает матриц через ро и гамма А^ro * B^gamma
 * 
 * @param mat_a матрица один
 * @param mat_b матрица два
 * @param n размер матриц
 * @param ro ро
 * @param gamma гамма 
 */

void computation(int64_t ***mat_a, int64_t ***mat_b, int n, int ro, int gamma)
{
    assert(mat_a != NULL);
    assert(mat_b != NULL);
    int64_t **temp;
    temp = matrix_alloc(n, n);
    if (ro == 0)
    {
        single_matrix(*mat_a, n);
    }
    else
    {
        dyn_mat_cpy(*mat_a, temp, n, n);
        for (int i = 0; i < ro - 1; i++)
            multiply_matrix(*mat_a, temp, n);
        dyn_mat_cpy(temp, *mat_a, n, n);
    }

    if (gamma == 0)
    {
        single_matrix(*mat_b, n);
    }
    else
    {
        dyn_mat_cpy(*mat_b, temp, n, n);
        for (int i = 0; i < gamma - 1; i++)
            multiply_matrix(*mat_b, temp, n);
        dyn_mat_cpy(temp, *mat_b, n, n);
    }
    matrix_free(temp, n);
    
    multiply_matrix(*mat_a, *mat_b, n);
}   