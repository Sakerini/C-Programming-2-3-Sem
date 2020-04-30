#include "add_or_delete.h"
#include "process.h"
#include "err.h"
#include <assert.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief find_element Функция ищет елемент с максимальную разницу
 * @param beg указатель на начало массива
 * @param end указатель на конец массива
 * @param miu переменная в которая храним результат
 * @return указатель на найденый елемент
 */
double *find_element(double *beg, const double *end, double miu)
{
    assert(beg != NULL);
    assert(end != NULL);
    assert(beg < end);

    double max_diff = fabs(fabs(miu) - fabs(*beg));
    double *pos = beg;

    for (;beg < end; beg++)
    {
        double cur_diff = fabs(fabs(miu) - fabs(*beg));
		//printf(" \n CUR DIFF = %lf \n", cur_diff);
        if (cur_diff > max_diff)
        {
            max_diff = cur_diff;
            pos = beg;
        }
    }
	//printf(" \n MAX DIFF = %lf \n", max_diff);
    return pos;
}

/**
 * @brief del_element Функция удаляет елемент из массива
 * @param beg указатель на начало массива
 * @param end указатель на конец массива
 */
void del_element(double *beg, double *end)
{
    assert(beg != NULL);
    assert(end != NULL);
    assert(beg < end);

    for (;beg < end - 1; beg++)
    {
        *beg = *(beg + 1);
    }
}

/**
 * @brief change_arr_size Функция перевыделяет память для массива
 * @param array указатель на начало массива, сам массив
 * @param size размер
 */
int change_arr_size(double **array, int *size, int newn)
{
    if (*size == newn)
        return ERR_OK;
    double *buf = (double *) realloc(*array, newn * sizeof(double));
    if (buf)
    {
        *array = buf;
        buf = NULL;
        *size = newn;
        return ERR_OK;
    }
    return ERR_MEM_ALLOC;
}
/**
 * @brief add Функция вставляет елемент на нужную позицию
 * @param beg указатель на начало массива
 * @param end указатель на конец массива
 * @param position позиция где мы вставим мю
 * @param miu значение мю
 */
void add(double *beg, double *end, int position, double miu)
{
    assert(beg != NULL);
    assert(end != NULL);
    assert(beg < end);
    assert(position >= 0);
    assert(position < end - beg);

    for (; end != (beg + position); end--)
    {
        *(end) = *(end - 1);
    }
    *(beg + position) = miu;
}

/**
 * @brief add_element Функция добаваляет 3 елемента в массив
 * @param beg указатель на начало массива
 * @param end указатель на конец массива
 * @param miu значение мю
 * @param p позиция где мы вставим мю
 */
void add_element(double *beg, double *end, double miu, int p)
{
    assert(beg != NULL);
    assert(end != NULL);
    assert(beg < end);
	
    add(beg, end - 1, p, miu);
    add(beg, end - 1, 0, miu);
    *(beg + ((end - beg) - 1)) = miu;
}
int complete_delete(double **beg, double **end, double *position)
{
    int rc = ERR_OK;
    int size = *end - *beg;
    del_element(position, *end);
    rc = change_arr_size(beg, &size, size - 1);
    if (rc == ERR_OK)
    {
        *end = *beg + size;
    }
    return rc;
}
