#include <stdio.h>

void dec_to_bin(int n)
{
    if (n < 2)
        printf("%d", n);
    else
    {
        dec_to_bin(n / 2);
        printf("%d", n % 2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    dec_to_bin(n);
    return 0;
}