#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
double PerimeterTriangle(Triangle *t)
{
    double a = sqrt(pow(t->Vertice1->X - t->Vertice2->X, 2) + pow(t->Vertice1->Y - t->Vertice2->Y, 2));
    double b = sqrt(pow(t->Vertice2->X - t->Vertice3->X, 2) + pow(t->Vertice2->Y - t->Vertice3->Y, 2));
    double c = sqrt(pow(t->Vertice3->X - t->Vertice1->X, 2) + pow(t->Vertice3->Y - t->Vertice1->Y, 2));
    return a + b + c;
}
int main () {
    float a, b, c, d, e, f;
    scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
    Triangle t = InputTriangle(a, b, c, d, e, f);
    double kq = PerimeterTriangle(&t);
    printf("%.2lf",kq);
    return 0;
}