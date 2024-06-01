#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char ho_ten[30];
    char dia_chi[30];
    float diem;
} Student;

void doc_du_lieu(Student S[])
{
    FILE *fp = fopen("23452541.txt", "r");
    char line[250];
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%[^:]:%[^;];%f", S[i].ho_ten, S[i].dia_chi, &S[i].diem);
        i++;
    }
    fclose(fp);
}

int dem(Student s[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].diem >= 8)
            count++;
    }
    return count;
}
char *laythongtin(Student s)
{
    static char quan[50];
    char a[50], line[255];

    strcpy(line, s.dia_chi);
    sscanf(line, "%[^,],%[^,],%*s", a, quan);

    // // Remove leading spaces from quan
    // char *start = quan;
    // while (*start == ' ')
    // {
    //     start++;
    // }
    // // Copy the trimmed string back to quan
    // memmove(quan, start, strlen(start) + 1);

    return quan;
}
// char *laythongtin(Student s)
// {
//     char a[50], quan[50];
//     char line[255];
//     strcpy(line, s.dia_chi);
//     sscanf(line, "%[^,],%[^,],%s", a, quan, a);

//     while (quan[0] == ' ')
//     {
//         for (int i = 0; i < strlen(quan); i++)
//         {
//             quan[i] = quan[i + 1];
//         }
//     }

//     return quan;
// }
void liet_ke(Student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strstr(s[i].dia_chi, "Go Vap"))
            ;
        {
            printf("%s %s %.2f\n", s[i].ho_ten, s[i].dia_chi, s[i].diem);
        }
    }
}

int main()
{
    Student S[100];
    int n = 3;
    doc_du_lieu(S);
    printf("%d\n\n", dem(S, n));
    liet_ke(S, n);

    return 0;
}