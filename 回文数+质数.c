int jud(int n)
{
	int sk = 0;
	if (n == 1 || n == 0)
	{
		return 0;
	}
	for (sk = 2; sk < n; sk++)
	{
		if (n % sk == 0)
		{
			return 0;
		}
	}
	return 1;
}

int final(int ac)
{
	char shit[12] = { '\0' };
	int ju = 1;
	int y = 0;
	for (; ju; y++)
	{
		shit[y] = (char)(ac % 10);
		if (ac < 10)
		{
			ju = 0;
		}
		ac /= 10;
	}
	
	int lon = y;
	/*for (int j = 0; j < 12; j++)
	{
		if (shit[j] == '\0')
		{
			lon = j + 1;
			break;
		}
	}*/
	for (int i = 0; i < lon && i <= lon -i -1; i++)
	{
		if (shit[i] == shit[lon - i -1])
		{
			continue;
		}
		else 
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int k,art = 1;
	int i = 0;
	scanf("%d", &k);
	for(i = k+1;art;i++)
	{
		if (final(i) && jud(i))
		{
			art = 0;
		}
	}
	printf("%d", i-1);
	return 0;
}
