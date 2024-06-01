#include <string.h>
#include <stdio.h>
void swap_character(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void daonguoc(char *str, int start, int end)
{
    char tmp[100];
    int len = strlen(str);
    int i = 0, r = len;
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        swap_character(&str[i], &str[len - 1]);
        len--;
    }
}
int main()
{
    char ten[100] = "Hello World";
    daonguoc(ten, 2, 5);
    printf("%s", ten);
}