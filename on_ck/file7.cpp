#include <stdio.h>
#include <conio.h>
void read_from_file(int a[][20], int *m, int *n)
{
    FILE *fp = fopen("file7b.txt", "r");
    fscanf(fp, "%d %d", n, m);
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            fscanf(fp, "%d", &a[i][j]);
        }
    }
    printf("loangding\n");
    fclose(fp);
}
int main()
{
    int a[20][20];
    int n, m;
    read_from_file(a, &m, &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}