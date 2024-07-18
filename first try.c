#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main() 
{
	int art[8] = { 0 };
	int k = 0;
	int cum = 0;
	for (k = 0; k < 8; k++)
	{
		printf("请输入第%d个数字", k + 1);
		cum = scanf("%d", &art[k]);
		if (cum != 1)
		{
			printf("不会写循环语句,写啥小数,给我回去重新启动!");
			return 1;
		}
	}
	int max = art[0];
	for (k = 1; k < 8; k++)
	{
		if (art[k] > max)
		{
			max = art[k];
		}
	}
	printf("最大值是:%d\n", max);
	int avg = 0;
	int sum = 0;
	int yesno = 0;
	int cuum = 0;
	printf("是否继续计算平均值?\n");
	printf("输入1继续,输入0结束.");
	cuum = scanf("%d", &yesno);
	if (cuum != 1)
	{
		printf("……");
		return 1;
	}
	if(yesno==1)
	{
		printf("正在计算中......\n");
	}
	else {
		return 0;
	}
	for (k = 0; k < 8; k++)
	{
		sum = sum + art[k];
	}
	avg = sum / 8;
		printf("输入的数字的平均值是%d哦~", avg);
	return 0;
}