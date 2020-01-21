#include<stdio.h>
#include<stdlib.h>
int main(){
	long long int i,s=0,k=1;
	for(i=1;i<=20;i++){
		k=k*i;
		s=s+k;
	}
	printf("%lld",s);
	return 0;
}
