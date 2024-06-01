#include <stdio.h>

int capsocong(int n, int a, int r)
{
    if (n == 1)
        return a;
    if (n >= 2)
    {
        return capsocong(n - 1, a + r, r);
    }
}
int capsonhan(int n, int a, int q)
{
    if (n == 1)
        return a;
    if (n >= 2)
        return capsonhan(n - 1, a * q, q);
}
int main()
{
    int a, r, n, q;
    scanf("%d %d %d %d", &n, &a, &r, &q);
    printf("CSC:");
    for (int i = 1; i <= n; i++)
    {
        printf(" %d", capsocong(i, a, r));
    }
    printf("\nCSN:");
    for (int i = 1; i <= n; i++)
    {
        printf(" %d", capsonhan(i, a, q));
    }
    return 0;
}