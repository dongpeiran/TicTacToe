#include "Game.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

/*

���Ǹ����Ժ�������������DisplayBoard����

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i < row - 1)
		{
			printf("---|---|---\n");
		}
	}
}
*/

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
			for (int j = 0; j < col; j++)
			{
				printf(" %c ", board[i][j]);
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
			if (i < row - 1)
			{
				for (int l = 0; l < col; l++)
				{
					printf("---");
					if (l < col - 1)
					{
						printf("|");
					}
				}
				printf("\n");
			}
	}
}



/*
void PlayerMove_DEBUG(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("[ Player go ]Please enter coordinates>");
	scanf_s(" %d %d", &x, &y);

	//�ж������Ƿ�Ϸ�
	while (1)
	{
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����

			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("(���n����)The coordinates have been occupied!\n");
				break;
			}
		}
		else
		{
			printf("(���n����)The coordinates are illegal ~\n");
			break;
		}
	}
}
*/


void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;


    // ��ʼ�����λ��
    x = row / 2;
    y = col / 2;


    while (true)
    {
        // �����Ļ
        system("cls");

        // ��ӡ��ǰ����
		char boardsave = board[x][y];
		board[x][y] = '+';
		DisplayBoard(board, ROW, COL);
		board[x][y] = boardsave;

        // �����ǰ���λ��
        printf("Cursor Position: (%d, %d)\n", x + 1, y + 1);

        // ��ȡ��������
        int key = _getch();

        // �������
        switch (key)
        {
        case 72:  // �ϼ�ͷ
            if (x > 0)
                x--;
            break;
        case 75:  // ���ͷ
            if (y > 0)
                y--;
            break;
        case 77:  // �Ҽ�ͷ
            if (y < col - 1)
                y++;
            break;
        case 80:  // �¼�ͷ
            if (x < row - 1)
                x++;
            break;
        case 13:  // �س���
            if (board[x][y] == ' ')
            {
                board[x][y] = 'O';
                printf("Player placed a move at (%d, %d)\n", x + 1, y + 1);
				Sleep(200);
                return;  // ��������
            }
            else
            {
                printf("(���n����) The coordinates have been occupied!\n");
                getchar();  // �ȴ��û������������
            }
            break;
        default:
            break;
        }
    }
}



// ����Ƿ��л�ʤ�Ļ���
int CheckWin(char board[ROW][COL], char player)
{
    // �����
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j <= COL - 3; j++) {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == ' ') {
                return i * COL + (j + 3);
            }
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 3] == player && board[i][j + 2] == ' ') {
                return i * COL + (j + 2);
            }
            if (board[i][j] == player && board[i][j + 2] == player && board[i][j + 3] == player && board[i][j + 1] == ' ') {
                return i * COL + (j + 1);
            }
            if (board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player && board[i][j] == ' ') {
                return i * COL + j;
            }
        }
    }

    // �����
    for (int j = 0; j < COL; j++) {
        for (int i = 0; i <= ROW - 3; i++) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == ' ') {
                return (i + 3) * COL + j;
            }
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 3][j] == player && board[i + 2][j] == ' ') {
                return (i + 2) * COL + j;
            }
            if (board[i][j] == player && board[i + 2][j] == player && board[i + 3][j] == player && board[i + 1][j] == ' ') {
                return (i + 1) * COL + j;
            }
            if (board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player && board[i][j] == ' ') {
                return i * COL + j;
            }
        }
    }

    // �������Խ���
    for (int i = 0; i <= ROW - 3; i++) {
        for (int j = 0; j <= COL - 3; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == ' ') {
                return (i + 3) * COL + (j + 3);
            }
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 3][j + 3] == player && board[i + 2][j + 2] == ' ') {
                return (i + 2) * COL + (j + 2);
            }
            if (board[i][j] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player && board[i + 1][j + 1] == ' ') {
                return (i + 1) * COL + (j + 1);
            }
            if (board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player && board[i][j] == ' ') {
                return i * COL + j;
            }
        }
    }

    // ��鷴��Խ���
    for (int i = 0; i <= ROW - 3; i++) {
        for (int j = COL - 1; j >= 3; j--) {
            if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == ' ') {
                return (i + 3) * COL + (j - 3);
            }
            if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 3][j - 3] == player && board[i + 2][j - 2] == ' ') {
                return (i + 2) * COL + (j - 2);
            }
            if (board[i][j] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player && board[i + 1][j - 1] == ' ') {
                return (i + 1) * COL + (j - 1);
            }
            if (board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player && board[i][j] == ' ') {
                return i * COL + j;
            }
        }
    }

    return -1;
}

// ��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;

    printf("[Computer go] Please wait for a moment...\n");

    // ����Ƿ��л�ʤ�Ļ���
    int winPos = CheckWin(board, 'X');
    if (winPos != -1) {
        x = winPos / COL;
        y = winPos % COL;
        board[x][y] = 'X';
        printf("Computer moves to (%d, %d)\n", x, y);
        return;
    }

    // ����Ƿ���Ҫ��ֹ���ֻ�ʤ
    int blockPos = CheckWin(board, 'O');
    if (blockPos != -1) {
        x = blockPos / COL;
        y = blockPos % COL;
        board[x][y] = 'X';
        printf("Computer blocks at (%d, %d)\n", x, y);
        return;
    }

    // ����ѡ������λ��
    int centerPos = (ROW / 2) * COL + (COL / 2);
    if (board[centerPos / COL][centerPos % COL] == ' ') {
        x = centerPos / COL;
        y = centerPos % COL;
        board[x][y] = 'X';
        printf("Computer moves to (%d, %d)\n", x, y);
        return;
    }

    // ���ѡ���λ
    while (1)
    {
        x = rand() % row;
        y = rand() % col;

        if (board[x][y] == ' ')
        {
            board[x][y] = 'X';
            printf("Computer moves to (%d, %d)\n", x, y);
            break;
        }
    }
}



int IS_FULL(char board[ROW][COL], int row, int col)
{
	int count = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				count++;
			}
		}
	}

	if (count == 0)
	{
		return 1;
	}

	return 0;
}



//����ֵ��'*'���Ӯ��'#'����Ӯ��Qƽ�֣�C��Ϸ����

/*
char isWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}

	//�ж�ƽ��
	int ret = IS_FULL(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	return 'C';

}
*/





// ����ֵ��'*'���Ӯ��'#'����Ӯ��'Q'ƽ�֣�'C'��Ϸ����
char isWin(char board[ROW][COL], int row, int col)
{
    // ���ˮƽ�����ʤ������
    for (int i = 0; i < row; i++) {
        for (int j = 0; j <= col - VL; j++) {
            bool win = true;
            char marker = board[i][j];
            if (marker == ' ') continue;
            for (int k = 1; k < VL; k++) {
                if (board[i][j + k] != marker) {
                    win = false;
                    break;
                }
            }
            if (win) return marker;
        }
    }

    // ��鴹ֱ�����ʤ������
    for (int j = 0; j < col; j++) {
        for (int i = 0; i <= row - VL; i++) {
            bool win = true;
            char marker = board[i][j];
            if (marker == ' ') continue;
            for (int k = 1; k < VL; k++) {
                if (board[i + k][j] != marker) {
                    win = false;
                    break;
                }
            }
            if (win) return marker;
        }
    }

    // ������Խ��ߵ�ʤ������
    for (int i = 0; i <= row - VL; i++) {
        for (int j = 0; j <= col - VL; j++) {
            bool win = true;
            char marker = board[i][j];
            if (marker == ' ') continue;
            for (int k = 1; k < VL; k++) {
                if (board[i + k][j + k] != marker) {
                    win = false;
                    break;
                }
            }
            if (win) return marker;
        }
    }

    // ��鷴�Խ��ߵ�ʤ������
    for (int i = 0; i <= row - VL; i++) {
        for (int j = VL - 1; j < col; j++) {
            bool win = true;
            char marker = board[i][j];
            if (marker == ' ') continue;
            for (int k = 1; k < VL; k++) {
                if (board[i + k][j - k] != marker) {
                    win = false;
                    break;
                }
            }
            if (win) return marker;
        }
    }

    // ���ƽ��
    bool full = true;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == ' ') {
                full = false;
                break;
            }
        }
        if (!full) break;
    }
    if (full) return 'Q';

    return 'C';
}