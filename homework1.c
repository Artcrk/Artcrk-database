#include <stdio.h>
#include <string.h>

struct candidates
{
	char name[21];
	int num;

}Li,Zhang,Sun;

int main()
{
	Li.num = 0, Zhang.num = 0, Sun.num = 0;
	strcpy(Li.name, "Li");
	strcpy(Zhang.name, "Zhang");
	strcpy(Sun.name, "Sun");
	int n,i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		char jud[21] = { '\0' };
		scanf("%s", &jud);
		if (0 == strcmp(jud, Li.name))
		{
			Li.num++;
		}
		else if (0 == strcmp(jud, Sun.name))
		{
			Sun.num++;
		}
		if (0 == strcmp(jud, Zhang.name))
		{
			Zhang.num++;
		}
	}
	printf("%s:%d\n", Li.name, Li.num);
	printf("%s:%d\n", Zhang.name, Zhang.num);
	printf("%s:%d\n", Sun.name, Sun.num);
	return 0;
}
