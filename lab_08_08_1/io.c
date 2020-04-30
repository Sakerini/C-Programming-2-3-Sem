#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "io.h"
#include "err.h"

/**
 * @brief print_arr Функция выводить массив на екран
 * @param elem указатель на начало массива
 * @param end указатель на конец массива
 */
void print_arr(const double *elem, const double *end)
{
    assert(elem != NULL);
    assert(end != NULL);
    assert(elem < end);

    printf("Array:\n");
    for (;elem < end; elem++)
        printf("%lf ", *(elem));
    printf("\n");
}

/**
 * @brief read_arr Функция которая считывает елементы и добавляет в массив
 * @param elem указатель на начало массива
 * @param end указатель на конец массива
 * @return
 */
static bool read_arr(double *elem, double *end)
{
    assert(elem != NULL);
    assert(end != NULL);
    assert(elem < end);

    for (;elem < end && scanf("%lf", elem) == 1; elem++);
    return elem == end;
}
/**
 * @brief input Функция ввода массива
 * @param beg указатель на начало массива
 * @param end указатель на конец массива
 * @return код ошибки
 */
int input(double **beg, double **end)
{
    long size = 0;
    double *a = NULL;
    printf("Enter size of the array:\n");
    if (scanf("%ld", &size) != 1 || size <= 2)
        return ERR_IO;

    a = malloc(size * sizeof(double));

    if (!a)
    {
        return ERR_MEM_ALLOC;
    }

    *beg = a;
    *end = a + size;
    printf("Enter elements: ");
    if (!read_arr(*beg, *end))
    {
        return ERR_IO;
    }
    return ERR_OK;
}

/**
 * @brief input_p Функция ввода позиции p
 * @param p позиция p
 * @param beg указатель на начало массива
 * @param end указатель на конец массива
 * @return код ошибки
 */
int input_p(int *p, const double *beg, const double *end)
{
    assert(beg != NULL);
    assert(end != NULL);
    assert(beg < end);

    printf("Enter position: ");
    if (scanf("%d", p) != 1)
        return ERR_IO;

    int size = end - beg;
    if (*p < 0 || *p > size)
        return ERR_RANGE;
    return ERR_OK;
}
