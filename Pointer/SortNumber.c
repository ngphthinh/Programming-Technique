#include <stdio.h>

void SortNumber(int *number)
{
    int digits[10] = {0};
    while (*number != 0)
    {
        int tmp = *number % 10;
        digits[tmp]++;
        *number /= 10;
    }
    int res = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (digits[i] != 0)
        {
            res = res * 10 + i;
            digits[i]--;
            i--;
        }
    }
    *number = res;
}

int main()
{
    int num;
    scanf("%d", &num);
    SortNumber(&num);
    printf("%d", num);

    return 0;
}