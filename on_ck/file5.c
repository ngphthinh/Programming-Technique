#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char name[30];
    char id[10];
    float TK, GK, CK, TH, DTB;
} SINHVIEN;
float solve_DTB(float tk, float gk, float ck, float th)
{
    return ((tk * 0.2 + gk * 0.3 + ck * 0.5) * 2 + th) / 3;
}
int read_from_file(SINHVIEN list[])
{
    FILE *fp = fopen("data_qlsv.txt", "r");
    if (fp == NULL)
    {
        printf("Error! Could't found file!");
        exit(0);
    }
    char line[256];
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%29[^;];%9[^;];%f;%f;%f;%f", list[i].name, list[i].id, &list[i].TK, &list[i].GK, &list[i].CK, &list[i].TH);
        list[i].DTB = solve_DTB(list[i].TK, list[i].GK, list[i].CK, list[i].TH);
        i++;
    }
    fclose(fp);
    return i;
}
void top_margin()
{
    printf("+-----+-------------------------+------------+-----+\n");
    printf("|%-5s|%-25s|%-10s|%-5s|\n", "STT", "HO VA TEN", "MA SINH VIEN", "DTB");
    printf("+-----+-------------------------+------------+-----+\n");
}
void bot_margin()
{
    printf("+-----+-------------------------+------------+-----+\n");
}
void top_margin_full()
{
    printf("+-----+-------------------------+-------+-----+-----+-----+-----+-----+----------+\n");
    printf("|%-5s|%-25s|%-7s|%-5s|%-5s|%-5s|%-5s|%-5s|%-10s|\n",
           " STT",
           "          HO TEN",
           " MA SV",
           "  TK", "  GK",
           "  CK", "  TH",
           " DTB",
           "  Ghi chu");
    printf("+-----+-------------------------+-------+-----+-----+-----+-----+-----+----------+\n");
}

void bot_margin_full()
{
    printf("+-----+-------------------------+-------+-----+-----+-----+-----+-----+----------+\n");
}
void print_diem(SINHVIEN list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        char note[10];
        if (list[i].DTB < 4)
            strcpy(note, " Hoc lai");
        else
            strcpy(note, " ");
        printf("|  %-3d|%-25s|  %-5s|%-5.2f|%5.2f|%5.2f|%5.2f|%5.2f|%-10s|\n", i, list[i].name, list[i].id, list[i].TK,
               list[i].GK, list[i].CK, list[i].TH, list[i].DTB, note);
    }
}
void print_sv(SINHVIEN list[], int size)
{
    for (int i = 0; i < size; i++)
        printf("|%-5d|%-25s|%-12s|%-5.2f|\n", i, list[i].name, list[i].id, list[i].DTB);
}
void search_id(SINHVIEN list[], int size)
{
    int count = 0;
    char id_x[10];
    printf("Nhap MSSV muon tim: ");
    gets(id_x);
    // printf("%s", id_x);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(list[i].id, id_x) == 0)
        {
            printf("Ho ten: %s\n", list[i].name);
            printf("Ma sinh vien: %s\n", list[i].id);
            printf("Diem thuong ki: %.2f\n", list[i].TK);
            printf("Diem giua ki: %.2f\n", list[i].GK);
            printf("Diem cuoi ki: %.2f\n", list[i].CK);
            printf("Diem thuc hanh: %.2f\n", list[i].TH);
            printf("Diem trung binh: %.2f\n", list[i].DTB);
            count++;
            break;
        }
    }
    if (count == 0)
        printf("Khong tim thay!");
}
int cmp(const void *a, const void *b)
{
    SINHVIEN *x = (SINHVIEN *)a;
    SINHVIEN *y = (SINHVIEN *)b;
    if (y->DTB - x->DTB > 0)
        return 1;
    else
        return -1;
}
void sort(SINHVIEN list[], int n)
{
    qsort(list, n, sizeof(list[0]), cmp);
}

void inputInteger(char *label, int *num)
{
    printf("%s", label);
    scanf("%d", num);
}

void write_to_FileBin(SINHVIEN sv[], int size)
{
    FILE *pf = fopen("data_qlsv.bin", "wb");
    fwrite(&size, sizeof(int), 1, pf);
    for (int i = 0; i < size; i++)
    {
        fwrite(&sv[i], sizeof(SINHVIEN), 1, pf);
    }
    fclose(pf);
}
int read_from_fileBin(SINHVIEN *list)
{
    FILE *pf = fopen("data_qlsv.bin", "rb");
    int size;
    fread(&size, sizeof(size), 1, pf);
    for (int i = 0; i < size; i++)
    {
        fread(&list[i], sizeof(SINHVIEN), 1, pf);
    }
    return size;
}
int main()
{
    SINHVIEN DSSV[MAX];
    int size = read_from_fileBin(DSSV);

    top_margin_full();
    print_diem(DSSV, size);
    bot_margin_full();
    top_margin();
    print_sv(DSSV, size);
    bot_margin();
    write_to_FileBin(DSSV, size);

    return 0;
}