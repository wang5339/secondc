#include<stdio.h>
#include<stdlib.h>
int han(int a){
	if(a==1){
		return 0;
	}
	 for(int i=2;i<a;i++){
	 	if(a%i==0){
	 		return 0;
		 }
	 }
	 return 1;
}
int main(){
	for(int i=1;i<=100;i++){
		if(han(i)==1){
			printf("%d\n",i);
		}
	}
	return 0;
} 
