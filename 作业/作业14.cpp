#include<stdio.h>
#include<stdlib.h>
int han(int a){
	int i;
	for (i=2;i<a;i++){
		if (a%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int j; 
	for (j=101;j<=200;j++){
		if(han(j)==1){
			printf("%d\n",j);
		}
	}
	return 0;
} 
