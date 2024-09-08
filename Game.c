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

这是个测试函数，用来测试DisplayBoard函数

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

	//判断坐标是否合法
	while (1)
	{
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//下棋

			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("(￣﹏￣；)The coordinates have been occupied!\n");
				break;
			}
		}
		else
		{
			printf("(￣﹏￣；)The coordinates are illegal ~\n");
			break;
		}
	}
}
*/


void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;


    // 初始化光标位置
    x = row / 2;
    y = col / 2;


    while (true)
    {
        // 清除屏幕
        system("cls");

        // 打印当前棋盘
		char boardsave = board[x][y];
		board[x][y] = '+';
		DisplayBoard(board, ROW, COL);
		board[x][y] = boardsave;

        // 输出当前光标位置
        printf("Cursor Position: (%d, %d)\n", x + 1, y + 1);

        // 读取键盘输入
        int key = _getch();

        // 处理方向键
        switch (key)
        {
        case 72:  // 上箭头
            if (x > 0)
                x--;
            break;
        case 75:  // 左箭头
            if (y > 0)
                y--;
            break;
        case 77:  // 右箭头
            if (y < col - 1)
                y++;
            break;
        case 80:  // 下箭头
            if (x < row - 1)
                x++;
            break;
        case 13:  // 回车键
            if (board[x][y] == ' ')
            {
                board[x][y] = 'O';
                printf("Player placed a move at (%d, %d)\n", x + 1, y + 1);
				Sleep(200);
                return;  // 结束函数
            }
            else
            {
                printf("(￣﹏￣；) The coordinates have been occupied!\n");
                getchar();  // 等待用户按任意键继续
            }
            break;
        default:
            break;
        }
    }
}



// 检查是否有获胜的机会
int CheckWin(char board[ROW][COL], char player)
{
    // 检查行
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

    // 检查列
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

    // 检查正向对角线
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

    // 检查反向对角线
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

// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;

    printf("[Computer go] Please wait for a moment...\n");

    // 检查是否有获胜的机会
    int winPos = CheckWin(board, 'X');
    if (winPos != -1) {
        x = winPos / COL;
        y = winPos % COL;
        board[x][y] = 'X';
        printf("Computer moves to (%d, %d)\n", x, y);
        return;
    }

    // 检查是否需要阻止对手获胜
    int blockPos = CheckWin(board, 'O');
    if (blockPos != -1) {
        x = blockPos / COL;
        y = blockPos % COL;
        board[x][y] = 'X';
        printf("Computer blocks at (%d, %d)\n", x, y);
        return;
    }

    // 优先选择中心位置
    int centerPos = (ROW / 2) * COL + (COL / 2);
    if (board[centerPos / COL][centerPos % COL] == ' ') {
        x = centerPos / COL;
        y = centerPos % COL;
        board[x][y] = 'X';
        printf("Computer moves to (%d, %d)\n", x, y);
        return;
    }

    // 随机选择空位
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



//返回值：'*'玩家赢，'#'电脑赢，Q平局，C游戏继续

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

	//判断平局
	int ret = IS_FULL(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	return 'C';

}
*/





// 返回值：'*'玩家赢，'#'电脑赢，'Q'平局，'C'游戏继续
char isWin(char board[ROW][COL], int row, int col)
{
    // 检查水平方向的胜利条件
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

    // 检查垂直方向的胜利条件
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

    // 检查正对角线的胜利条件
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

    // 检查反对角线的胜利条件
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

    // 检查平局
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