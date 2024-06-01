#include <stdio.h>

void dec_to_hex(int n)
{
    if (n < 16)
    {
        if (n < 10)
            printf("%d", n);
        else
            printf("%c", (55 + n));
    }
    else
    {
        dec_to_hex(n / 16);
        if (n % 16 < 10)
            printf("%d", n % 16);
        else
            printf("%c", (55 + n % 16));
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    dec_to_hex(num);
    return 0;
}