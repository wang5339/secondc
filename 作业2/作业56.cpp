#include <stdio.h>
#include<string.h>
#include<stdlib.h> 
#define N 128
int stringLength(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
int main()
{
	char string[N] = {0}
	gets(string);
	printf("%d\n", stringLength(string));
	return 0;
} 

