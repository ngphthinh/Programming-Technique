#include <stdio.h>
#include <stdlib.h>
#define file "input.txt"
#define countNumber 10
void input_file()
{
    FILE *fp = fopen(file, "w");
    float num = 0;
    for (int i = 0; i < countNumber; i++)
    {
        scanf("%f", &num);
        fprintf(fp, "%f\n", num);
    }
    fclose(fp);
}
float read_from_file()
{
    FILE *fp = fopen(file, "r");
    float sum = 0;
    float num;
    while (fscanf(fp, "%f", &num) == 1)
    {
        sum += pow(num, 2);
    }
    fclose(fp);
    return sum;
}
int main()
{
    input_file();
    printf("%.2f", read_from_file());
    return 0;
}