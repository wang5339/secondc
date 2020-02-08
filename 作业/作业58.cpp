#include <stdio.h>
int f(char *s1, char *s2)
{
	int i, j, flag = -1;
	for (i = 0, j = 0; s1[i]; i++)
	{
		while (s1[i] == s2[j] && s1[i] && s2[j])
		{
			i++;
			j++;
			if (!s2[j])
			{
				flag = i - j;
				return flag;
			}
		}
		j = 0;
	}
	return flag;
}
int main(){
	int flag;
	char s1[100], s2[100];
	scanf("%s", s1);
	scanf("%s", s2);
	flag = f(s1, s2);
	if (flag != -1)
		printf("%d\n", flag);
	else
		printf("Not found\n");
	return 0;
}

