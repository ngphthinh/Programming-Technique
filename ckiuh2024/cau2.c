#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    char name[50];
    double price;
    char ogirin[50];
} Product;

void nhapthongtin(Product products[], int n)
{
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strlen(products[i].name) - 1] = '\0';
        scanf("%lf", &products[i].price);
        getchar();
        fgets(products[i].ogirin, sizeof(products[i].ogirin), stdin);
        products[i].ogirin[strlen(products[i].ogirin) - 1] = '\0';
    }
}
int dem(Product products[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(products[i].ogirin, "Viet Nam") == 0)
            count++;
    }
    return count;
}
void write_to_fileText(Product products[], int n)
{
    FILE *pfText = fopen("23642651.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(products[i].ogirin, "Viet Nam") == 0)
        {
            fprintf(pfText, "%s; %.2lf; %s\n", products[i].name, products[i].price, products[i].ogirin);
        }
    }
    fclose(pfText);
}
int main()
{
    int n;
    Product products[50];
    scanf("%d", &n);
    nhapthongtin(products, n);
    printf("%d\n", dem(products, n));
    write_to_fileText(products, n);
    return 0;
}