#include "process.h"
#include <assert.h>

/**
 * @brief compute_miu1 Функция которая вычисляет МЮ1
 * @param beg указатель на начало массива
 * @param end указатель на конец массива
 * @return результат вычисления
 */
double compute_miu1(const double *beg, const double *end)
{
    assert(beg != NULL);
    assert(end != NULL);
    assert(beg < end);

    double summ1 = 0;
    double summ2 = 0;
    double result = 0;
    for (int i = 1 ;beg < end; beg++)
    {
        summ1 += (((i) * (i)) * (*(beg)));
        summ2 += (i) * (i);
        i++;
    }
    result = summ1 / summ2;
    return result;
}

/**
 * @brief compute_miu2 Функция которая вычисляет МЮ1
 * @param beg указатель на начало массива
 * @param end указатель на конец массива
 * @return результат вычисления
 */
double compute_miu2(const double *beg, const double *end)
{
    assert(beg != NULL);
    assert(end != NULL);
    assert(beg < end);

    int size = end - beg;
    double summ1 = 0;
    double result = 0;
    for (;beg < end; beg++)
    {
        summ1 += *(beg);
    }
    result = summ1 / size;
    return result;
}
