#include <stdio.h>

#define r 0.05

double laikep(float y, int n)
{
    if (n == 0)
        return y;
    else
        return laikep(y * (1 + r), n - 1);
}
int main()
{
    int n;
    float y;
    scanf("%d %f", &n, &y);
    printf("%.2lf", laikep(y, n));
    return 0;
}
// #include <stdio.h>

// #define r 0.05

// float laikep(float y, int n)
// {
//     if (n == 0)
//         return y;
//     else
//         return laikep(y * (1 + r), n - 1);
// }

// int main()
// {
//     int n;
//     float y;
//     scanf("%d %f", &n, &y);
//     printf("%.2f", laikep(y, n));
//     return 0;
// }
