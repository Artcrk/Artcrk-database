#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcpy(char* dest,const char* src)
{
	char* Kn = dest;
	assert(dest != NULL && src != NULL);
	while (*dest++ = *src++);
	return Kn;
}

int main()
{
	char arr1[20] = "xxxxxxxxxx";
	char arr2[] = "hello";
	printf("%s", my_strcpy(arr1, arr2));
	return 0;
}
