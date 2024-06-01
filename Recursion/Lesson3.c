#include <stdio.h>

// 1
// 1 1
// 1 2 1
// 1 3 3 1
int pascal(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    else
        return pascal(k - 1, n - 1) + pascal(k, n - 1);
}
int main()
{
    int number;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", pascal(j, i));
        }
        printf("\n");
    }
}