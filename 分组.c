#include <stdio.h>
int main()
{
int n = 0;//二分模拟均等分组
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int start = 0;
	int end = n - 1;
	int mid;
	int lef, rig;
	int sumlef = 0, sumrig = 0;
	int fid = 0;
	while(start <= end)
	{
		sumlef = 0;
		sumrig = 0;
		mid = (start + end)/2;
		for (lef = 0; lef <= mid; lef++)
		{
			sumlef += arr[lef];
		}
		for (rig = n-1; rig > mid; rig--)
		{
			sumrig += arr[rig];
		}
		if (sumrig == sumlef)
		{
			fid = 1;
			break;
		}
		else if(sumrig != sumlef)
		{
			if (sumrig < sumlef)
			{
				end -= 1;
			}
			else {
				start += 1;
			}
		}
	}
	printf("%d", fid);
	return 0;
}
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
