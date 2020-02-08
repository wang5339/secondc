#include <stdio.h>
void fun(int n)
{
	char next;
	if (n <= 1)
	{
		next = getchar();
		putchar(next);
	}
	else
	{
		next = getchar();
		fun(n-1);
		putchar(next);
	}
}
int main(){
	fun(5);
	printf("\n");
	return 0;
}
