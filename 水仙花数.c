#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int fat(long long k)
{
	long long kr = k;
	long long sum = 0;
	long long rt = 0;
	long long ok = k,ksum = 1;
	while (1)
	{
		if (ok > 9)
		{
			ok /= 10;
			ksum++;
		}
		else
		{
			break;
		}
	}
	if (ksum == 2)
	{
		return 0;
	}
	for (;;)
	{
		rt = kr % 10;
		sum += pow(rt,ksum);
		if (sum > k)
		{

			return 0;
		}
		else if (sum == k)
		{

			return 1;
		}
		if (kr > 9)
		{
			kr /= 10;
			continue;
		}
		else if (kr < 10)//注意,有些数加完后结果还没自己大,这时要注意把最后一次区分出来,强制退出.
		{
			return 0;
		}
		
	}
}
int main()
{

	short* ui = (short*)malloc(sizeof(short) * 200000);
	long long k = 1;
	long long i = 0;
	short xtu = 0;
	long long out = 0;
	do 
	{
		scanf("%lld", &k);
		if (k == 0)
		{
			break;
		}
		if (fat(k))
		{
			ui[xtu] = 1;
			xtu++;
		}
		else
		{
			ui[xtu] = 0;
			xtu++;
		}

	} while (k);
	for (out = 0; out < xtu; out++)
	{
		if (ui[out])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
