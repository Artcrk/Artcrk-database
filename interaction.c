#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Boardinput(char board[ROW][COL], int row, int col)//玩家下棋
{
	HANDLE colorset = GetStdHandle(STD_OUTPUT_HANDLE);
	int row_custom, col_custom;
	while (1)
	{
		printf("Choose where you want to place your pieces.\n>:");
		scanf("%d%d", &row_custom, &col_custom);
		if (row_custom <= ROW && col_custom <= COL && col_custom > 0 && row_custom > 0)
		{
			if (board[row_custom - 1][col_custom - 1] == ' ')//判断是否被占用
			{
				board[row_custom - 1][col_custom - 1] = '*';//改变字符
				break;//跳出无限循环
			}
			else 
			{
				SetConsoleTextAttribute(colorset, FOREGROUND_RED);
				printf("Site occupied,please choose again.\n");
				SetConsoleTextAttribute(colorset, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
		}
		else
		{
			SetConsoleTextAttribute(colorset, FOREGROUND_RED);
			printf("Unaccepted input,please retry.\n");//输入有误
			SetConsoleTextAttribute(colorset, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		
	}
	system("cls");
}



void Computerinput(char board[ROW][COL], int row, int col)//机器下棋
{
	do
	{
		int FR_row = rand() % row;
		int FR_col = rand() % col;//随机数,考虑AI接口.
		if (board[FR_row][FR_col] == ' ')//占用判断
		{
			board[FR_row][FR_col] = '#';
			break;
		}
	} while (1);
}



char WIN_judge(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int ij = 0;
	int sum1c = 1;
	int sum2r = 1;
	int sum3rca = 1;
	int sum4rcs = 1;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			sum1c = 0;
			sum2r = 0;
			sum3rca = 0;
			sum4rcs = 0;//对于每一个起始点,初始化所有判定体为0

			if (board[i][j] == ' ')
			{
				continue;
			}
			for (ij = 0; ij < CHNR_SET; ij++)
			{
				if (j + CHNR_SET <= col)
				{
					if (board[i][j] == board[i][j + ij])//判断正向横排相等情况
					{
						sum1c++;//由于判断了一次其与自身的相等性,所以判定体均设为0.
					}
				}
				if (i + CHNR_SET <= col)//判断下向竖排相等情况
				{
					if (board[i][j] == board[i + ij][j])
					{
						sum2r++;
					}
				}
				if (i + CHNR_SET <= col && j + CHNR_SET <= col)//判断反斜杠斜向相等情况
				{
					if (board[i][j] == board[i + ij][j + ij])
					{
						sum3rca++;
					}
				}
				if (i + CHNR_SET <= col && j >= CHNR_SET - 1)//判断斜杠斜向相等情况
				{
					if (board[i][j] == board[i + ij][j - ij])
					{
						sum4rcs++;
					}
				}
				if (sum1c == CHNR_SET || sum2r == CHNR_SET || sum3rca == CHNR_SET || sum4rcs == CHNR_SET) {
					return board[i][j];//判断完成情况.
				}
			}
		}
	}
	return 'C';//无结果,返回继续值.
}



void judge_winer(char jdm)
{
	HANDLE colo = GetStdHandle(STD_OUTPUT_HANDLE);
	if (jdm == '*')
	{
		SetConsoleTextAttribute(colo, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("\nPlayer win!!!\n");

	}
	else if (jdm == '#')
	{
		SetConsoleTextAttribute(colo, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("\nComputer win!!!\n");
	}
	else if (jdm == '$')
	{
		SetConsoleTextAttribute(colo, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("\nNobody win...\n");
	}
}