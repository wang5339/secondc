#include <stdio.h>
#include <string.h>
int main(){
	char s1[100], s2[100];
	scanf("%s", s1);
	scanf("%s", s2);
	const int x = strlen(s1), y = strlen(s2);
	int d[x][y];
	int i, j, maxLen = 0;
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			d[i][j] = 0;
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
					d   [i][j] = 1;
				else
				{
					d[i][j] = d[i - 1][j - 1] + 1;
					if (d[i][j] > maxLen)
						maxLen = d[i][j];
				}
			}
			else
				d[i][j] == 0;
		}	
	printf("%d\n", maxLen);
	return 0;
}
