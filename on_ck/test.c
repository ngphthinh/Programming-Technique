#include <stdio.h>
void main()
{
    int x = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j % 2 == 0)
                x += i + j;
        }
    }
    printf("%d", x);
}
