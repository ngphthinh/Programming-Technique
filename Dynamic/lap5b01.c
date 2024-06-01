#include <stdio.h>
#include <stdlib.h>

struct Point2D
{
    double X, Y;
};

typedef struct
{
    struct Point2D *Vertice1;
    struct Point2D *Vertice2;
    struct Point2D *Vertice3;
} Triangle;

Triangle InputTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    Triangle a;
    a.Vertice1 = malloc(sizeof(struct Point2D));
    a.Vertice2 = malloc(sizeof(struct Point2D));
    a.Vertice3 = malloc(sizeof(struct Point2D));
    a.Vertice1->X = x1;
    a.Vertice1->Y = y1;
    a.Vertice2->X = x2;
    a.Vertice2->Y = y2;
    a.Vertice3->X = x3;
    a.Vertice3->Y = y3;
    return a;
}
void ShowTriangle(Triangle a)
{
    printf("Vertice1: (%.2f, %.2f)\n", a.Vertice1->X, a.Vertice1->Y);
    printf("Vertice2: (%.2f, %.2f)\n", a.Vertice2->X, a.Vertice2->Y);
    printf("Vertice3: (%.2f, %.2f)", a.Vertice3->X, a.Vertice3->Y);
}
int main()
{
    float a, b, c, d, e, f;
    scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
    Triangle t = InputTriangle(a, b, c, d, e, f);
    ShowTriangle(t);
}