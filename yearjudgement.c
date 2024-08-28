#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int year;
	int four[155] = { 0 };
	scanf("%d", &year);
	year = year - 1580;
	if (year == 20 || year == 420) {
		printf("1");
		return 0;
	}
	for (int c = 1; c <= 155; c++) {
		if (year == 4 * c&&year!=(100*c-80)) {
			printf("1");
			return 0;
		}
	}
	printf("0");
	return 0;
}