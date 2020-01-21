#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[200],b[200]={0};
int  num(int g,int f,int q){
	q++;
	for(int d=0;d<g;d++){
		for(;q<=f;){
			if(b[d]==a[q]){
				q++;
				break;
			}else{
				return d;
			}
		}
	}
}
int main(){
	int i,c,p,j;
	gets(a);
	int r=strlen(a);
	for(i=0;a[i]!=' ';i++);
	for(j=0;j<i;j++){
		b[j]=a[j];
	}
	c=i;
	p=i;
	i++;
	for(;i<=r;i++){
		if(a[i]==' '||i==r){
			c=num(c,i,p);
			p=i;	
		}
	}
	if(c==0){
		printf("*");
	}
	for(i=0;i<c;i++){
		printf("%c",b[i]);
	}

}
