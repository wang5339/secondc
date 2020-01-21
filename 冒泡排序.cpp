#include<stdio.h>
void fun(){
	int a[10],i; 
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	int j,k;
	for(i=0;i<9;i++)
	{
		for(j=0;j<10-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
			k=a[j];
			a[j]=a[j+1];
			a[j+1]=k;
			}
		}
	}
	for(i=0;i<10;i++)
	{
	printf("%d   ",a[i]);
	}
}
int main(){
	fun();
	return 0;
}
