#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>//相当于stdio.h
#include <iostream>//据说包含了Cpp内部的所有基本函数
#include <algorithm>

int w[105], value[105];
int DP[1005] = { 0 };

int main()
{
    int t, m = -1;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &w[i], &value[i]);
    }
    for (int i = 1; i <= m; i++)//设置为1不仅是为了更直观看到编号,而且为后来的调用DP[0][j]作了铺垫.
    {
        for (int j = t; j >= 0; j--)//在i的循环中,i-1的循环至关重要!!!,只要可以
            
        {
            if (j >= w[i])
            {
                DP[j] = std::max(DP[j - w[i]] + value[i], DP[j]);

            }

        }
        //因为每一次向后选取的DP总是在前一次选择的最大value值
        //所以在新选的过程中,只要考虑必选新元素或者必不选新元素,然后再返回去调用值.
        //而由于j遍历t的存在,可以保证每一个可能取到的前置j值在取到之前就已经完成了初始化.
    }
    printf("%d", DP[m][t]);//最后的条件,i增长为m,j停留在等于t的最大值.然后输出.
    return 0;
}
