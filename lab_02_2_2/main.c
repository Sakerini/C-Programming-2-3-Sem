#include<stdio.h>
#include<math.h>
#define EPS 10e-7
#define OK 0
#define ERR_IO 1
#define IN_TRIANGLE 0
#define NOT_IN_TRIANGLE 2
#define ON_TRIANGLE 1

/*
Функция считает площадь тригуольник, если площадь равен 0 или меньше возвращает ответ НЕ,
Функция принимает аргументы координаты сначало задаем икс потом игрек
(x1 x2 x3 y1 y2 y3)
*/
int istriangle(float x1, float x2, float x3, float y1, float y2, float y3)
{
    float s;
    s = fabs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) / 2;
    if (s <= 0)
        return 1; // не тригуольник
    else
        return 0;
}
/*
Функция ищет точку задана по координатам, проверяет если точка внутри вне или на тригуольник,
аргументы координаты, сначало икс потом игрек
(x1 x2 x3 xa y1 y2 y3 ya) где xa и ya координаты точка
*/
int find_point(float x1, float x2, float x3, float xa, float y1, float y2, float y3, float ya)
{
    float va, vb, vc;             // результата произведения для оставшейся координаты (z)

    va = (((x2 - x1) * (ya - y1)) - ((y2 - y1) * (xa - x1)));
    vb = (((x3 - x2) * (ya - y2)) - ((y3 - y2) * (xa - x2)));
    vc = (((x1 - x3) * (ya - y3)) - ((y1 - y3) * (xa - x3)));

    if ((va > 0 && vb > 0 && vc > 0) || (va < 0 && vb < 0 && vc < 0))
    {
        return IN_TRIANGLE;
    }
    else if (fabs(va) < EPS || fabs(vb) < EPS || fabs(vc) < EPS)
    {
        return ON_TRIANGLE;
    }
    else
    {
        return NOT_IN_TRIANGLE;
    }
}
int main(void)
{
    int rc = OK;
    float x1, x2, x3, xa, y1, y2, y3, ya;
    setbuf(stdout, NULL);
    printf("Input a coordinates x1 y1 x2 y2 x3 y3 xA yA : ");
    if (scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &xa, &ya) == 8)
    {
        if (istriangle(x1, x2, x3, y1, y2, y3) == 1)
        {
            rc = ERR_IO;
            printf("Error: IT is not a triangle");
        }
        else
            printf("%d", find_point(x1, x2, x3, xa, y1, y2, y3, ya));
    }
    else
    {
        rc = ERR_IO;
        printf("Error: WRONG INPUT/OUTPUT");
    }
    return rc;
}
