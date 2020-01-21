#include <stdio.h>
int main()
{
	int a[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	int a2[3][3] = {
		{9, 8, 7},
		{6, 5, 4},
		{3, 2, 1}
	};
	int b[3][3] = {0};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
	{
		b[i][j] = a[i][j] + a2[i][j];
			printf("%3d", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
