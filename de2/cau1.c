#include <stdio.h>

void thaythe(int *a, int n)
{
    if (n == 0)
        return;
    if (a[n - 1] < 0)
    {
        a[n - 1] = 0;
        thaythe(a, n - 1);
    }
    else
        thaythe(a, n - 1);
}

int main()
{
    int a[] = {1, -4, -6, -5, -2, 4, 2, 5, -6, 3, 5 - 5, 3, 5};
    int n = sizeof(a) / sizeof(int);
    printf("After:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    thaythe(a, n);
    printf("\nBefore:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}