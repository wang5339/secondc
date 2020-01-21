#include<stdio.h>
#include<stdlib.h>
int main() {
	int n, i, j;
	scanf("%d", &n);
	int a;
	a = n;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= a - 1; j++) {
				printf(" ");
			}
			--a;
			for (j = 1; j <= i * 2 - 1; j++) {
				printf("*");
			}
			printf("\n");
		}
		a = n;
		for (i = 1; i < n; i++) {
			for (j = 1; j <= i; j++) {
				printf(" ");
			}
			for (j = 1; j <= (a - i) * 2 - 1; j++) {
				printf("*");
			}
			printf("\n");
		}
	return 0;
}
