#include<stdio.h>
#include<stdlib.h>
int han(int s){
	int a=0;
	while(s){
		if (s%2==1){
			a++;
		}
		s=s/2;
	}
	return a;
}
int main(){
	int n;
	scanf("%d",&n);
	int k;
	k=han(n);
	printf("%d",k);
	return 0;
} 
