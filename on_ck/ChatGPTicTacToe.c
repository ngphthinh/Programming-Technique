#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];          // Bảng chứa các ô của game
char currentPlayer = 'X';  // Người chơi hiện tại
char computerPlayer = 'O'; // Người chơi máy tính

// Khởi tạo bảng game với các ô trống
void initBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Hiển thị bảng game
void displayBoard()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Kiểm tra xem người chơi đã thắng hay chưa
bool checkWin(char player)
{
    // Kiểm tra các dòng và cột
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Kiểm tra các đường chéo
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

// Kiểm tra xem bảng đã đầy chưa
bool isBoardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Thực hiện lượt đi của người chơi
void playerMove()
{
    int row, col;
    printf("Luot di cua nguoi choi %c\n", currentPlayer);
    do
    {
        printf("Nhap dong (0-2): ");
        scanf("%d", &row);
        printf("Nhap cot (0-2): ");
        scanf("%d", &col);
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
    board[row][col] = currentPlayer;
}

// Thực hiện lượt đi của máy tính
void computerMove()
{
    printf("Luot di cua may tinh (%c)\n", computerPlayer);
    srand(time(NULL));
    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = computerPlayer;
}

int main()
{
    bool gameOver = false;
    initBoard();
    printf("Chao mung den voi tro choi Tic-Tac-Toe!\n");
    while (!gameOver)
    {
        displayBoard();
        playerMove();
        if (checkWin(currentPlayer))
        {
            displayBoard();
            printf("Nguoi choi %c thang!\n", currentPlayer);
            gameOver = true;
            break;
        }
        else if (isBoardFull())
        {
            displayBoard();
            printf("Tro choi hoa!\n");
            gameOver = true;
            break;
        }
        displayBoard();
        computerMove();
        if (checkWin(computerPlayer))
        {
            displayBoard();
            printf("May tinh (%c) thang!\n", computerPlayer);
            gameOver = true;
        }
        else if (isBoardFull())
        {
            displayBoard();
            printf("Tro choi hoa!\n");
            gameOver = true;
        }
    }
    return 0;
}
