#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//initialize board.
{
	int i = 0;
	int j = 0;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			board[j][i] = ' ';//����ʼ��Ϊ�ո�.
		}
	}
}

void Boardoutput(char chessboard[ROW][COL], int row, int col)
{
	int r = 0;
	int c = 0;
	int re_c = 0;
	HANDLE put = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(put, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (c = 0; c < col; c++)//��ӡ�Ͻ�
	{
		if (c == col - 1)
		{
			printf("========>>\n\n\n");
		}
		else if(c == 0)
		{
			printf("\n<<========");
		}
		else 
		{
			printf("===");
		}
	}
	SetConsoleTextAttribute(put, FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (r = 0; r < row; r++)//��ӡ��������
	{
		for (c = 0; c < col; c++)
		{
			if (c == col - 1)//col - 1������c,�Ǹ��к�һ��ֵ.
			{
				printf(" %c \n", chessboard[r][c]);//���һ������
			}
			else 
			{
				printf(" %c |", chessboard[r][c]);
			}
			
		}
		for (re_c = 0; re_c < col; re_c++)
		{
			if (r == row - 1)//����ӡ���һ��.
			{
				break;
			}
			if (re_c == col - 1)//ͬ��
			{
				printf("---\n");//���һ��������
			}
			else 
			{
				printf("---|");

			}
		}
	}
	SetConsoleTextAttribute(put, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (c = 0; c < col; c++)//��ӡ�½�
	{
		if (c == col - 1)
		{
			printf("========>>\n");
		}
		else if (c == 0)
		{
			printf("\n\n<<========");
		}
		else
		{
			printf("===");
		}
	}
}

