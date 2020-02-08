#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *str1,char *str2)
{
    char temp[20];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
int main(){
    char s1[20], s2[20], s3[20];
    printf("请输入3个字符串：\n");
    fgets(s1, (sizeof s1 / sizeof s1[0]), stdin);
    fgets(s2, (sizeof s2 / sizeof s2[0]), stdin);
    fgets(s3, (sizeof s3 / sizeof s3[0]), stdin);
    if (strcmp(s1, s2) > 0)
		swap(s1, s2);
    if (strcmp(s2, s3) > 0)
		swap(s2, s3);
    if (strcmp(s1, s2) > 0)
		swap(s1, s2);
    printf("排序后的结果为：\n");
    printf("%s  %s  %s\n", s1, s2, s3);
    return 0;
}

