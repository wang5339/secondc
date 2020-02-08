#include <stdio.h>
int main(){
	int num, a, b, c, d, t;
	printf("四位数字：");
	scanf("%d", &num);
	a = num / 1000;
	b = num % 1000 / 100;
	c = num % 100 / 10;
	d = num % 10;
	a = (a + 5) % 10;
	b = (b + 5) % 10;
	c = (c + 5) % 10;
	d = (d + 5) % 10;
	t = d;
	d = a;
	a = t;
	t = c;
	c = b;
	b = t;
	printf("加密后的数字为：%d%d%d%d\n", a, b, c, d);
	return 0;
}
