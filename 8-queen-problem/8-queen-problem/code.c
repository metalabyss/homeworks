#include <stdio.h>

// Задача о 8 ферзях (Backtracking method)
// Спойлер: для доски 8х8 кол-во решений - 92

#define SIZE (8) // Размер доски

int board[SIZE][SIZE];
int results_count = 0; // Количество решений.

// Функция распечатывает доску.
void showBoard()
{
    int a = 0;
    int b = 0;

    for (a = 0; a < SIZE; ++a)
    {
        for (b = 0; b < SIZE; ++b)
        {
            if (board[a][b])
            {
                printf("Q ");
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Функция проверяет, нет ли уже установленных ферзей по вертикали и диагоналям.
int tryQueen(int a, int b)
{
    int i;

    for (i = 0; i < a; ++i)
    {
        if (board[i][b])
        {
            return 1;
        }
    }

    for (i = 1; i <= a && b - i >= 0; ++i)
    {
        if (board[a - i][b - i])
        {
            return 1;
        }
    }

    for (i = 1; i <= a && b + i < SIZE; i++)
    {
        if (board[a - i][b + i])
        {
            return 1;
        }
    }

    return 0;
}

// Функция пробует найти результаты решений.
// a - номер очередной строки, в которую нужно поставить очередного ферзя.
void setQueen(int a)
{
    //если дошли до конца - выводим решение
    if (a == SIZE)
    {
        showBoard();
        printf("Solution #%d\n\n", ++results_count);
    }

    int i;
    for (i = 0; i < SIZE; ++i)
    {
        // Здесь проверяем, что если поставим в board[a][i] ферзя (единицу),
        // то он будет единственным в этой строке, столбце и диагоналях.
        if (!tryQueen(a, i))
        {
            board[a][i] = 1;
            setQueen(a + 1);
            board[a][i] = 0;
        }
    }
}

int main()
{
    setQueen(0);

    return 0;
}