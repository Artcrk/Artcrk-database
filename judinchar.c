int main()
{
	char crr[2000] = { '\0' };
	int jud = 1;
	char j = 'o';
	int y = 0;
	for (y = 0; jud; y++)
	{
		j = getchar();
		if (j == '\n')
		{
			crr[y] = j;
			jud = 0;
			continue;
		}//本来想用scanf,但是发现单个scanf遇到' '就停止了,所以设置了一个遇到回车'\n'才停止的getchar循环.顺便把检测范围框定了,得到的数据大小值.
		else { crr[y] = j; }
	}
	int ls = y + 1;
	int En = 0, Num = 0, sp = 0, els = 0;
	char* p = &crr[0];
	for (int i = 0; i < ls; i++)
	{
		p = &crr[i];//因为一直写crr[i]太麻烦了,于是考虑到用指针简化.注意,是赋值给p(地址)而不是给*p(解引用的值).因为我们需要指向我们所需的数组的值.
		if (*p == 10)
		{
			break;
		}else
		if ((*p > 64 && *p < 91 )||(*p >96 && *p <123))
		{
			En++;
			continue;
		}
		else if (*p == 32)//空格居然是32吗,以前一直以为是0,看来'\0'才是0,'\n'是10,' '是32.
		{
			sp++;
			continue;
		}
		else if (*p > 47 && *p < 58)
		{
			Num++;
			continue;
		}
		else
		{
			els++;
			continue;
		}
	}
	printf("%d %d %d %d", En, Num, sp, els);
	return 0;
}
