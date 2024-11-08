#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <limits.h>
int row = 0, col = 0;
int C = 0;
int i = 0, j = 0;
int atrr[1050][1050] = { 0 };

int main()
{
	scanf("%d%d%d", &row, &col, &C);
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			scanf("%d", &atrr[i][j]);
		}
	}
	int v = 0, f = 0, sum = 0;
	int r = 0, c = 0;
	int rich = INT_MIN;
	for (v = 0; v < col; v++)
	{
		for (f = 0; f < row; f++)
		{
			sum = 0;
			for (i = v; i < C + v && v + C - 1 <= col; i++)
			{
				for (j = f; j < C + f && f + C - 1 <= row; j++)
				{
					sum += atrr[i][j];
				} 
			}
			if (sum > rich)
			{
				rich = sum;
				c = v;
				r = f;
			}

		}
	}
	printf("%d %d", c + 1, r + 1);
	return 0;
}
