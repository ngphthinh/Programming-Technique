#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swaps(float *a, float *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm xuất mảng ra màn hình
void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.3f ", arr[i]);
    }
}
void scanfArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
}

bool asc(float a, float b) // kiểm tra xem a có lớn hơn b hay không
{
    return a > b;
}
bool desc(float a, float b) // kiểm tra xem a có nhỏ hơn b hay không
{
    return a < b;
}
void bubbleSort(float *arr, int n, bool (*comparison)(float, float))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (comparison(arr[j], arr[j + 1]))
            {
                swaps(&arr[j], &arr[j + 1]);
            }
        }
    }
}
// Viết chương trình khai báo mảng 10 con trỏ đến kiểu float, nhận 10 số thực từ bàn phím, sắp xếp lại và in ra màn hình dãy số đã sắp xếp.

int main()
{
    int n;
    float a[100];
    scanf("%d", &n);
    scanfArray(a, n);
    bubbleSort(a, n, desc);
    printArray(a, n);
    return 0;
}
