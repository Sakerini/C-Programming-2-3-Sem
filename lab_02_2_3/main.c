#include<stdio.h>
#include<math.h>
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
/* Функция s_x выводить значение безконечного ряда s(x), 
Параметры: х это элемент который вводим, а эпсилон точность
*/
float s_x(float x, float eps)
{
    int z1 = 2, z2 = 3, z, p = 1;
    z = z1 * z2;
    float s = x, t = x;
    while (fabs(t) > eps)
    {
        t = t * (x * x * p) / z;
        s += t;
        p += 2;
        z = (z + 2) * (z2 + 2);
    }
    return s;
}

int main(void)
{
    float x, eps, rc = OK, absolute, otnos;
    setbuf(stdout, NULL);
    printf("Input x(between 0 and 1) and eps: ");
    if (scanf("%f%f", &x, &eps) == 2)
    {
        if (x <= -1 || x >= 1 || eps <= 0 || eps > 1)
        {
            rc = ERR_IO;
            printf("Error");
        }
        else
        {
            absolute = fabs(asin(x) - s_x(x, eps));   // абсолютная погрешность
            otnos = fabs(absolute / asin(x));   //относительная погрешность
            printf("Result for s(x) = %f \n", s_x(x, eps));
            printf("Result for f(x) = %f \n", asin(x));
            printf("Result for absolute %f and not absolute %f", absolute, otnos);
        }
    }
    else
    {
        rc = ERR_IO;
        printf("Error!");
    }
    return rc;
}
