#include <stdio.h>
int main()
{
	int arr1[10], arr2[10];
	int i, j, k;
	j = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &arr1[i]);
	scanf("%d", &k);
	for (i = 10 - k; i < 10; i++)
	{
		arr2[j] = arr1[i];
		j++;
	}
	for (i = 0; i < 10 - k; i++)
	{
		arr2[j] = arr1[i];
		j++;
	}
	for (j = 0; j < 10; j++)
		printf("%d ", arr2[j]);
	return 0;
}
