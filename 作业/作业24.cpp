#include<stdio.h>
#include<stdlib.h>
int main(){
	float h=100,s=0;
	int i;
	for (i=0;i<10;i++){
		s=s+h;
		h=h/2;
		if(i!=9){
			s=s+h;
		}
	}
	printf("%f\n",h);
	printf("%f",s);
	return 0;
}
