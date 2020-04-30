#include<stdio.h>
#include<math.h>
#define OK 0.0
#define ERR_IO 1.1
#define PI 3.1415  // число PI

void ploshad(float r, float h, float *s1, float *s2)
{                            //s1 площадь боковой, s2 площадь полной
    *s1 = 2 * PI * r * h;
    *s2 = 2 * PI * r * (h + r);
}

int main(void)
{
    float r, h, rc = OK, s1, s2;
    float *z = &s1, *x = &s2;
    setbuf(stdout, NULL);
    printf("Input radius and height: ");
    if (scanf("%f %f", &r, &h) == 2)
    {
        rc = OK;
        ploshad(r, h, z, x);
        printf("%f , %f ", s1, s2);
        return rc;
    }
    else
        return ERR_IO;
}
