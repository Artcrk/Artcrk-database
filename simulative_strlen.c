#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

size_t my_strlen(const char* str)
{
	size_t r = 0;
	while (*str++ != '\0')
	{
		r++;
	}
	return r;
}

int main()
{
	char arr2[] = "Hello World!";
	printf("%zu", my_strlen(arr2));
	return 0;
}
