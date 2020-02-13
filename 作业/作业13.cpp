#include<stdio.h>
#include<stdlib.h>
int fun(int n){
	if (n == 1 || n == 2){
        return 1;
	}else{
		return fun(n - 1) + fun(n - 2);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fun(n)*2);
	return 0;
}

