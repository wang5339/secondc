#include <stdio.h>
int main()
{
	int s = 0, i = 1;
	while (i <= 100)
	{
		s += i;
		i++;
	}
	printf("%d\n", s);
	return 0;
}
