#include <stdio.h>
void s(char str1[], char str2[])
{
    int i, j;
    for (i = 0; str1[i] != '\0'; i++);
    for (j = 0; str2[j] != '\0'; i++, j++)
        str1[i] = str2[j];
    str1[i] = '\0';
}
int main()
{
    char stri1[40], stri2[40];
    scanf("%s", stri1);
    scanf("%s", stri2);
    s(stri1, stri2);
    printf("%s", stri1);
    return 0;
}


