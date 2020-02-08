#include <stdio.h>
#include <string.h>
int main(){
	int  i, j, k;
	int count = 0;
	char str1[100], str2[100];
	printf("ÇëÊäÈëÄ¸×Ö·û´®£º");
	gets(str1);
	printf("ÇëÊäÈë×Ó×Ö·û´®£º"); 
	gets(str2);
	for (i = 0; i <= strlen(str1) - strlen(str2); i++)
	{
		for (j = 0, k = i; j < strlen(str2) && str2[j] == str1[k]; j++, k++);
			if (j == strlen(str2))
				count++;
	}
	printf("%d\n", count);
	return 0;
} 
