#include "io.h"
#include "err.h"

#include <string.h>

/**
 * @brief freadline (функция которая читает строку)
 * 
 * @param f Файл, с которого читает
 * @param str где записывается прочетеная строка
 * @param str_size размер str
 */
int freadline(FILE *f, char *str, int str_size)
{
    if (fgets (str, str_size, f) == NULL)
        return ERR_IO;
    char *newline = strchr(str, '\n');
    if (newline)
        *newline = 0;
    if (strlen(str) == 0) 
        return ERR_IO;

    return OK;
}

void print(FILE *f, char **str, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s ", str[i]);
        printf("%s ", str[i]);
    }

    fprintf(f, "\n");
    puts("");
}
