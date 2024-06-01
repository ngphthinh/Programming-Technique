#include <stdio.h>
int Combination(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    if (k > n)
        return 0;

    return Combination(k, n - 1) + Combination(k - 1, n - 1);
}

int main()
{

    int n, k;
    scanf("%d %d", &k, &n);
    printf("%d", Combination(k, n));
}