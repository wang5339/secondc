#include<stdio.h>
#include<stdlib.h>
int su(int a){
	int j;
	for (j=2;j<a;j++){
		if(a%j==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int x,i;
	scanf("%d",&x);
	printf("%d=",x);
	if(su(x)){
		printf("%d",x);
	}
	else{
		while(x!=1){
			for (i=2;i<=x;i++){
				if(su(i)&&x%i==0){
					printf("%d",i);
					if(i!=x){
						printf("*");
					}
					x=x/i;
					i=1;
				}
			}
		}
	}
	return 0;
}
