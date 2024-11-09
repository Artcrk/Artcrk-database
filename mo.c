int main()//猴子吃桃子
{
	int n = 0;
	int st = 1;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("2");
		return 0;
	}
	else
	{
		st = 2;
	}
	for (int s = 0; s < n-1; s++)
	{
		
		st += 1;
		st *= 2;
	}
	printf("%d", st);
	return 0;
}
