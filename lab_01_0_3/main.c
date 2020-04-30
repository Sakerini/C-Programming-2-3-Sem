#include<stdio.h>
int main(void)
{
    float h, t, m, weight, indxm;
    printf("Input h, t, m:");
    scanf("%f%f%f", &h, &t, &m);
    weight = (h * t) / 240;
    indxm = m / ((h / 100) * (h / 100));
    printf("Normal human weight , mass is: %.5f %.5f", weight, indxm);
    return 0;
}
