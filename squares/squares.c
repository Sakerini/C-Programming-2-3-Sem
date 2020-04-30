/*
Вычисляет площадь прямоугольника.
*/
#include <stdio.h>
#define PI 3.14
float s_pryam(float a, float b)
{
    float s;
    s = a * b;
    return s;
}
float s_krug(float r)
{
    float s;
    s = PI * r * r;
    return s;
}
int main(void)
{
    float a, b, r, sall;
    printf("Input a and b:");
    scanf("%f%f",&a, &b);
    printf("Square of rectangle is %8.3f\n", s_pryam(a, b));

    printf("Input radius: ");
    scanf("%f", &r);
    printf("Square of circle is %8.3f\n", s_krug(r));
    sall = s_pryam(a, b) + s_krug(r);
    printf("both square of the figures is %8.3f\n", sall);


    return 0;
}
