#include <stdio.h>
int main()
{
	int n;
	for (int i = 0; i < 7; i++)
	{
		printf("������һ��1-50֮������֣�");
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
