#include<stdio.h>
#include <windows.h> 
#include <conio.h>
#include "Game.h"
#include <stdbool.h>

//打印一个菜单
void menu() {
	system("cls"); // 清屏

	printf("                         ||                           ||||                                  |||\n");
	printf("                         ||||                         |||||                    |||          ||||\n");
	printf("                  ||     |||                          ||||                    ||||          |||\n");
	printf("                   ||||   |||                           ||||||||||              |||    ||    |||\n");
	printf("                   |||||  ||                    || ||||||||||||||||             |||    |||   |||\n");
	printf("                    |||   ||                    ||||||||||    ||||||            ||     ||||  |||\n");
	printf("                    |||   |||||||              |||||          |||||             ||     |||   ||||||\n");
	printf("                    |||||||||||||             ||||            ||                ||      || ||||||||\n");
	printf("              ||||||||||||||||               ||||     |||||                    ||||||||||||||||||\n");
	printf("                ||||||||  ||                  ||| |||||||||||               ||||||||||||||||||||\n");
	printf("                    |||   ||                      |||||| ||||             |||||||||     ||   |||\n");
	printf("                    |||   ||                       ||   |||||               ||||||      ||||||||\n");
	printf("                    |||   ||  |||||                   |||||                    |||      ||||||||\n");
	printf("                    |||||||||||||||||                 ||||                    ||||||    ||   ||\n");
	printf("            |||||||||||||||||||||||||                  ||| |||||||||          |||||||   |||||||\n");
	printf("            |||||||||||   ||                       ||||||||||||||||||        ||||||||   |||||||\n");
	printf("             |||   ||||   ||               ||||||||||||||||||||||||||       ||| ||  |   |||| ||\n");
	printf("                   |||    ||                ||||||||||  |||                 ||| ||      ||   |||||||||\n");
	printf("                   |||    ||                 |||        |||                |||  ||  ||||||||||||||||||\n");
	printf("                  |||     ||                            |||               |||   || ||||||||\n");
	printf("                  |||     ||                            |||               ||   |||  || |||   ||\n");
	printf("                 |||      ||                            |||                    |||     ||||  ||||\n");
	printf("                |||       ||                            |||                    |||     |||    |||||\n");
	printf("               |||        ||                           ||||                    |||    |||      ||||\n");
	printf("              |||         ||                       ||||||||                    |||   |||        ||||\n");
	printf("                          ||                        |||||||                    |||  |||          |||\n");
	printf("                          ||                          ||||                      || |||            |\n");
	printf("                          |                            ||\n");


	printf("\033[32mYu Zihan's special edition\033[32m\n");
	printf("\033[1;31mWelcome to the Game Menu  (￣y△,￣)╭\033[0m\n\n");
	printf("\tYou can find game modes and standard input methods here!\n");
	//printf("\033[1;34m1. Play\033[0m\n");
	//printf("\033[1;34m2. Help\033[0m\n");
	//printf("\033[1;34m0. Exit\033[0m\n\n");
}




int getMenuChoice()
{
	int choice = 0;
	int selected = 1;

	do {
		menu();

		// 高亮显示当前选项
		for (int i = 1; i <= 3; i++) {
			if (i == selected) {
				printf("\033[1;31m");
			}
			printf("%d. %s\033[0m\n", i, (i == 1 ? "Play" : (i == 2 ? "Help" : "Exit")));
		}

		// 读取按键输入
		int key = _getch();
		switch (key) {
		case 72: // 上箭头
			selected--;
			break;
		case 80: // 下箭头
			selected++;
			break;
		case 13: // Enter 键
			choice = selected;
			break;
		}

		// 限制选项范围
		if (selected < 1) {
			selected = 1;
		}
		else if (selected > 3) {
			selected = 3;
		}

	} while (choice == 0);

	return choice;
}




void printGameGuide()
{
	int currentPage = 1;
	const int totalPages = 4;

	while (1) {
		system("cls"); // 清屏

		// 打印当前页面标题
		printf("\033[1;32mPage %d/%d\033[0m\n", currentPage, totalPages);
		printf("\033[1;34mPress up or down arrow keys to navigate, and press ESC to exit.\033[0m\n\n");

		// 根据当前页面显示不同内容
		switch (currentPage) {
		case 1:
			printf("\033[1;32mGame Modes:\033[0m\n");
			printf("\t\033[1;33m1. Play\033[0m: Start a new game.\n");
			printf("\t\033[1;33m2. Help\033[0m: Show this help menu again.\n");
			printf("\t\033[1;33m0. Exit\033[0m: Exit the game.\n\n");
			break;
		case 2:
			printf("\033[1;32mStandard Input Methods:\033[0m\n");
			printf("\t- Use \033[1;33m<1-N> <1-N>\033[0m to indicate the prevention of marking coordinates.\n");
			break;
		case 3:
			printf("\033[1;32mTips:\033[0m\n");
			printf("\t- Try to get three of your marks in a row (horizontally, vertically, or diagonally).\n");
			printf("\t- Try your best to prevent the computer from winning! (Actually, it's quite foolish).\n");
			printf("\t- Plan ahead and think strategically.\n");
			break;
		case 4:
			printf("\033[1;32mCredits:\033[0m\n");
			printf("\t- Developed by iampeiru.\n");
			printf("\t- Inspired by the classic game Tic Tac Toe.\n");
			printf("\t- Special thanks to my friend for the idea.\n\n");

			printf("\033[1;32mV2.0 update content\033[0m\n");
			printf("\t-Now keyboard control is available \n");
			printf("\t-Added a help page\n");
			printf("\t-Added a game UI\n");
			break;
		}

		// 读取按键输入
		int key = _getch();
		switch (key) {
		case 72: // 上箭头
			currentPage--;
			break;
		case 80: // 下箭头
			currentPage++;
			break;
		case 27: // ESC 键
			return;
		}

		// 限制页面范围
		if (currentPage < 1) {
			currentPage = 1;
		}
		else if (currentPage > totalPages) {
			currentPage = totalPages;
		}
	}
}




void game()
{
	//存储数据（二维数组）
	char board[ROW][COL];

	//初始化棋盘（初始化空格）
	InitBoard(board, ROW, COL);

	//打印棋盘
	DisplayBoard(board,ROW,COL); 

	char ret;//接受游戏状态

	while(1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);

		//判断玩家是否赢得游戏
        ret = isWin(board,ROW,COL);

		if (ret == 'O')
		{
			printf("< Player win! >\n");
			break;
		}
		else if (ret == 'X')
		{
			printf("< Computer win! >\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("< Draw! >\n");
			break;
		}

		//电脑下棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);

		//判断是否赢得游戏
		ret = isWin(board, ROW, COL);

		if (ret == 'O')
		{
			printf("< Player win! >\n");
			break;
		}
		else if (ret== 'X')
		{
			printf("< Computer win! >\n");
			break;
		}
		else if(ret == 'Q')
		{
			printf("< Draw! >\n");
			break;
		}

	}
}



//主函数，游戏逻辑测试

int main(void)
{
	int choice = 0; //玩家开始菜单的选择
	do
	{

		//menu();
		choice = getMenuChoice();

		switch(choice)
		{
			case 1:
				printf("<(￣︶￣)↗[PLAY!]\n"); 
				game();
				Sleep(2000);	
				break;
			case 3:
				printf("BYE!  QAQ\n");
				break;
			case 2:
		        printGameGuide();
				break;
			default:
				printf("Wrong choice ╰（‵□′）╯\n\n\n");
				break;

		}

	} while (choice != 3);
	
	return 0;
}
