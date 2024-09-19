#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"//预定义

void menu()//打印菜单界面
{
	HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台权限
	SetConsoleTextAttribute(Color, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("***;*********************************************;***\n");
	printf("**;***********************************************;**\n");
	printf("*;*************************************************;*\n");
	printf(";*******************");
	SetConsoleTextAttribute(Color, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("  1.play  ");//将play的颜色单独自定义
	SetConsoleTextAttribute(Color, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("**********************;\n");
	printf(";*******************");
	SetConsoleTextAttribute(Color, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("  0.exit  ");
	SetConsoleTextAttribute(Color, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("**********************;\n");
	printf("*;*************************************************;*\n");
	printf("**;***********************************************:**\n");
	printf("***;*********************************************;***\n");
	SetConsoleTextAttribute(Color, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//返回白色
}

void game()
{
	int playtimes = 0;
	int sr = 0;
	HANDLE CUT = GetStdHandle(STD_OUTPUT_HANDLE);
	char JDM = 'C';
	char chessboard[ROW][COL];//使用头文件宏定义长宽
	InitBoard(chessboard,ROW,COL);//初始化棋盘,引用InitializeProgram.c的内容.
	Boardoutput(chessboard, ROW, COL);//打印棋盘 
	while (1)
	{
		Boardinput(chessboard, ROW, COL);//要求用户输入
		Boardoutput(chessboard, ROW, COL);
		JDM = WIN_judge(chessboard, ROW, COL);
		playtimes++;
		if (playtimes == ROW * COL && JDM == 'C')
		{
			JDM = '$';
		}
		if (JDM != 'C')
		{
			break;
		}
		system("cls");
		Computerinput(chessboard, ROW, COL);//电脑输入
		Boardoutput(chessboard, ROW, COL);
		JDM = WIN_judge(chessboard, ROW, COL);
		playtimes++;
		if (playtimes == ROW * COL && JDM == 'C')//当所有地方被下满后中止游戏,和棋退出.
		{
			JDM = '$';
		}
		if (JDM != 'C')
		{
			break;
		}
	}
	judge_winer(JDM);
	SetConsoleTextAttribute(CUT, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	while(1)
	{
		printf("\nInput any number to Quit...\n");
		scanf("%d", &sr);
		if (sr || !sr)//包括了所有整数
		{
			break;
		}
	}
	system("cls");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		HANDLE CUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(CUT,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		printf("Please choose an option.\n:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("Loading");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".\n");
			system("cls");
			game();
			break;
		case 0:
			printf("Exiting");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".\n");
			break;
		default:
			printf("Unaccpeted input,please retry.\n");
			Sleep(500);
			system("cls");
			break;
		}
	} while (input);
	return 0;
}