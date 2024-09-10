#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int ar[] = { 4,5,6,7,8,9,14,15,16,17,18,19,20,21,22 };
    //创建一个未知数目的数组,但按大小依次排序.
    int k;
    int size = sizeof(ar) / sizeof(ar[0]);
    int left = 0;
    int right = size - 1;

    printf("please input the number what you want find.\n");
    scanf("%d", &k);
    for (;;)
    {
        int mid = (left + right) / 2;
        //寻找中值,拟四舍五入.

        if (k > ar[mid])
        {
            left = mid + 1;
        }
        else if (k < ar[mid])
        {
            right = mid - 1;
        }
        else
        {
            printf("在第%d位,找到了%d.", mid + 1, k);
            break;//打破无限循环.
        }
    }

    return 0;
}