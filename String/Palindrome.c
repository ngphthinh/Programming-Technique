#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void Delete_Not_AlNum(char *str)
{
    // Ham xoa ki tu khong phai la so hoac chu
    int len = strlen(str);
    int i, j;
    // xoa ki tu o dau dong
    while (str[0] == ' ')
    {
        for (i = 0; i < len; i++)
        {
            str[i] = str[i + 1];
        }
        len--;
    }

    for (i = 0; i < len; i++)
    {
        if (!isalnum(str[i]))
        {
            for (j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            i--;
            len--;
        }
    }
}

void strlwc(char str[])
{
    // ham chuyen xau tu hoa sang thuong
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

int is_Palindrome(char str[])
{
    // ham kiem tra doi xung
    Delete_Not_AlNum(str);
    strlwc(str);
    int l = 0;
    int r = strlen(str) - 1;
    while (l <= r)
    {
        if (str[l] != str[r])
        {
            return 0;
        }
        l++;
        --r;
    }
    return 1;
}

void Palindrome(char str[])
{
    if (is_Palindrome(str))
        printf("This string is a palindrome");
    else
        printf("This string is not a palindrome");
}

int main()
{
    char S[] = "Never odd or even";
    Palindrome(S);
    return 0;
}
void strlwc(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}
void DeleteAllSpaces(char str[])
{
    strlwc(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (isspace(str[i]))
        {
            for (int j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
    }
}
int IsPalindrome(char *str)
{
    DeleteAllSpaces(str);
    int l = 0, r = strlen(str) - 1;
    while (r = > l)
    {
        if (str[r] != str[l])
            return 0;
        r--;
        l++;
    }
    return 1;

    void Palindrome(char str[]) if (IsPalindrome(str))
        printf("This string is a palindrome");
    else printf("This string is not a palindrome");
}