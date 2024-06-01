#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int length1(char string[])
{
    
    if (string[0] == '\0')
        return 0;
    else
    {
        return 1 + length1(string + 1);
    }
}

int main()
{
    char string[100];
    gets(string);
    printf("\n%d", length1(string));
}