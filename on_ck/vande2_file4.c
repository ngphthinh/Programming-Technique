#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 1000

typedef struct point
{
    int x;
    int y;
} point;

typedef point PointArray[max];

// tính đoạn thẳng p1 p2
float p1p2(point p1, point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// diện tích tam giác p1 p2 p3 nếu 3 điểm thẳng hàng trả về 0

float area_triangle(point p1, point p2, point p3)
{
    if ((p2.y - p1.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - p1.x))
        return 0;
    float a = p1p2(p1, p2);
    float b = p1p2(p2, p3);
    float c = p1p2(p1, p3);
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// tinh diện tích đa giác lồi
float S(PointArray a, int n)
{
    float res = 0;
    for (int i = 0; i < n - 2; i++)
    {
        res += area_triangle(a[i], a[i + 1], a[i + 2]);
    }
    return res;
}

// nhập mảng điểm
void input(PointArray a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
}
int main()
{
    int n = 3;
    scanf("%d", &n);
    PointArray a = {{0, 0}, {3, 0}, {0, 4}};
    input(a, n);
    printf("%.2f\n", S(a, n));

    return 0;
}