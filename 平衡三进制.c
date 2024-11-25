#define _CRT_SECURE_NO_WARNINGS 1

//#include <cstdio>
//#include <cstdlib>
//#include <iostream>
//#include <algorithm>
//#include <cstring>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
typedef struct Lpoint* ST_P;


void Rear_in(int n);


struct Lpoint
{
	struct Lpoint* just;//上一节点

	int data;
	short A_Encth[20];//先用短整型把数据存下来.到最后再转换计算.
	short power;//幂次
	//bool next_way;//从该节点到达下一节点的路径方式
	short next_way;
	struct Lpoint* next;//下一节点
}V;

ST_P head = NULL;
ST_P last = NULL;

int three[21];

 
void Rear_in(int n)//尾插法
{
	ST_P temp = (ST_P)malloc(sizeof(V));//局部指针在运行完成后会自动销毁,但是内存不会

	temp->data = n;//插入值
	temp->next = NULL;//尾插,所以下一个就是NULL;
	//初始化基础值.
	
	if (head == NULL)
	{
		head = temp;
		head->just = NULL;//注意初始化首元素的just
	}
	
	if (last == NULL)
	{
		last = temp;
	}
	if (last != temp)
	{
		last->next = temp;
		temp->just = last;//指向之前的last;
		last = temp;
	}
	for (int y = 0; y < 20; y++)
	{
		last->A_Encth[y] = 0;
	}
	//last->next_way = true;
	last->next_way = 1;
	last->power = 0;
}
//反向判断累加
void pre_put(ST_P* Lptr)
{
	while (1)
	{
		if ((*Lptr)->next == NULL && (*Lptr)->just == NULL)
		{
			break;
		}
		if ((*Lptr)->next == NULL && (*Lptr)->just != NULL)
		{
			(*Lptr) = (*Lptr)->just;
			continue;
		}
		else
		{
			for (int ui = 0;ui < 20 - (*Lptr)->next->power;ui++)//倒序合成
			{
				if ((*Lptr)->next_way)
				{
					(*Lptr)->A_Encth[(*Lptr)->next->power+ui] += -1 * ((*Lptr)->next->A_Encth[(*Lptr)->next->power+ui]);
				}
				else
				{
					(*Lptr)->A_Encth[(*Lptr)->next->power+ui] += (*Lptr)->next->A_Encth[(*Lptr)->next->power+ui];
				}
			}
			
		}
		if((*Lptr)->just == NULL)
		{
			break;
		}
		else
		{
			(*Lptr) = (*Lptr)->just;
		}

	}
}


void jud(int* j,int* lefde,int *rigde,int data)//循环判断体系;
{
	
	for (*j = 1; *j < 21; (*j)++)
	{
		*lefde = data - three[*j];
		if (*j != 20)
		{
			*rigde = three[(*j) + 1] - data;
		}
		if (data >= three[*j] && data < three[(*j)+1])
		{
			break;
		}
	}

}

//正向搜索放入
void jud_put(int powers ,int to_next,ST_P* lastr)//数据,幂,本次到下次的路径选择.以及本次需要初始化的链节(ture 为向右,false为向左)
{
	int j;
	int lefde;
	int rigde;
	for (;;)
	{
		jud(&j, &lefde, &rigde, (*lastr)->data);
		if ((*lastr)->data == three[j])
		{
			powers = 20 - j;
			(*lastr)->A_Encth[powers] = 1;
			(*lastr)->power = powers;
			break;//到这种情况时就退出.
		}
		
		//固定幂次位为1.逆向输入,按逆向位次.为了分辨,在最高位后,向前一位加入'N'.j+1是右边的下标
		if (j == 20)
		{
			Rear_in(lefde);
			

			(*lastr)->next_way = 0;
			(*lastr)->A_Encth[powers] = 1;
			(*lastr)->power = powers;

			(*lastr) = (*lastr)->next;
			continue;
		}
		if ((*lastr)->data > ((three[j + 1] - 1) / 2))//表示数据点离右侧更近,这里使用了平衡三进制的特点.第n+1项除以二比前n项累加的和大0.5.
		{
			
			powers = 19 - j;
			//right
			Rear_in(rigde);
			//(*lastr)->next->data = lefde;//用于下一次检测所用的data.第一次的data就是输入的值.

			(*lastr)->next_way = 1;//表示走的右路
			(*lastr)->A_Encth[powers] = 1;//逆向放入一个1,是必有的一个1.等传完后再反向求索.
			(*lastr)->power = powers;

			(*lastr) = (*lastr)->next;

		}//注意,上面A_Encth的下标只到19.所以而powers至少从2开始,所以应该用20-power.
		else
		{
			powers = 20 - j;
			//left
			Rear_in(lefde);//添加链节//用于下一次检测所用的data.第一次的data就是输入的值.
			//(*lastr)->data = rigde;

			(*lastr)->next_way = 0;//表示走的左路
			(*lastr)->A_Encth[powers] = 1;//逆向放入一个1,是必有的一个1.等传完后再反向求索.无论走哪一边.
			(*lastr)->power = powers;

			(*lastr) = (*lastr)->next;
		}
	}
	return;

}

void print(ST_P pu,int oi)
{
	for (;;oi++)
	{
		if (oi + 1 > 20)
		{
			break;
		}
		switch (pu->A_Encth[oi])
		{
		case 0:
			printf("0");
			break;
		case 1:
			printf("1");
			break;
		case -1:
			printf("-");
			break;
		}
	}
	printf("\n");
}


int main()
{
	
	int n = 0, i = 0, j = 0;
	scanf("%d", &n);
	int input = 0;
	int iap = 1;

	for (i = 0; i < 20; i++)//储存所有可能用上的3的进位.固定20次循环.不用每一次都从0开始循环计算到对应值.
	{
		iap = (int)pow(3, i);
		three[i + 1] = iap;//1,3,9,27......
	}
	iap = 0;
	ST_P tryer = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);
		if (input == 0)
		{
			printf("0\n");
			continue;
		}
		Rear_in(input);
		tryer = last;
		jud_put(head->power, head->next_way, &tryer);
		pre_put(&tryer);
		print(tryer,tryer->power);

		ST_P temps = NULL;
		while (1)//从尾部清空建立的链表.
		{
			
			if (last != NULL)
			{
				if (last == head)
				{
					temps = head;
					head = NULL;
					last = NULL;
					free(temps);
				}
				else
				{
					temps = last;
					if (last->just != NULL)
					{
						last = last->just;
					}
					free(temps);//这里可能出错
					
					
				}

			}
			else
			{
				break;
			}
		}

	}

	return 0;
}
