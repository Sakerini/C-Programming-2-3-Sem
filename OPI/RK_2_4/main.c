#include<stdio.h>
#include<string.h>

#include "io.h"
#include "err.h"
#include "str.h"

#define MAX_STR_LEN 128
#define MAX_WORDS_NUMBER MAX_STR_LEN/2

int main(int argc, char **argv)
{
    int rc = OK;
    if (argc != 3)
    {
        puts("WRONT INPUT FILES IN CMD");
        puts("Usage: app f_in f_out");
        rc = ERR_ARGC;
    }
    else
    {
        FILE *f_in = fopen(argv[1], "r");
        FILE *f_out = fopen(argv[2], "w");
        if (f_in && f_out)
        {
            char str[MAX_STR_LEN + 1] = { 0 };
            char flag_empty = 1;
            while ((rc = freadline(f_in, str, MAX_STR_LEN + 1)) == OK)
            {
                char *splited[MAX_WORDS_NUMBER] = { 0 };
                int n = MAX_WORDS_NUMBER;

                if ((rc = split(str, splited, &n)) == OK)
                {
                    process(splited, n);
                    print(f_out, splited, n);
                    flag_empty = 0;
                }
                else
                {
                    puts("Error split");
                    break;
                }
            }

            fclose(f_in);
            fclose(f_out);

            if (flag_empty)
            {
                printf("ERR empty\n");
                rc = ERR_EMPTY;
            }
        }
        else
        {
            if (f_in)
                fclose(f_in);
            if (f_out)
                fclose(f_out);

            puts("Can not open file");
            rc = ERR_OPEN_FILE;
        }

    }

    return rc;
}
