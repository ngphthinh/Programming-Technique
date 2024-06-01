#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
#define Account "account.bin"
typedef struct
{
    char sPassWord[10];
    char sAccount[10];
} Users;

void ScanString(char *label, char *string, size_t max_length)
{
    printf("%s: ", label);
    fgets(string, max_length, stdin);
    string[strcspn(string, "\n")] = '\0';
}
bool Log_in(Users users[], int size)
{
    Users userLogin;
    bool found = false;
    ScanString("Enter account", userLogin.sAccount, sizeof(userLogin.sAccount));
    for (int i = 0; i < size; i++)
    {
        if (strcmp(users[i].sAccount, userLogin.sAccount) == 0)
        {
            ScanString("Enter password", userLogin.sPassWord, sizeof(userLogin.sPassWord));
            if (strcmp(users[i].sPassWord, userLogin.sPassWord) == 0)
            {
                printf("Logged in successfully\n");
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        printf("Account or password is incorrect\n");
        return false;
    }
    return true;
}
void Sign_in(Users users[], int *size)
{
    Users userSignIn;
    ScanString("Enter account", userSignIn.sAccount, sizeof(userSignIn.sAccount));
    for (int i = 0; i < *size; i++)
        if (strcmp(userSignIn.sAccount, users[i].sAccount) == 0)
        {
            printf("Account already exists");
            system("pause");
            return;
        }
    ScanString("Enter pass", userSignIn.sPassWord, sizeof(userSignIn.sPassWord));
    users[*size] = userSignIn;
    ++(*size);
    FILE *pfBin = fopen(Account, "wb");
    fwrite(size, sizeof(int), 1, pfBin);

    if (fwrite(users, sizeof(Users), *size, pfBin) != *size)
        perror("");

    fclose(pfBin);
    printf("Sign-in successful!\n");
}

int text_to_bin()
{
    FILE *pfText = fopen("chuyen_doi.txt", "r");
    FILE *pfBin = fopen(Account, "wb");

    Users user[MAX];
    int n;
    fscanf(pfText, "%d", &n);
    fwrite(&n, sizeof(n), 1, pfBin);
    for (int i = 0; i < n; i++)
    {
        fscanf(pfText, "%s %s", user[i].sAccount, user[i].sPassWord);
        fwrite(&user[i], sizeof(Users), 1, pfBin);
    }
    fclose(pfBin);
    fclose(pfText);
    return n;
}
int read_from_fileBin(Users users[])
{
    FILE *pfBin = fopen(Account, "rb");
    int size = 0;

    fread(&size, sizeof(size), 1, pfBin);

    fread(users, sizeof(Users), size, pfBin);
    fclose(pfBin);
    return size;
}
void print(Users users[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s|%s\n", users[i].sAccount, users[i].sPassWord);
    }
}

int Menu()
{
    system("cls");
    int key;
    printf("1.Log in\n");
    printf("2.Sign in\n");
    printf("3.Exit\n");
    scanf("%d", &key);
    getchar();
    return key;
}
int Menu1()
{
    system("cls");
    int key;
    printf("1.Sign in\n");
    printf("3.Exit\n");
    scanf("%d", &key);
    getchar();
    return key;
}
int main()
{
    Users users[MAX];
    int size = read_from_fileBin(users);
    while (1)
    {
        int key = Menu();
        switch (key)
        {
        case 1:
            if (!Log_in(users, size))
            {
                system("pause");
                int key1 = Menu1();
                switch (key1)
                {
                case 1:
                    Sign_in(users, &size);
                    break;
                default:
                    exit(0);
                    break;
                }
            }
            else
            {
                system("pause");
            }
            break;
        case 2:
            Sign_in(users, &size);
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}
