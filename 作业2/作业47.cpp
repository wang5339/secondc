#include <stdio.h>
int main(){
	int num, s;
	scanf("%d", &num);
	s = num * num;
	printf("%d\n", s);
	do
	{
		scanf("%d", &num);
		s = num * num;
		printf("%d\n", s);
	} while (s >= 50);
	return 0;
}
