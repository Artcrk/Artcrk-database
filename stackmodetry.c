#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int a[15] = { 0 };
    int* p = &a[0];
    int* ap = &a[15];
    printf("%d\n", (int)(ap - p));
    int i = 0;

    for (i = 0; i < 15; i++)
    {
        *p++ = i + 1;
        printf("a[%d] = %d\n",i, a[i]);
    }
    for (; i > 0; i--)
    {
        *(--p) = -i;
        printf("ppa[%d] = %d\n", i-1, *p);
    }
    return 0;
} 
