#include <stdio.h>
#include <stdlib.h>

int CountDigits(long long n)
{
    if (n == 0)
        return 0;
    else
        return 1 + CountDigits(n / 10);
}

int main()
{
    long long n;
    scanf("%lld", &n);
    // printf("%d\n", n);
    printf("%d", CountDigits(n));

    return 0;
}