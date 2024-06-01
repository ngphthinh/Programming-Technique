#include <stdio.h>
#include <stdlib.h>
#define fileName "Namquocsonha.txt"
void read_file()
{
    FILE *pf = fopen(fileName, "r");
    if (pf == NULL)
    {
        printf("Error");
        exit(0);
    }
    char line[100];
    while (fgets(line, sizeof(line), pf))
    {
        printf("%s", line);
    }
    fclose(pf);
}

void sua_file()
{
    FILE *pf = fopen(fileName, "r");
    if (pf == NULL)
    {
        printf("Error");
        exit(0);
    }
    fseek(pf, -, SEEK_END);
    char line[100];
    fgets(line, sizeof(line), pf);
    printf("%s", line);
    fclose(pf);
}
int main()
{
    read_file();
    printf("\n");
    printf("\n");
    sua_file();
    return 0;
}
