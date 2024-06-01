#include <stdio.h>
#include <math.h>
typedef struct
{
    int Numerator;
    int Denominator;
} Fractions;
int isPositiveFraction(Fractions fr)
{
    if (fr.Numerator * fr.Denominator > 0)
    {
        return 1; // Trả về 1 nếu phân số dương
    }
    if (fr.Numerator * fr.Denominator < 0)
    {
        return -1; // Trả về -1 nếu phân số âm
    }

    {
        return 0; // Trả về 0 nếu phân số bằng 0
    }
}
int main()
{
    Fractions fr = {1, 1};
    int ispos = isPositiveFraction(fr);
    printf("%d", ispos);
}