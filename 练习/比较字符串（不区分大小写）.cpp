#include <string.h>
#include<stdio.h>
char a[300],b[30];
int  fun(int d,int e,int f){
	int j;
	for(j=0;j<f;j++){
		for(;d<e;){
			if(b[j]==a[d]){
				d++;
				break;
			}else {
				f=j;
				return f;}
		}
	}
	return f-1;
}
int main(){
	gets(a);
	int i,n;
	for(i=0;i<300;i++){
		if(a[i]==' '){
			break;
		}	
	}
	for(n=0;n<i;n++){
		b[n]=a[n];
	}
	n--;
	int s=0;
	i++;
	for(;i<300;i++){
		if(a[i]==' '||a[i]=='\0'){
			n=fun(i-s,i,n);
			s=0;
			i++;
		}else{
			s++;
		}
	}
	for(i=0;i<=n;i++){
		printf("%c",b[i]);
	}
	return 0;
}
