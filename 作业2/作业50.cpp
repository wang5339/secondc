#include <stdio.h>
int main()
{
	int arr1[1000], arr2[1000];
	scanf("%d",)
	int i, j, k;
	j = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &arr1[i]);
	scanf("%d", &k);
	if(k>10){
		for(i=0;i<10;i++){
			arr2[j+i]=arr1[i];
		}
	}else{
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
	}
	for (j = 0; j < 10; j++)
		printf("%d ", arr2[j]);
	return 0;
}

