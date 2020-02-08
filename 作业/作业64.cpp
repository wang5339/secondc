#include<stdio.h>
int main(){
    int i, j = 0, k = 0, n;
    int a[40] = {0};
    printf("请输入有几个人玩游戏:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = 1;                          
    for (i = 1; i < 4; i = i % 3 + 1)       
    {
        if (3 == i && a[j] != 0)
        {
            a[j] = 0;						
            k++;
            if (n - 1 == k)
            	break;
            j = (j + 1) % n;
            continue;
        }
        if (a[j] == 0)
        {
            j = (j + 1) % n;
            i--;
            continue; 
        }
        j = (j + 1) % n;
    }        
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
        printf("%d\n", i + 1);
    }
} 
