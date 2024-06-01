#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct
{
    char HegID[8];
    char HegSpe[15];
    long Price;
    int Quantity;
} Hedgedhog, HegArr[SIZE];

void InputHeg(Hedgedhog *Heg)
{
    fflush(stdin);
    printf("Enter hedgedhog type ID: ");
    fgets(Heg->HegID, 8, stdin);
    printf("Enter the name of the hedgedhog type: ");
    fgets(Heg->HegSpe, 15, stdin);
    printf("Enter edgehog price: ");
    scanf("%ld", &Heg->Price);
    printf("Enter the number of hedgedhog types: ");
    scanf("%d", &Heg->Quantity);
    Heg->HegID[strlen(Heg->HegID) - 1] = '\0';
    Heg->HegSpe[strlen(Heg->HegSpe) - 1] = '\0';
}

int InputHegArr(HegArr hedgedhog)
{
    int size = 0;
    printf("Enter the hedgedhog type number: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Type %d\n", i + 1);
        InputHeg(&hedgedhog[i]);
    }
    return size;
}
void DisplayHedArr(HegArr hedgedhog, int size)
{
    printf("\n+=====+========+===============+=====+========+\n");
    printf("|%s|%-8s|%-15s|%s|%s|\n", "Index", "   ID", "     Name", "Price", "Quantity");
    printf("+=====+========+===============+=====+========+\n");
    for (int i = 0; i < size; i++)
    {
        printf("|%-5d|%-8s|%-15s|%5ld|%8d|\n", i + 1, hedgedhog[i].HegID, hedgedhog[i].HegSpe, hedgedhog[i].Price, hedgedhog[i].Quantity);
    }
    printf("+=====+========+===============+=====+========+\n");
}
void HegPriceMax(HegArr hedgedhog, int size)
{
    int index = 1;
    long max = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < hedgedhog[i].Price)
        {
            max = hedgedhog[i].Price;
        }
    }
    printf("\n+=====+========+===============+=====+========+\n");
    printf("|%s|%-8s|%-15s|%s|%s|\n", "Index", "   ID", "     Name", "Price", "Quantity");
    printf("+=====+========+===============+=====+========+\n");
    for (int i = 0; i < size; i++)
    {
        if (max == hedgedhog[i].Price)
        {
            printf("|%-5d|%-8s|%-15s|%5ld|%8d|\n", index, hedgedhog[i].HegID, hedgedhog[i].HegSpe, hedgedhog[i].Price, hedgedhog[i].Quantity);
            index++;
        }
    }
    printf("+=====+========+===============+=====+========+\n");
}
void PriceUpdate(HegArr hedgedhog, int size)
{
    const double priceUpdate = 1.15;
    fflush(stdin);
    char ChangeID[8];
    printf("Enter the ID you want to change: ");
    fgets(ChangeID, 8, stdin);
    ChangeID[strlen(ChangeID) - 1] = '\0';
    for (int i = 0; i < size; i++)
    {
        if (strcmp(ChangeID, hedgedhog[i].HegID) == 0)
        {
            hedgedhog[i].Price *= priceUpdate;
            printf("update %s", ChangeID);
            break;
        }
    }
}
int main()
{
    HegArr hedgedhog;
    int size = InputHegArr(hedgedhog);
    DisplayHedArr(hedgedhog, size);
    printf("\nThe most expensive squirrels on the list\n");
    HegPriceMax(hedgedhog, size);
    PriceUpdate(hedgedhog, size);
    DisplayHedArr(hedgedhog, size);
    return 0;
}