#include <stdio.h>
#define N 100
void fun(int *arr, int len)
{
	int flag = 0;
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			if (arr[i] == arr[j])
			{
				flag = 1;
				break;
			}
	if (flag == 0)
		printf("false\n");
	else
		printf("true\n");
}
int main(){
	int arr1[5] = {1, 2, 3, 4, 1};
	int arr2[5] = {1, 1, 2, 3, 4};
	int arr3[10] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
	printf("����1�Ľ��Ϊ��");
	fun(arr1, 5);
	printf("����2�Ľ��Ϊ��");
	fun(arr2, 5);
	printf("����3�Ľ��Ϊ��");
	fun(arr3, 10);
	return 0;
}

