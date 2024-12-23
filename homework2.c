#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <limits.h>

struct student
{
	long long num;
	char name[22];
	int score;
}A,B;


int main()
{
	struct student ours[201];
	int n = 0;
	int max[2] = { INT_MIN,0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld %s %d", &ours[i].num, &ours[i].name, &ours[i].score);
	}
	int i = 0, j = 0;
	
	for (i = 0; i < n; i++)
	{
		max[0] = INT_MIN;
		max[1] = 0;
		for (j = 0; j < n; j++)
		{
			if (ours[j].score == -1)
			{
				continue;
			}
			if (ours[j].score > max[0])
			{
				max[0] = ours[j].score;
				max[1] = j;
			}
		}
		printf("%lld %s %d\n", ours[max[1]].num, ours[max[1]].name, ours[max[1]].score);
		ours[max[1]].score = -1;
	}
	return 0;
} 
