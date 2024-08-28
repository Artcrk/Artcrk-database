#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
double math (double x, double y,int z)
{
	double v = 0;
	v = x * y * z;
	return v;
}
int main() {
	double crit = 0;
	double CD = 0;
	int attack = 2000;
	printf("please write down your crit rate and crit damage.\n");
	scanf("%lf %lf", &crit, &CD);
	double avgdamage = math (crit, CD, attack);
	printf("Your average damage is %.2lf", avgdamage);
	return 0;
}