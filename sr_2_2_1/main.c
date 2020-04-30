#include<stdio.h>
#define OK 0.0
#define ERR_IO 1.0
// Function that changes the a and b parameters
void change(float *a, float *b)
{
    float c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(void)
{
    float a, b, rc = OK;
    float *z = &a, *x = &b;
    printf("Input two numbers: ");
    setbuf(stdout, NULL);
    if (scanf("%f%f", &a, &b) == 2)
    {
        rc = OK;
        change(z, x);
        printf("%f %f", a, b);
        return rc;
    }
    else
        return ERR_IO;
}
