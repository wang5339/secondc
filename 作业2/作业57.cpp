#include <stdio.h> 
int main(){
	int a[10][10] = {0};
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		int m = 0;
		for (m = 0; m < 10 - i; m++)
			printf("  ");
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			if ((j == 0) || (i == j))
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
