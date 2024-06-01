#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// cho số ngẫu nhiên trong đoạn từ m tới n;
int random(int m, int n)

    // srand(time(NULL));
    return m + rand() % (n - m + 1);
}
void input(int Q[], int *n)
{
    srand(time(NULL));
    *n = random(1, 100);
    for (int i = 0; i < *n; i++)
    {
        Q[i] = random(1, 100);
    }
}
void output(int Q[], int n)
{
    if (n == 1)
        printf("Q[0] = %d\n", Q[0]);
    else
    {
        output(Q, n - 1);
        printf("Q[%d] = %d\n", n - 1, Q[n - 1]);
    }
}
long sum_rec(int Q[], int n)
{
    if (n == 1)
        return Q[0];
    return Q[n - 1] + sum_rec(Q, n - 1);
}
int max_rec(int Q[], int n)
{
    if (n == 1)
        return Q[0];
    return Q[n - 1] > max_rec(Q, n - 1) ? Q[n - 1] : max_rec(Q, n - 1);
}
long sum(int Q[], int n)
{
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += Q[i];
    }
    return sum;
}
int main()
{
    int a[100];
    int n;
    input(a, &n);
    output(a, n);
    printf("sum = %ld", sum_rec(a, n));
    printf("\nsum = %ld", sum(a, n));
    printf("\nmax = %d", max_rec(a, n));
    return 0;
}
