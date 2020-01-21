#include<stdio.h>
#include<stdlib.h>
int main(){
	int x;
	scanf("%d",&x);
	if (x>=90){
		printf("A");
	}else if(x>=60){
		printf("B");
	}else {
		printf("C");
	}
	return 0;
} 
