#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int l,m;
	int fukingtree[10001] = { 0 };
	int st,fin;
	int sum = 0;
	scanf("%d", &l);
	scanf("%d", &m);
	l + 1;
	for (int i = 0; i <= l; i++) {
		fukingtree[i] = 1;
	}
	while(m > 0){
		scanf("%d", &st);
		scanf("%d", &fin);
		for (st; st <= fin; st++) {
			fukingtree[st] = 0;
		}
		m--;
	}
	for (int r = 0; r <= l; r++) {
		if (fukingtree[r] == 1) {
			sum += fukingtree[r];
		}
	}
	printf("%d", sum);
	return 0;
}