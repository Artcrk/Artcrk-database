#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
long long abc[10005][3] = { 0 };//存放a,b,c的数组.
//因为最大组数为10000,每组三个元素,这里稍稍把范围弄大一点,防止一些错误
//以及,定义在全局,也是为了把栈内存转移到数据段里,防止栈溢出.

void downloaddata(long long* a, long long* b, long long* c)//下载数据,使用了地址传参的办法,看似牛逼其实麻烦,但是在某种意义上可能挺方便的?
{
    scanf("%lld%lld%lld", a, b, c);//long long整型需要lld来输出和接收
}

void Hus(long long* up, long long* dw)//Hus互素,就是求最大公约数并进行约分的,注意,若没有最大公约数,最大公约数就会是1
//当最大公约数是1时,说明不需要约分,这个时候
{
    long long uup = *up;//因为交互值会变化,为了保证输出值的值与原始一致,所以把两值分开了
    long long ddw = *dw;
    int sxs = uup % ddw;//sxs是二者求余的结果
    while (sxs)//求余结果为0说明被整除,同时也有可能是数据被1整除,这种时候相当于这种公式的保护机制.这个时候最大公约数就是1,而不会是*dw.
        //之前以为无法约分,ddw就还是*dw? 大错特错!!ddw已经变成1了,不然怎么跳出循环?!
    {
        uup = ddw;//第一被除数除数=第二除数
        ddw = sxs;//第二除数=前一次求余结果
        sxs = uup % ddw;//再次求余.
    }
    *up /= ddw;//一起约分,注意,当无法约分时,ddw也是1,不会造成错误!!
    *dw /= ddw;
    return;//退出,这里是学的尹俊杰的反回空值.
}

void putdata(long long up, long long dw)
{
    long long dc = (long long)-1;//保险一点,免得隐式整型替换导致数据不对!
    int sa = 0;//用于判断最终的符号,就是统计有几个-1.
    if (up < 0)//以下这一串都是,如果是负数,就乘以一个long long的-1,然后-1个数加一.
    {
        up *= dc;
        sa++;
    }
    if (dw < 0)
    {
        dw *= dc;
        sa++;
    }
    if (sa == 2)
    {
        sa = 0;
    }

    Hus(&up, &dw);//开始约分.
    if (sa == 1)//当sa为1时,说明有一个-1,因为分数要把-表示在分子,所以把分子变成相反数.
    {
        up *= dc;
    }
    if (dw != 1)//看分母,如果是1,就约掉.只输出整数.否则就输出分数形式.
    {
        printf("%lld/%lld\n", up, dw);
    }
    else
    {
        printf("%lld\n", up);
        return;//打印完成,退出
    }

}

int main()
{
    int Ts = 0;
    scanf("%d", &Ts);//总组数
    long long a = 0, b = 0, c = 0;//这是第一次的错误,然后变成了后来的接口,用于暂时存储对应组的a,b,c

    long long uper, downer;//分子,分母
    int i = 0;
    for (; i < Ts; i++)//花里胡哨的接收数据的方法,用了直接传地址的方式保证函数内的改动可以影响到为外部实参.
    {
        downloaddata(&abc[i][0], &abc[i][1], &abc[i][2]);//但是在abc转移到全局后,这么做变成了多余的,但是懒得改了,毕竟这种写法两种都能用
    }
    for (i = 0; i < Ts; i++)
    {
        a = abc[i][0];//表示在对应组的第几位,和输入的格式一致,方便下面uper和downer的书写,其实也是为了和之前写的a,b,c对接,懒得大改了.
        b = abc[i][1];
        c = abc[i][2];
        uper = (b * c * c) + (a * a * c) - (b * b * a);//分子
        downer = a * b * c;//分母
        putdata(uper, downer);//传参.
    }
    return 0;
}
