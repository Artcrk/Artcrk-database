#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>//相当于stdio.h
#include <iostream>//据说包含了Cpp内部的所有基本函数
#include <algorithm>//相当于C++里面的<math.h>

using namespace std;//简化特定函数名

int main()
{
	int art;
	int max = 0;
	int crt;
	std::cin >> art;
	std::cin >> crt;
	max = std::max(art, crt);//找出几个值的较大值.来自algorithm函数.
	std::cout << max;

	return 0;
}
