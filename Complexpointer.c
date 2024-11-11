#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>

void print(int arr[3][5],int a, int b)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void hyprint(int(*p)[1], int a, int b)
{
	int cc = 0;
	int rr = 0;
	for (cc = 0; cc < a; cc++)
	{
		for (rr = 0; rr < b; rr++)
		{
			printf("%d ", *(*(p + cc) + rr));
			/*p,使用的是arr[0][0]的地址.步长为一整个arr[NOT][AND];
			 每加一相当于移动指针到了arr[n+1][0]的地方;
			
			*p和p都是指向arr[0][0],但是前者加一,会在内部加上指针的原始int步长
			而后者加一,由于接收了5个int的长度,所以会加五个int长;
			但是由于一个*p指向了一整个(5个元素的)arr[n][1~5];
			我们在p的地址上加上一个1,就会一次移动一整个对象值,也就是5个.相当于换层的效果.
			而,我们的*p加一,就是引用这个复指针(一整个数组),此时其就是一个普通指针.
			*(*p)得到的一直是arr[0][0]的值;
			*(*(p+col)+row)得到的,最终变成了arr[col][row]的值;*/
		}
		printf("\n");
	}

}
 
int main()
{
	HANDLE Col = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Col, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("//////////////////////////////////////////////////////////////////\n");
	int arr[3][5] = { { 1,2,3,4,5 }, { 6, 7, 8, 9, 10 } ,{ 11, 12, 13, 14, 15 } };
	int art = 0;
start:

	print(arr, 3, 5);
	printf("\n\n\n");
	hyprint(arr, 3, 5);



	printf("//////////////////////////////////////////////////////////////////\n");
	printf("\nRetry?Input 1.\n>:");
	scanf("%d", &art);
	if (art == 1)
	{
		goto start;
	}
	return 0;
} 
