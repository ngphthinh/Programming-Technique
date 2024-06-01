#include <stdio.h>
#include <stdlib.h>

void input(int *a, int size)
{
    if (size == 0)
        return;
    else
    {
        input(a, size - 1);
        scanf("%d", &a[size - 1]);
    }
}

void out(int *a, int size)
{
    if (size == 0)
    {
        return;
    }
    else
    {
        out(a,size-1);
        printf("%d ",*(a + size -1));
    }
}
int main()
{
    int size;
    scanf("%d", &size);
    int *a = (int *)malloc(size * sizeof(int));
    input(a, size);
    out (a,size);

    free(a);
    return 0;
}