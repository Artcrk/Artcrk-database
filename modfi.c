#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int ar[] = { 4,5,6,7,8,9,14,15,16,17,18,19,20,21,22 };
    //����һ��δ֪��Ŀ������,������С��������.
    int k;
    int size = sizeof(ar) / sizeof(ar[0]);
    int left = 0;
    int right = size - 1;

    printf("please input the number what you want find.\n");
    scanf("%d", &k);
    for (;;)
    {
        int mid = (left + right) / 2;
        //Ѱ����ֵ,����������.

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
            printf("�ڵ�%dλ,�ҵ���%d.", mid + 1, k);
            break;//��������ѭ��.
        }
    }

    return 0;
}