#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void initbro(char bro[RO][CO], int ro, int co, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ro; i++)
	{
		for (j = 0; j < co; j++)
		{
			bro[i][j] = set;
		}
	}
}

void boput(char bro[RO][CO], int ro, int co)
{
	int i = 0; 
	int j = 0;
	printf("<=================================扫雷游戏======================================>\n");
	HANDLE CUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(CUT,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	for (i = 1; i <= ro;i++)
	{
		if (i == 1)
		{
			for (j = 0; j <= co; j++)
			{
				if (j == co)
				{
					printf("---|\n");
				}
				else if (j == 0)
				{
					printf("|---|");
				}
				else
				{
					printf("---|");
				}
			}
			for (j = 0; j <= co; j++)
			{
				if (j == co)
				{
					printf("+%d+|\n",j);
				}
				else if (j == 0)
				{
					printf("|+%d+|",j);
				}
				else
				{
					printf("+%d+|",j);
				}
			}
		}
		for (j = 0; j <= co; j++)
		{
			if (j == co)
			{
				printf("---|\n");
			}
			else if (j == 0)
			{
				printf("|---|");
			}
			else
			{
				printf("---|");
			}
		}
		for (j = 0; j <= co; j++)
		{
			if (j == co) 
			{
				printf(" %c |\n", bro[i][j]);
			}
			else if (j == 1)
			{
				printf(" %c |",bro[i][j]);
			}
			else if (j == 0)
			{
				printf("|+");
				printf("%d", i);
				printf("+|");
			}
			else
			{
				printf(" %c |", bro[i][j]);
			}
			
		}
		if (i == ro) 
		{
			for (j = 0; j <= co; j++)
			{
				if (j == co)
				{
					printf("---|\n");
				}
				else if (j == 0)
				{
					printf("|---|");
				}
				else
				{
					printf("---|");
				}
			}
		}

	}
	SetConsoleTextAttribute(CUT,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("<=================================扫雷游戏======================================>\n");
}

void Setmine(char bomb[RO][CO], int row, int col)
{
	int Mine = MINE;
	while(Mine)
	{
		int r_rand = rand() % ROW;
		int c_rand = rand() % COL;
		if (bomb[r_rand + 1][c_rand + 1] == '0')
		{
			bomb[r_rand + 1][c_rand + 1] = '1';
			Mine--;
		}
	}
}

int ju = 0;
void minefind(char unshow[RO][CO], char show[RO][CO],int R_put, int C_put)//找雷
{
	int mines = 0;
	int i = 0;
	int j = 0;
	int r = 0;
	int c = 0;
	for (i = 0; i <= 2; i++)//检索3x3范围内的mine
	{
		for (j = 0; j <= 2; j++)
		{

			if (unshow[R_put - 1 + i][C_put - 1 + j] == '1')
			{
				mines++;
			}

		}
	}
	show[R_put][C_put] = mines + '0';
}


int FindMine(char unshow[RO][CO], char show[RO][CO])
{
	int R_put = 0;
	int C_put = 0;
	while (1)
	{
		printf("请选择踩位\n>:");
		scanf("%d%d", &R_put, &C_put);
		if (unshow[R_put][C_put] == '0' && R_put > 0 && C_put > 0 && R_put <= ROW && C_put <= COL && show[R_put][C_put] == ' ')
		{
			minefind(unshow, show, R_put, C_put);
			return 1;
		}
		else if (unshow[R_put][C_put] == '1' && R_put > 0 && C_put > 0 && R_put <= ROW && C_put <= COL)
		{
			printf("\nBOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!!!!!!!!\n");
			printf("你被炸死了.\n");
			return 0;
		}
		else
		{
			printf("非法输入或点位已勘探,请重试!");
		}
	}
}
