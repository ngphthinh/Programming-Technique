#include <stdio.h>
#include <stdlib.h>
int PalindromeArray(int a[], int n)
{
    if (n < 1)
        return 1;
    if (a[0] != a[n - 1])
        return 0;
    else
        return PalindromeArray(a + 1, n - 2);
}
int MaxArray(int *a, int n)
{
    if (n <= 1)
        return a[0];
    int max = MaxArray(a, n - 1);
    return a[n - 1] > max ? a[n - 1] : max;
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int res = PalindromeArray(a, n);
    printf("%d\n%d", res, MaxArray(a, n));
    return 0;
}
