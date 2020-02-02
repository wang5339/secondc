#include<stdio.h>
#include<stdlib.h>
int main() {
	int n, y, r,a=0; 
	int b[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
	printf("请输入年：");
	scanf("%d", &n);
	printf("请输入月：");
	scanf("%d",&y);
	printf("请输入日：");
	scanf("%d",&r);
	if ((n%4==0&&n%100!=0)||(n%400==0) ){
		a = 1;
	}
	else {
		a = 0;
	}
	int s = 0;
	if (a == 1) {
		if (y > 2) {
			s = b[y] + 1 + r;
		}
		else {
			s = b[y] + r;
		}
	}
	else {
		s = b[y] + r;
	}
	printf("%d",s);
	return 0;
}
