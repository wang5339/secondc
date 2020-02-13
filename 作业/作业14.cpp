#include<stdio.h>
#include<stdlib.h>
int main(){
int i ,j;
for(i=101;i<=200;i++){
	for (j=2;j<i;j++){
		if(i%j==0){
			break;
		}else if(j==i-1){
			printf("%d\n",i);
		}
	}
	
}
	return 0;
}

