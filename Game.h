#pragma once

//���̳��� ���ŵĶ���
#define ROW 15
#define COL 15

#define VL 5 //Victory length

//����������

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
char ComputerMove(char board[ROW][COL], int row, int col);
