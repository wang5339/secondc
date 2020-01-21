#include<stdio.h>
#include<stdlib.h>
int main(){
	int s=0,a,d;
	printf("请输入几个数相加:");
	scanf("%d",&d);
	printf("\n请输入相加的数字:");
	scanf("%d",&a);
	int b;
	b=a;
	for(int i=0;i<d;i++){
		s=s+a;
		a=a*10+b;
	}
	printf("%d",s);
	return 0;
} 
