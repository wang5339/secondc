#include <stdio.h>

int main(){
    int a=0;  // 素数的个数
    int num=0;  // 输入的整数

    printf("输入一个整数：");
    scanf("%d",&num);

    for(int i=2;i<num;i++){
        if(num%i==0){
            a++;  // 素数个数加1
        }
    }

    if(a==0){
        printf("%d是素数。\n", num);
    }else{
        printf("%d不是素数。\n", num);
    }

    return 0;
}
