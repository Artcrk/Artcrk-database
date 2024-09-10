#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <limits.h>
int main() {
    int all;
    int xss[200000] = { 0 };
    int sum;
    int Max = INT_MIN;
    scanf("%d", &all);
    for (int i = 0; i < all; i++) {
        scanf("%d", &xss[i]);
    }
    for (int n = 1; n <= all; n++) {
        for (int drit = 0; drit <= all - n; drit++) {
            sum = 0;
            for (int turn = drit; turn < n + drit; turn++) {
                sum += xss[turn];
            }
            Max = (Max > sum) ? Max : sum;
        }
    }
    printf("%d", Max);
    return 0;
}