#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20];
    int age;
    float salary;
} Person;
void input_file()
{
    FILE *fp = fopen("file6b2.txt", "w");
    Person person;
    while (1)
    {
        fgets(person.name, 20, stdin);
        person.name[strcspn(person.name, "\n")] = '\0';
        if (person.name[0] == '\0')
            break;
        scanf("%d %f", &person.age, &person.salary);
        getchar(); // Đọc ký tự '\n' còn thừa sau scanf
        fprintf(fp, "%s %d %f\n", person.name, person.age, person.salary);
    }
    fclose(fp);
}
void display_data_from_file()
{
    FILE *fp = fopen("file6b2.txt", "r");
    char line[256];
    while (fgets(line, 256, fp))
    {
        printf("%s", line);
    }
    fclose(fp);
}

int main()
{

    input_file();
    display_data_from_file();
    return 0;
}