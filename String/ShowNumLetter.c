#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void ShowNumLeters(int n, int pos, char str[])
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < len)
            printf("%c", str[i]);
    }
    printf("\n");
    for (int i = len - n; i < len; i++)
    {
        if (i >= 0 && n < len)
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    for (int i = pos; i < pos + n; i++)
    {
        if (i < len)
            printf("%c", str[i]);
    }
}

int main()
{

    char S[] = "Hello, world";
    int n = 3, pos = 0;
    ShowNumLeters(n, pos, S);
}
