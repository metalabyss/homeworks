#include <stdio.h>

// ������ � 8 ������ (Backtracking method)
// �������: ��� ����� 8�8 ���-�� ������� - 92

#define SIZE (8) // ������ �����

int board[SIZE][SIZE];
int results_count = 0; // ���������� �������.

// ������� ������������� �����.
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

// ������� ���������, ��� �� ��� ������������� ������ �� ��������� � ����������.
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

// ������� ������� ����� ���������� �������.
// a - ����� ��������� ������, � ������� ����� ��������� ���������� �����.
void setQueen(int a)
{
    //���� ����� �� ����� - ������� �������
    if (a == SIZE)
    {
        showBoard();
        printf("Solution #%d\n\n", ++results_count);
    }

    int i;
    for (i = 0; i < SIZE; ++i)
    {
        // ����� ���������, ��� ���� �������� � board[a][i] ����� (�������),
        // �� �� ����� ������������ � ���� ������, ������� � ����������.
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