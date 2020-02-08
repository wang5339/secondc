#include <stdio.h>

int main(void)
{
	long x;
	int a, b, c, d, e;
	scanf("%ld", &x);
	a = x / 10000;
	b = x % 10000 / 1000;
	c = x % 1000 / 100;
	d = x % 100 / 10;
	e = x % 10;
	if (a != 0)
		printf("5！！！！%d%d%d%d%d\n", e, d, c, b, a);
	else if (b != 0)
		printf("4！！！！%d%d%d%d\n", e, d, c, b);
	else if (c != 0)
		printf("3！！！！%d%d%d\n", e, d, c);
	else if (d != 0)
		printf("2！！！！%d%d\n", e, d);
	else
		printf("1！！！！%d\n", e);
	return 0;
}
