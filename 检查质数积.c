//帕秋莉发现了一本古老的魔法书...
//TLE算法,不推荐
long long arr[1050] = { 0 };
long long p[1050] = { 0 }, q[1050] = {0};

int find(long long n)
{
	if (n == 0ll || n == 1ll)
	{
		return 0;
	}
	long long j = 2ll;
	for (j =2; j < n / 2;j++)
	{
		if (n % j == 0ll)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int ptr = 0;
	int T = 0;
	scanf("%d", &T);
	int i = 0;
	long long f = 0;
	long long sd = 0;
    long double fsd = 0;
	for (i = 0; i < T; i++)
	{
		scanf("%lld", &arr[i]);
	}
	for (i = 0; i < T; i++)
	{
		for (f = 2ll; f * f * f <= arr[i] / 2ll ; f++)
		{
			if (find(f) == 1)
			{
				sd = arr[i] / (f * f * f);
				fsd = (long double)arr[i] / (long double)(f * f * f);
				if (fsd != sd)
				{
					continue;
				}
				q[ptr] = sd;
				if (find(q[ptr]))
				{
					p[ptr] = f;
					ptr++;
					break;
				}
				else
				{
					p[ptr] = 0ll;
					q[ptr] = 0ll;
					continue;
				}
			}
		}
		printf("%lld %lld\n", p[i], q[i]);
	}

	return 0;
}
