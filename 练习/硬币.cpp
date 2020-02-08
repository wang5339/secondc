#include<stdio.h>
#include<stdlib.h>
int main(){
	int i=100,j,k,n;
	for(j=0;j<=100;j++)
	{
		for(k=0;k<=50;k++)
		{
			for(n=0;n<=20;n++)
			{
				if(j*1+k*2+n*5==100&&j+k+n==50)
				{
					printf("%d*1+%d*2+%d*5=100\n",j,k,n);
				}
			}
		}
	}
	return 0;
} 
