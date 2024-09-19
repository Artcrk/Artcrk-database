#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"//Ԥ����

void menu()//��ӡ�˵�����
{
	HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨Ȩ��
	SetConsoleTextAttribute(Color, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("***;*********************************************;***\n");
	printf("**;***********************************************;**\n");
	printf("*;*************************************************;*\n");
	printf(";*******************");
	SetConsoleTextAttribute(Color, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("  1.play  ");//��play����ɫ�����Զ���
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
	SetConsoleTextAttribute(Color, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//���ذ�ɫ
}

void game()
{
	int playtimes = 0;
	int sr = 0;
	HANDLE CUT = GetStdHandle(STD_OUTPUT_HANDLE);
	char JDM = 'C';
	char chessboard[ROW][COL];//ʹ��ͷ�ļ��궨�峤��
	InitBoard(chessboard,ROW,COL);//��ʼ������,����InitializeProgram.c������.
	Boardoutput(chessboard, ROW, COL);//��ӡ���� 
	while (1)
	{
		Boardinput(chessboard, ROW, COL);//Ҫ���û�����
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
		Computerinput(chessboard, ROW, COL);//��������
		Boardoutput(chessboard, ROW, COL);
		JDM = WIN_judge(chessboard, ROW, COL);
		playtimes++;
		if (playtimes == ROW * COL && JDM == 'C')//�����еط�����������ֹ��Ϸ,�����˳�.
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
		if (sr || !sr)//��������������
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