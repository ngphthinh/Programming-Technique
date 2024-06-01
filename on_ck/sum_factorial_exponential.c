#include <stdio.h>
#include <stdlib.h>
long sum(int n)
{
    if (n == 0)
        return n;
    return n + sum(n - 1);
}
long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
double exponential(float a, int n)
{
    if (n == 0)
        return 1;
    return a * exponential(a, n - 1);
}
int main()
{
    int n;
    float a;
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Du lieu khong hop le. Nhap lai gia tri n");
        exit(0);
    }
    scanf("%f", &a);
    printf("S(%d) = %d\n", n, sum(n));
    printf("P(%d) = %d\n", n, factorial(n));
    printf("A(%.2f,%d) = %.2lf\n", a, n, exponential(a, n));
    return 0;
}