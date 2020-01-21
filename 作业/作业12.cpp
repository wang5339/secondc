#include<stdio.h>
#include<stdlib.h>
int han(int a){
	int k=1;
	while(k<=a){
		k=k*3;
		if (k==a){
			return 1;
		}
	}
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);	
	if(han(n)==1){
		printf("ÊÇ");
	}else{
		printf("²»ÊÇ");
	}
}
