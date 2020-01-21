#include<stdio.h>
#include<stdlib.h>
int main() {
	int i;
	float b, s=0, a[25];
	a[1] = 1;
	a[2] = 2;
	for (i = 3; i <= 23; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	for (i = 1; i <= 20; i++) {
		b = a[i + 1] / a[i];
		s = s + b;
	}
	printf("%f", s);
	return 0;
}

