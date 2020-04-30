#include "str.h"
#include "err.h"

#include <string.h>
#include <stdio.h> // TODO delete

/**
 * @brief split Разделяет строку на массив указателей на строку. Каждая строка, есть новое слово
 * 
 * @param text[in] строка
 * @param split[out] Массив указатели на слова
 * @param split_size[in][out] На входе макс размер массива, на выходе количество слов
 */
int split(char *text, char **split, int *split_size)
{
    int len = strlen(text);
    int j = 0; // Curr pos in split
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
            text[i] = 0;
        else if (i == 0 || text[i - 1] == 0)
        {
            if (j == *split_size)
            {
                return ERR_SIZE;
            }

            split[j++] = text + i;
        }
    }
    *split_size = j;
    if (j == 0)
        return ERR_EMPTY;

    return OK;
}

/**
 * @brief Меняет местами самого длиного и самого кароткого слов
 * 
 * @param words Массив слов
 * @param n Количество слов
 */
void process(char **words, int n)
{
    if (n == 0)
        return;
    int len_biggest = strlen(words[0]);
    int len_smallest = strlen(words[0]);
    int biggest = 0;
    int smallest = 0;

    for (int i = 1; i < n; i++)
    {
        int len_curr = strlen(words[i]);
        if (len_curr > len_biggest)
        {
            len_biggest = len_curr;
            biggest = i;
        }

        if (len_curr < len_smallest)
        {
            len_smallest = len_curr;
            smallest = i;
        }
    }

    // swap
    char *tmp = words[biggest];
    words[biggest] = words[smallest];
    words[smallest] = tmp;
}