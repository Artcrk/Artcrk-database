#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main() 
{
	int art[8] = { 0 };
	int k = 0;
	int cum = 0;
	for (k = 0; k < 8; k++)
	{
		printf("�������%d������", k + 1);
		cum = scanf("%d", &art[k]);
		if (cum != 1)
		{
			printf("����дѭ�����,дɶС��,���һ�ȥ��������!");
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
	printf("���ֵ��:%d\n", max);
	int avg = 0;
	int sum = 0;
	int yesno = 0;
	int cuum = 0;
	printf("�Ƿ��������ƽ��ֵ?\n");
	printf("����1����,����0����.");
	cuum = scanf("%d", &yesno);
	if (cuum != 1)
	{
		printf("����");
		return 1;
	}
	if(yesno==1)
	{
		printf("���ڼ�����......\n");
	}
	else {
		return 0;
	}
	for (k = 0; k < 8; k++)
	{
		sum = sum + art[k];
	}
	avg = sum / 8;
		printf("��������ֵ�ƽ��ֵ��%dŶ~", avg);
	return 0;
}