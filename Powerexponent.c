#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void yur(int n)
{
	int i = 0;
	int sn = n;
	int sr = (n - 1);
	int arr[40] = { -1 };
	int m = 0;
	for (m = 0; m < 40; m++)
	{
		arr[m] = -1;
	}
	int cc = 0;
	int uu = 0;
	int judstop = 0;

	for (i = 0; i < 32; i++)
	{
		if (judstop > 1)
		{
			break;
		}
		if (sr <= 0)
		{
			judstop++;
		}
		if ((sr % 2 == 0||sr ==0)&&judstop < 2)
		{
			arr[cc] = i;
			cc++;
			sn >>= 1;
			sr = sn - 1;
			continue;
		}
		sn >>= 1;
		sr = sn - 1;
	}

	for (uu = cc-1; uu >= 0; uu--)
	{
		if (arr[uu] == 1)
		{
			printf("2");
			if (uu > 0)
			{
				printf("+");
			}
		}
		else {
			
			if (arr[uu] == 0)
			{
				printf("2(0)");
			}
			else if (arr[uu] == 2)
			{
				printf("2(2)");
			}
			else if (arr[uu] > 2)
			{
				printf("2(");
				yur(arr[uu]);
				printf(")");
			}
			if (uu>0)
			{
				printf("+");
			}
		}
	}
	return;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	yur(n);
	return 0;
}
