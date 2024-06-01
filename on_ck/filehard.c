#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct
{
    char stt[5];
    char name[30];
    int age;
} Person, listPerson[MAX];

void read_from_file(listPerson Persons)
{
    FILE *file = fopen("filehard.txt", "r");
    if (file == NULL)
    {
        perror("");
        return;
    }
    int n = 0;
    char line[100];
    while (fgets(line, 100, file) != NULL)
    {
        sscanf(line, "%4[^-]-%29[^-]-%d", Persons[n].stt, Persons[n].name, &Persons[n].age);

        n++;
    }
    for (int i = 0; i < n; i++)
    {
        // printf("a");
        printf("%-5s|%-29s|%02d\n", Persons[i].stt, Persons[i].name, Persons[i].age);
    }
}
void create_binary_file(const char *filename, listPerson people, int num_people)
{
    // Mở tập tin để ghi dữ liệu
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Không thể mở tập tin");
        return;
    }

    // Ghi dữ liệu vào tập tin nhị phân
    size_t a = fwrite(people, sizeof(Person), 100, file);

    // Đóng tập tin
    fclose(file);

    printf("%zu\n", a);
}
int search_from_file(int pos)
{
    FILE *file = fopen("filehard.txt", "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    // Di chuyển con trỏ tới vị trí bắt đầu của tập tin
    rewind(file);
    // Tìm vị trí bắt đầu của dòng thứ n
    for (int i = 1; i < pos; ++i)
    {
        int ch;
        while ((ch = fgetc(file)) != EOF && ch != '\n')
        {
            // Đọc cho đến khi gặp ký tự kết thúc dòng hoặc kết thúc tập tin
        }
    }

    // Đọc và in ra dòng
    char line[100]; // Độ dài tạm thời của mỗi dòng
    fgets(line, sizeof(line), file);
    printf("%s", line);

    fclose(file);
}
int main()
{
    listPerson Persons;
    read_from_file(Persons);
    create_binary_file("binary.bin", Persons, 100);
    return 0;
}
