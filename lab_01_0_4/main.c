#include<stdio.h>
#define A 20
#define B 25
int main(void)
{
    int s, bottles;
    printf("input s: ");
    scanf("%d", &s);
    bottles = (s - A) / B;
    printf("%d", bottles);
    return 0;
}
