#include <stdio.h>
#include <string.h>

int Compare2String(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] < str2[i])
            return -1;
        else if (str1[i] > str2[i])
            return 1;
        i++;
    }
    return 0;
}

void SwapString(char *str1, char *str2)
{
    char tmp[1000];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}
void Compare3String(char str1[], char str2[], char str3[])
{
    if (strcmp(str1, str2) > 0)
        SwapString(str1, str2);

    if (strcmp(str2, str3) > 0)
        SwapString(str2, str3);

    if (strcmp(str1, str2) > 0)
        SwapString(str1, str2);

    printf("%s\n%s\n%s", str1, str2, str3);
}
int main()
{
    char S1[101] = "B";
    char S2[101] = "A";
    char S3[101] = "C";
    // Compare3String(S1, S2, S3);
    Compare3String(S1, S2, S3);
    return 0;
}