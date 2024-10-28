#include <stdio.h>
#include <graphics.h>
#include <windows.h>
#include <conio.h>

int main()
{
  //此处省略了画布初始化的步骤,直接展示了掩码的转换核心代码,处理过程与二维数组处理办法一致
  	for (int y0 = y; y0 < y + 256/*y轴最大宽度*/; y0++)
	{
		for (int x0 = x; x0 < x + 192/*x轴最大宽度*/; x0++)
		{
			COLORREF color = getpixel(x0, y0);

			if (color == RGB(0, 0, 238))
			{ // 检查颜色是否为#0000EE,这个是预先设定好的不涉及颜色(bkcolor),已经知道它的RGB代码
				putpixel(x0, y0, BLACK); // 设置掩码为黑色（透明）
			}
			else
			{
				putpixel(x0, y0, RGB(255,255,255)); // 设置掩码为白色（不透明）
			}
		}
	}
	while (1);
	return 0;
}
