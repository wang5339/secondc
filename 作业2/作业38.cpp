#include <stdio.h>
int main(){
	int a[5] = {1, 2, 3, 4, 5};
	int i;
	while (i < 4)
	{
		printf("%d, ", a[i]);
		i++;
	}
	printf("%d\n", a[i]);
	return 0;
}
