#define _CRT_SECURE_NO_WARNINGS 1

//还有潜在的bug...
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

void Front_In(int e);

void Rear_In(int n);

bool del_aimdata(int ct);


struct LLst//链节
{
	int Data;
	struct LLst* Next;

}V;//利用这个元素测量数据需要开辟的空间大小.

struct LLst* head = NULL;
struct LLst* last = NULL;

//头插法
void Front_In(int e)//头插法,完成这个头插法需要保证head一定指向第一个或者第"0"个元素.
{
	struct LLst* Headlist = (struct LLst*)malloc(sizeof(V));
	
	Headlist->Next = head;
	Headlist->Data = e;

	head = Headlist;//此时Headlist是头指针
	if (last == NULL)
	{
		last = Headlist;
	}
}
//尾插法
void Rear_In(int n)//尾插法,完成这个,可以只用一个head,但是会增加一些情况下的时间复杂度.
//或许可以创建一个一定指向尾部的指针?
{
	struct LLst* lastlist = (struct LLst*)malloc(sizeof(V));
	lastlist->Data = n;
	lastlist->Next = NULL;

	last->Next = lastlist;//这样就解决了需要很多时间复杂度的问题.保证时间复杂度总为O(1);
	last = lastlist;
	if (head == NULL) 
	{
		head = lastlist;
	}

	//else
	//{
	//	struct LLst* Iap = head;
	//	while (Iap->Next != NULL)
	//	{
	//		Iap = Iap->Next;
	//	}
	//	Iap->Next = lastlist;
	//	//free(Iap);//这样会把Iap指向的地址也释放
	//	Iap = NULL;
	//	delete Iap;//直接把Iap指针销毁,但是不影响其先前指向的地址.
	//}
}
//删除元素
bool del_aimdata(int ct)//按暴力搜索对应元素,然后完成删除操作.需要用到head.
{
	struct LLst* temp = (struct LLst*)malloc(sizeof(V));
	if (head == NULL)//如果链表都没有,删nm呢,直接返回.
	{
		return false;
	}
	else if (head->Data == ct)
	{
		
		temp = head;
		head = head->Next;
		free(temp);
		return true;//返回一个bool值!!
	}
	else
	{
		struct LLst* Pre_connector = (struct LLst*)malloc(sizeof(V));
		Pre_connector = head;

		while (Pre_connector->Next != NULL)//先看pre的下一项是不是NULL,是的话就不进入循环
		{
			if (Pre_connector->Next->Data == ct)//再看下一项的数据是否符合目标
			{
				temp = Pre_connector->Next;
				Pre_connector->Next = Pre_connector->Next->Next;//准备转移指针

				free(temp);
				return true;//表示成功
			}
			else
			{
				Pre_connector = Pre_connector->Next;//那就下一项
			}
		}

		return false;
		
		
	}
}







int main()
{
	HANDLE AK = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(AK, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN);

	struct LLst* sv_head = NULL;
	int in = 0, data = 0;
	bool puter = TRUE;

	while (1)
	{
		system("cls");
		printf("///////////////////////////////////////////////////////////////////////////\n");

		printf("\ninput 0(exit)/1(front_in)/2(Rear_in)/3(delete),and data\n>:");

		scanf("%d", &in);
		if (in == 0 || in >3)
		{
			printf("exiting...");
			Sleep(400);
			break;
		}
		scanf("%d", &data);
		switch (in)
		{
		case 1:
			Front_In(data);
			break;
		case 2:
			Rear_In(data);
			break;
		case 3:
			puter = del_aimdata(data);
			if (!puter)
			{
				printf("Failed to delete the number!\n");
			}
			break;
		}
		printf("\n///////////////////////////////////////////////////////////////////////////\n");
		printf("Linklist view draw\n");
		sv_head = head;
		while (1)
		{
			if (sv_head == NULL)
			{
				printf("NULL\n");
				break;
			}
			printf("%d -> ", sv_head->Data);
			if (sv_head->Next == NULL)
			{
				printf("NULL\n");
				break;
			}
			else
			{
				sv_head = sv_head->Next;
			}
		}
		printf("input any key to continue...");
		while (1)
		{
			if (_getch() != '\n'/*&& _getch() != ' '*/)
			{
				break;
			}

		}

	}
	return 0;
}
