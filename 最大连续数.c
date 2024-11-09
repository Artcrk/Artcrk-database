#include<stdio.h>
int main()
{
int n = 0;//最大连续属性值
	int max = 0;
	int remax = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] == arr[i - 1] && i != 0)
		{
			max += 1;
		}
		else if (i == 0)
		{
			max = 1;
		}
		else
		{
			if (max >= remax)
			{
				remax = max;
			}
			max = 1;
		}
		if (i == n - 1 && arr[i] == arr[i - 1])
		{
			
			if (max >= remax)
			{
				remax = max;
			}
		}
		else
		{
			if (max >= remax)
			{
				remax = max;
			}
		}
	}
	printf("%d", remax);
	return 0;
}
