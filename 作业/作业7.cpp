#include <stdio.h>
int main() {
	int a[5] = {1, 2, 3, 4, 5};
	int b[5];
	int i;
	printf("原数组为：");
	for (i = 0; i < 5; i++)
	{
		printf("%-2d", a[i]);
		b[i] = a[i];
	}
	printf("\n复制后的数组为：");
	for (i = 0; i < 5; i++)
		printf("%-2d", b[i]);
	printf("\n");
	return 0;
}

