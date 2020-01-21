#include <stdio.h>
int len(char *str)
{
	int l = 0;
	for (; *str != '\0'; str++)
		l++;
	return l;
}
int main()
{
	char a[100] = {0};
	printf("请输入字符串：");
	gets(a);
	int l = len(a);
	printf("字符串的长度为：%d\n", l);
	return 0;
}

