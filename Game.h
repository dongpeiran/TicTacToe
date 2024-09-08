#pragma once

//棋盘长宽 符号的定义
#define ROW 15
#define COL 15

#define VL 5 //Victory length

//函数的声名

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
char ComputerMove(char board[ROW][COL], int row, int col);
