#include<stdio.h>
#define OK 0
#define ERR_IO 1

/*
Функция считает число из поредицу фибоначи,
Как параметр задаем номер число из поредицу которое хотим вычеслить
n
*/
int fib(int n)
{
    int fib1 = 1, fib2 = 1, fib3;
    if (n == 0)
        fib2 = 0;
    else
    {
        for (int i = 3; i <= n; i++)
        {
            fib3 = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib3;
        }
    }
    return fib2;
}
/*
Функция спрашивает у пользователя номер n и выводить на екран
число из поредицу фибоначи
параметр задаем код ошибки как изменяемая переменная
rc
*/
void n_input(int *rc)
{
    int n;
    printf("Input a number of N: ");
    if (scanf("%d", &n) == 1)
    {
        if (n >= 0 && n <= 46)
            printf("%d", fib(n));
        else
        {
            *rc = ERR_IO;
            printf("Error: WRONG INPUT/OUTPUT");
        }
    }
    else
    {
        *rc = ERR_IO;
        printf("Error: WRONG INPUT/OUTPUT");
    }
}
int main(void)
{
    int rc = OK;
    setbuf(stdout, NULL);
    n_input(&rc);
    return rc;
}
