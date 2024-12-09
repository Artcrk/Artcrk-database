#include <stdio.h>
#include <stdlib.h>

struct vio
{
	struct vio* just;
	int data;
	struct vio* next;
}V;

typedef struct vio ST;
ST* head = NULL, *last = NULL;

void Rearin(int n)
{
	ST* temp = (ST*)malloc(sizeof(V));
	temp->data = n;
	temp->next = head;
	if (head == NULL)
	{
		head = temp;
		temp->just = temp;
	}
	if (last == NULL)
	{
		last = temp;
	
	}
	if (temp != last)
	{
		temp->just = last;
		last->next = temp;
		last = temp;
	}
}

int cut(ST** ptr)
{
	ST* temp = (ST*)malloc(sizeof(V));
	temp = (*ptr)->next;
	if (*ptr == head && *ptr == last)
	{
		return 1;
	}
	if (*ptr == last)
	{
		last = (*ptr)->just;
	}
	if (*ptr == head)
	{
		head = (*ptr)->next;
	}
	(*ptr)->just->next = (*ptr)->next;
	(*ptr)->next->just = (*ptr)->just;
	*ptr = temp;
	return 0;
}


int main()
{
	int n,i,c = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		Rearin(i);
	}
	ST* Foin = (ST*)malloc(sizeof(V));
	Foin = head;
	while (1)
	{
		for (i = 0; i < 2; i++)
		{
			Foin = Foin->next;
		}
		c = cut(&Foin);
		if (c == 1)
		{
			printf("%d", Foin->data);
			break;
		}
	}


	return 0;
}
