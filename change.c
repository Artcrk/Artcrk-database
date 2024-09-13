#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>

char overmax[] = "ABCDEF";

int decode(int c_into,char arr[],int n)
{
	n--;
	int sum = 0;
	for (int j = 0; j <= n; j++)
	{
		if (arr[n - j] >= '0' && arr[n - j] <= '9')
		{
			int Nnum = (arr[n - j] - '0');
			sum += Nnum * pow(c_into, j);
		}
		else
		{
			int Fnum = (arr[n - j] -'A') + 10;
			sum += Fnum * pow(c_into, j);
		}
	}
	return sum;
}

void encode(int c_out,int ten)
{
	if (ten >= c_out)
	{
		encode(c_out, ten / c_out);
	}
	int left = ten % c_out;
	if (left > 9)
	{
		printf("%c", overmax[left - 10]);
	}
	else
	{
		printf("%d", left);
	}
}

int main()
{
	int level_1, level_2;
	char hux[31] = { 0 };
	int i = -1;
	int TEN  = 16;
	scanf("%d%s%d", &level_1, &hux, &level_2);
	do
	{
		i++;
		if (i == 30)
			break;
	} while (hux[i + 1] != '\0');
	i++;
	if (level_1 == level_2)
	{
		for (int ss = 0; ss < i; ss++)
		{
			printf("%c", hux[ss]);
		}
		return 0;
	}
	TEN = decode(level_1, hux,i);
	encode(level_2,TEN);
	return 0;
}
