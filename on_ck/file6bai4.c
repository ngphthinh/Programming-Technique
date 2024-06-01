#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long calc_sizeFile()
{
    FILE *fp = fopen("file6b4.txt", "r");
    fseek(fp, 0, SEEK_END);

    long size = ftell(fp);
    fclose(fp);
    return size;
}

void analyze_text_file()
{
    FILE *fp = fopen("file6b4.txt", "r");
    int cnt[26] = {0};
    char c;
    int kitu = 0;
    while (!feof(fp))
    {
        c = fgetc(fp);
        if (isalpha(c))
        {
            c = tolower(c);
            cnt[c - 97]++;
            kitu++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%d ", cnt[i]);
    }
    printf("\n%d", kitu);
}

int main()
{
    long size = calc_sizeFile();
    // printf("%ld", size);
    analyze_text_file();
    return 0;
}