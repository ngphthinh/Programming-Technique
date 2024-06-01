#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void strlwc(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

void chuyen_in_hoa(char *str)
{
    strlwc(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (i == 0 || str[i - 1] == ' ')
        {
            str[i] = toupper(str[i]);
        }
    }
}
void standard(char *str)
{

    while (str[0] == ' ')
    {
        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = str[i + 1];
        }
    }
    while (str[strlen(str) - 1] == ' ')
    {
        str[strlen(str) - 1] = '\0';
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (int j = i; j < strlen(str); j++)
            {
                str[j] = str[j + 1];
            }
            --i;
        }
    }
}
void deleta_space(char str[])
{
    // while (isspace(str[0]))
    // {
    //     for (int i = 0; i < strlen(str); i++)
    //     {
    //         str[i] = str[i + 1];
    //     }
    // }
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))
        {
            for (int j = i; j < strlen(str); j++)
            {
                str[j] = str[j + 1];
            }
            i--;
        }
    }
}
void xuatcactu(char *str)
{
    char *token = strtok(str, " ");
    int count = 0;
    while (token != NULL)
    {
        printf("%s\n", token);
        count++;
        token = strtok(NULL, " ");
    }
    printf("%d", count);
}

void xuatcactu2(char *str)
{
    int count = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))
        {
            count++;
            printf("\n");
            i++;
        }
        printf("%c", str[i]);
    }
    printf("\n%d", count);
}
void LongestWord(char str[])
{
    char *token = strtok(str, " ");
    int len = strlen(token);
    char longword[100];
    strcpy(longword, token);
    // printf("%s", longword);
    while (token != NULL)
    {
        if (len > strlen(token))
        {
            len = strlen(token);
            strcpy(longword, token);
        }
        token = strtok(NULL, " ");
    }
    printf("%s", longword);
}
void Show_Num_Letter(char str[], int n, int pos)
{
    for (int i = 0; i < n && i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    for (int i = strlen(str) - n; i < strlen(str) && i >= 0; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    for (int i = pos; i < pos + n && i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }
}
int main()
{
    char str[100] = "Hello, World";
    // deleta_space(str);
    // chuyen_in_hoa(str);
    // printf("%s", str);
    // xuatcactu2(str);
    // system("pause");
    // LongestWord(str);
    Show_Num_Letter(str, 3, 0);
    return 0;
}