#include <stdio.h>
#include <stdlib.h>

char *dynamic_character()
{
    char *character = (char *)malloc(sizeof(char));
    scanf("%c", character);
    return character;
}

int main()
{
    char *ptr1, *ptr2;
    ptr1 = dynamic_character();
    ptr2 = dynamic_character();

    char i;
    if (*ptr1 > *ptr2)
    {
        char *c = ptr1;
        ptr1 = ptr2;
        ptr2 = c;
    }

    for (i = *ptr1; i <= *ptr2; i++)
    {
        printf("%c %4d %4o %4X\n", i, i, i, i);
    }

    return 0;
}