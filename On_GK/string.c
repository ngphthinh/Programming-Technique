#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned ArrayModify(int Arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (Arr[i] < 0)
        {
            Arr[i] *= (-i);
            sum += Arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }
    return sum;
}
int main()
{
    int n = 10, Arr[] = {-39, 1, 44, 37, 30, 47, 2, 38, 14, -19};
    unsigned int m = ArrayModify(Arr, n);
    printf("\n%u", m);
}
