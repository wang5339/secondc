#include <stdio.h>
int main() {
	int a[5] = {1, 2, 3, 4, 5};
	int b[5];
	int i;
	printf("ԭ����Ϊ��");
	for (i = 0; i < 5; i++)
	{
		printf("%-2d", a[i]);
		b[i] = a[i];
	}
	printf("\n���ƺ������Ϊ��");
	for (i = 0; i < 5; i++)
		printf("%-2d", b[i]);
	printf("\n");
	return 0;
}

