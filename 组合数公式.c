#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef long long ll;

ll factor(ll k)
{
	ll io = 1;
	ll r = 1;
	for (;r <= k; r++)
	{
		io *= r;
	}
	return io;
}

int main()
{
	ll a = 0,b = 0;
	printf("Input m,k(10>=m>=k>0):\n");
	scanf("%d,%d", &a,&b);
	ll rs = factor(a) / (factor(b) * factor(a - b));
	printf("p = %lld\n", rs);
	return 0;
}
