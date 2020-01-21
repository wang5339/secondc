#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char c;
	int y=0,k=0,s=0,f=0;
	while((c=getchar())!="\n"){
		if(0<=a[i]<=9){
			s++;
		}else if((("a"<=a[i])&&(a[i]<="z"))||(("A"<=a[i])&&(a[i]<="Z"))){
			z++;
		}else if(a[i]==" "){
			k++;
		}else{
			f++;
		}
	}
	printf("Êý×Ö:%d\n×ÖÄ¸:%d\n¿Õ¸ñ:%d\n×Ö·û:%d",s,z,k,f);
	return 0;
} 

