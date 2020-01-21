#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[1000];
	a[1] = 1;
	a[2] = 1;
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	printf("%d", a[n]);
	return 0;
}
