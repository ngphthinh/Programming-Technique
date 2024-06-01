#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int tuso;
    int mauso;
} PS;

int GCD(int a, int b)
{
    if (b == 0)
        return abs(a);
    return GCD(b, a % b);
}
void input(PS &phanso)
{
    scanf("%d %d", &phanso.tuso, &phanso.mauso);
}
void output(PS phanso)
{
    printf("%d/%d", phanso.tuso, phanso.mauso);
}
void toigian(PS &phanso)
{
    int gcd = GCD(phanso.tuso, phanso.mauso);
    phanso.tuso /= gcd;
    phanso.mauso /= gcd;
}
int main()
{
    PS p;
    printf("\nNhap phan so:");
    input(p);
    printf("\nPhan so vua nhap:");
    output(p);
    toigian(p);
    printf("\nPhan so sau khi toi gian:");
    output(p);
    return 0;
}