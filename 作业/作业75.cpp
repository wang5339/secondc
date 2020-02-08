#include <stdio.h>
#include <string.h>
int f(char *s)
{
	int t[26] = {0};
	int i;
	int len = strlen(s);
	for (i = 0; i < len; i++)
		t[s[i] - 'a']++;
	for (i = 0; i < len; i++)
		if (t  [s[i] - 'a'] == 1)
			return i;
	return -1;
}
int main() {
	char s[100];
	scanf("%s", s);
	printf("%d\n", f(s));
	return 0;
}


