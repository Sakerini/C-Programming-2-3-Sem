#include<stdio.h>
#include<math.h>
int main(void)
{
    float a, b, h, l, p;
    printf("Input a,b,h:");
    scanf("%f%f%f", &a, &b, &h);
    l = sqrt(pow(h, 2) + pow(((b - a) / 2), 2));
    p = 2 * l + a + b;
    printf("The result is: %f", p);
    return 0;
}
