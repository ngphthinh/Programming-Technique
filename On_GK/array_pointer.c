#include <stdio.h>
#include <stdlib.h>

int *input(int *n)
{
    scanf("%d", n);
    int *a = (int *)malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", (a + i));
    }
    return a;
}
void show(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
}

void swaps(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j])
                swaps(&a[i], &a[j]);
        }
    }
}
int main()
{
    int size, x, p;
    // scanf("%d", &x);
    int *a = input(&size);
    sort(a, size);
    show(a, size);
    free(a);
    return 0;
}
