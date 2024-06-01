#include <stdio.h>
float average(int a[], int n)
{
    if (n == 0)
        return a[0];
    return (a[n - 1] + average(a, n - 1) * (n - 1)) / n;
}

float faverage(int a[], int n)
{
    if (n == 0)
        return a[0];
    else
    {
        return (a[n - 1] + (n - 1) * faverage(a, n - 1)) / n;
    }
}
int main()
{
    int a[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%f", average(a, 10));
    return 0;
}