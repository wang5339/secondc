#include<stdio.h>
#include <stdlib.h>
int main() {
	int n,c,d,i;
	scanf("%d", &n);
	int a[1000], b[1000], x[1000], y[1000];
	for ( i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &x[i], &y[i]);
	}
	scanf("%d %d", &c, &d);
	for (i = n; i >= 1; i--) {
		if ((a[i] <= c <= a[i] + x[i]) && (b[i] <= d <= b[i] + y[i])) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
