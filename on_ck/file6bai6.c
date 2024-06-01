#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Viết chương trình in nội dung tập tin văn bản, chỉ in các ký tự chữ cái và chữ
// số. Tên tập tin là đối số của hàm main.

void print_alphanumeric_characters(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Khong the mo tap tin.\n");
        return;
    }
    char c;
    while (!feof(fp))
    {
        c = fgetc(fp);
        if (isalnum(c))
        {
            putchar(c);
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Sai cu phap. Hay nhap ten tap tin.\n");
        return 1;
    }

    char *filename = argv[1];
    print_alphanumeric_characters(filename);

    return 0;
}
