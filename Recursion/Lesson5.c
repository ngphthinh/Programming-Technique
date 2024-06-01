#include <stdio.h>

void Dec_Bin(int n)
{
    if (n < 2)
    {
        printf("%d", n);
    }
    else
    {
        Dec_Bin(n / 2);
        printf("%d", n % 2);
    }
}
int main()
{
    Dec_Bin(5);
}