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
	printf("�������ַ�����");
	gets(a);
	int l = len(a);
	printf("�ַ����ĳ���Ϊ��%d\n", l);
	return 0;
}

