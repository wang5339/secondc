#include<stdio.h>
#include<stdlib.h>
int han(int a){
	int i,j,k;
	i=a%100%10;
	j=a/100;
	k=a/10%10;
	if(i*i*i+j*j*j+k*k*k==a){
		return 1;
	}
	return 0;
}
int main(){
	for(int d=100;d<=999;d++){
		if(han(d)==1){
			printf("%d\n",d);
		}
	}
	return 0;
}   
