#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hiện thực hàm Quadrants với đầu vào là con trỏ cấu trúc điểm,kiểm tra điểm thuộc
// phần tư nào trên trục tọa độ? trả về các giá trị 1,2,3,4 tương ứng đó. Ngược lại trả về 0
struct Point2D
{
    double X, Y;
};
int Quadrants(struct Point2D *p)
{
    if (p->X > 0 && p->Y > 0)
        return 1;
    else if (p->X < 0 && p->Y < 0)
        return 3;
    else if (p->X > 0 && p->Y < 0)
        return 4;
    else if (p->X < 0 && p->Y > 0)
        return 2;
    else
        return 0;
}
int main()
{
    float x, y;
    scanf("%f %f", &x, &y);
    struct Point2D p = {x, y};
    printf("%d", Quadrants(&p));
    return 0;
}