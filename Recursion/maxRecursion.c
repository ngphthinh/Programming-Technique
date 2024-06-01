#include <stdio.h>
#include <stdlib.h>

int max_for(int *a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
int max_recursion(int a[], int n)
{

    if (n == 1)
        return a[0];

    // Recursively find the maximum element in the sub-array excluding the last element
    int maxInRest = max_recursion(a, n - 1);

    // Compare the maximum of the sub-array with the last element and return the greater one
    return (maxInRest > a[n - 1]) ? maxInRest : a[n - 1];
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    printf("%d", max_recursion(arr, n));
    // system("pause");
    return 0;
}