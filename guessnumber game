#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <windows.h>

void game()
{
	system("cls");
 //系统操作符清屏,*0.
	int ran = rand()%100+1;
 //取模得到范围,*1,
	int num = INT_MAX;
 //极限知识,*2,
	int p = 1;

start2:
//标签跳转知识,*3,
	printf("Please input the number what you're guessed\n");

	while (num != ran)
	{
		p = scanf("%d", &num);
  //scanf返回值有误的重新处理,*4
  //第一次成功!!
		if (p != 1)
		{
			printf("Wrong input,please retry.\n");
			Sleep(500);
   //停止函数,*5,
			int g;
			while (g = getchar() != '\n')
			{
				;//空取字符器,用于清空缓冲区,*6
			}
			system("cls");
			p = 1;
   //警示,把判定值初始化,
			goto start2;
   //标签走向,*7
		}
		if (num > ran)//大小比较和连续if判定.*8
		{
			printf("猜大了\n");

		}
		else if(num < ran)
		{
			printf("猜小了\n");
		}
		else 
		{
			printf("猜对了!就是%d", num);
			Sleep(2000);
			system("cls");
			break;//打破循环.*9
		}
	}
	
}

void menu()//void制造函数,使得主函数变得简洁.*10
{
	printf("********************************\n");
	printf("********************************\n");
	printf("*********** 1.play *************\n");
	printf("*********** 0.exit *************\n");
	printf("********************************\n");
	printf("********************************\n");
}

int main() 
{
	srand((unsigned int)time(NULL));
 //新学,使用时间戳产生伪随机数.*11
	int input = 1;
	int p = 1;
start:
	do//使用dowhile循环保证整个循环体的可重复性,*12
	{
		menu();
		printf("Please choose the option:>");
		p = scanf("%d", &input);
		if (p != 1)
		{
			printf("Wrong input,please retry.\n");
			int g;
			while (g = getchar() != '\n')
			{
				;
			}
			Sleep(500);
			system("cls");
			p = 1;
			goto start;
		}
		switch (input)
  //使用switch函数对简介输入式进行分类并走向,简介,*13
		{
		case 1:
			game();
			break;
		case 0:
			printf("Escaping.");
			Sleep(300);
			printf(".");
			Sleep(300);
			printf(".");
			Sleep(300);
			break;
		default:
			printf("Wrong input,please retry.");
			Sleep(700);
			system("cls");
			break;//切记每个条件后要加break,否则会滑落.*14
		}
	} while (input);//使用直接0与非0判断是否循环,使用了数的真假,*15
	return 0;
}
