#include <stdio.h>

void printMatrixByRow(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMatrixByColumn(int n, int matrix[n][n])
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMatrixByMainDiagonal(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void printMatrixBySecondaryDiagonal(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", matrix[i][n - 1 - i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Nhập số cấp của ma trận: ");
    scanf("%d", &n);

    int matrix[n][n];
    printf("Nhập các phần tử của ma trận:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("In ma trận theo hàng:\n");
    printMatrixByRow(n, matrix);

    printf("In ma trận theo cột:\n");
    printMatrixByColumn(n, matrix);

    printf("In ma trận theo đường chéo chính:\n");
    printMatrixByMainDiagonal(n, matrix);

    printf("In ma trận theo đường chéo phụ:\n");
    printMatrixBySecondaryDiagonal(n, matrix);

    return 0;
}
