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
int Congruent2Triangles(Triangle *t, Triangle *t2)
{
    int a = (int)sqrt(pow(t->Vertice1->X - t->Vertice2->X, 2) + pow(t->Vertice1->Y - t->Vertice2->Y, 2));
    int b = (int)sqrt(pow(t->Vertice2->X - t->Vertice3->X, 2) + pow(t->Vertice2->Y - t->Vertice3->Y, 2));
    int c = (int)sqrt(pow(t->Vertice3->X - t->Vertice1->X, 2) + pow(t->Vertice3->Y - t->Vertice1->Y, 2));
    int d = (int)sqrt(pow(t2->Vertice1->X - t2->Vertice2->X, 2) + pow(t2->Vertice1->Y - t2->Vertice2->Y, 2));
    int e = (int)sqrt(pow(t2->Vertice2->X - t2->Vertice3->X, 2) + pow(t2->Vertice2->Y - t2->Vertice3->Y, 2));
    int f = (int)sqrt(pow(t2->Vertice3->X - t2->Vertice1->X, 2) + pow(t2->Vertice3->Y - t2->Vertice1->Y, 2));
    if (a / d == 1 || a / e == 1 || a / f == 1)
    {
        if (b / d == 1 || b / e == 1 || b / f == 1)
        {
            if (c / d == 1 || c / e == 1 || c / f == 1)
                return 1;
        }
    }
    return 0;
}
int main()
{
    float a, b, c, d, e, f, g, h, i, j, k, l;

    scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
    scanf("%f %f %f %f %f %f", &g, &h, &i, &j, &k, &l);
    Triangle t = InputTriangle(a, b, c, d, e, f);
    Triangle t2 = InputTriangle(g, h, i, j, k, l);
    int kq = Congruent2Triangles(&t, &t2);
    printf("%d", kq);
    return 0;
}