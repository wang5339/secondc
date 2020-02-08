#include <stdio.h>
int main(){
	int n, i;
	scanf("%d", &n);
	int a1[10] = {0}, a2[10] = {0};
	for (i = 0; i <= n; i++)
		a1[i] = i;
	for (i = 0; i < n; i++)
		scanf("%d", &a2[i]);
	for (i = 0; i < n; i++)
	{
		if (a1[i] != a2[i])
		{
			printf("%d\n", a1[i]);
			break;
		}
		if (i == n)
			printf("%d\n", a1[i + 1]);
	}
	return 0;
}
