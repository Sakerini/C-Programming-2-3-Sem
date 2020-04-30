#include<stdio.h>
#define OK 0
#define ERR_IO 1
#define N_MAX 10

int Summa(int chislo)
{
    int summa = 0 ,a, b;
    char str_chislo[10], str_a, str_b;
    str_chislo = str(chislo);
    str_a = chislo[0];
    str_b = chislo[-1];
    a = int(str_a);
    b = int(str_b);
    summa = a * b;
    return summa;

}

int main(void)
{
    int chislo;
    setbuf(stdout, NULL);
    printf("Input a number: ");
    if (scanf("%d", &chislo) == 1)
    {
        summa(chislo)
        return OK;
    }
    else
        return ERR_IO;

}
