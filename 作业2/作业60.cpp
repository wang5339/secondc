#include <stdio.h>
long a(long x)
{
	long long int  ret = 0;
	while (x != 0)
	{
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	if ((long int )ret != ret)
		return 0;
	return (long int )ret;
}
int main()
{
	long int num;
	scanf("%ld", &num);
	printf("%ld\n", a(num));
	return 0;
}

